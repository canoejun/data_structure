//
//  HTNTree.c
//  赫夫曼树的创建及赫夫曼编码
//
//  Created by 张俊 on 2018/11/20.
//  Copyright © 2018年 zhangjun. All rights reserved.
//

#include "HTNTree.h"
#include <stdlib.h>
#include <string.h>


void printTree(HuffmanTree * tree,int length){
    for (int i = 0; i < length; i++,tree++) {
        printf("%c %2d %d %d %d\n",tree->symbol,tree->weight,tree->parent,tree->lchild,tree->rchild);
    }
}

//判断链表里面是否存在相应的符号
int isExistInSymbolLink(SymbolLink * L,char element){
    SymbolLink * p = L->next;
    while (p) {
        if (element == p->symbol) {
            p->weight++;
            return 1;
        }
        p = p->next;
    }
    return 0;
}

//挑选出来最小的两个结点
void selectTwoMin(HuffmanTree * HT,int length, int * m1,int* m2){
    int minWeigth = 999999,secondMinWeight = 999999;
    int minWeigthIndex = 0,secondMinWeightIndex = 0;
    for (int i = 0; i < length; i++) {
//        parent不为0
        if ((HT+i)->parent == 0) {
//            找寻最小的两个数值的下标
            if ((HT+i)->weight < minWeigth) {
                secondMinWeight = minWeigth;
                minWeigthIndex = i;
                minWeigth = (HT+i)->weight;
            }else if(secondMinWeight >= (HT+i)->weight && (secondMinWeight != minWeigthIndex)){
                secondMinWeightIndex = i;
                secondMinWeight = (HT+i)->weight;
            }
        }
    }
    *m1 = minWeigthIndex;*m2 = secondMinWeightIndex;
//    printf("%d %d %d %d\n-------\n",minWeigth,minWeigthIndex,secondMinWeight,secondMinWeightIndex);
}

//赫夫曼树的创建
void HuffmanCreat(HuffmanTree ** HT,FILE * fp,int *count){
//    首先用链表记录出现的符号统计存在多少个
    int n = 0;
    SymbolLink * L = (SymbolLink *)malloc(sizeof(SymbolLink));
    if (!L) {
        EXIT_FAILURE;
    }
    L->next = NULL;
    SymbolLink * p = L;
    char tempElement;
    while((tempElement = fgetc(fp)) != EOF) {
//        如果不存在 重新创建一个结点进行存储 存在该位置的频率加一
        if (!isExistInSymbolLink(L, tempElement)) {
            n++;
            SymbolLink * q = (SymbolLink *)malloc(sizeof(SymbolLink));
            if (!q) {
                EXIT_FAILURE;
            }
            q->symbol = tempElement;  q->weight = 1;
            p->next = q; p = q;
            p->next = NULL;
        }
    }
    *count = n;
//    创建动态数组进行赫夫曼树的建立
    int m = 2 * n - 1;
    *HT = (HuffmanTree *)malloc(sizeof(HuffmanTree) * m);
    if (!HT) {
        EXIT_FAILURE;
    }
//    将新申请的数组进行赋值
    p = L->next;
    int i = 0;
//    前面的统计出来的放在数组中
    while (p) {
        (*HT+i)->symbol = p->symbol;(*HT+i)->weight = p->weight;(*HT+i)->L = (SymbolLink *)malloc(sizeof(SymbolLink));
        if (!(*HT+i)->L) {
            EXIT_FAILURE;
        }
        
        
        
        
//        ??????
//        L->next = NULL;
        
        
        
        
        
        
        
        (*HT+i)->parent = 0;(*HT+i)->lchild = 0;(*HT+i)->rchild = 0;
        i++;p = p->next;
    }
//    将统计出来的后面的重置为空
    for (; i < m; i++) {
        (*HT+i)->symbol = '#';(*HT+i)->weight = 0;
        (*HT+i)->parent = 0;(*HT+i)->lchild = 0;(*HT+i)->rchild = 0;
    }
    
//    将树打印出来
    printTree(*HT, m);
    
//  赫夫曼树的创建
    int m1 = 0,m2 = 0;
    for (i = n; i < m; i++) {
//        把最小的两个值的索引返回回来
        selectTwoMin(*HT, i, &m1, &m2);
        (*HT+m1)->parent = i; (*HT+m2)->parent = i;
        (*HT+i)->lchild = m1; (*HT+i)->rchild = m2;
        (*HT+i)->weight = (*HT+m1)->weight+(*HT+m2)->weight;
        
    }
    printf("---------------\n");
    printTree(*HT, m);
}

//赫夫曼编码
void HuffmanCoding(HuffmanTree * HT,int n){
//    头插法用于存储编码
    for (int i = 0; i < n; i++) {
        int c,f;
        SymbolLink * L = (HT+i)->L;
        L->next = NULL;
        for (c = i,f = (HT+i)->parent; f !=0; c = f,f = (HT+f)->parent) {
            if ((HT+f)->lchild == c) {
                SymbolLink * p = (SymbolLink *)malloc(sizeof(SymbolLink));
                p->symbol = '0';
                p->next = L->next;
                L->next = p;
            }else{
                SymbolLink * p = (SymbolLink *)malloc(sizeof(SymbolLink));
                p->symbol = '1';
                p->next = L->next;
                L->next = p;
            }
        }
    }
//    进行符号的打印
    for (int i = 0; i < n; i++) {
        printf("\n%c:",(HT+i)->symbol);
        SymbolLink * p = (HT+i)->L;
        while (p) {
            printf("%c",p->symbol);
            p = p->next;
        }
    }
}
