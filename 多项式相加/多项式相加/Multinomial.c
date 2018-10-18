 //
//  MultinomialList.c
//  多项式相加
//
//  Created by 张俊 on 2018/10/9.
//  Copyright © 2018年 zhangjun. All rights reserved.
//

#include "Multinomial.h"
#include <stdlib.h>
#include <time.h>

//初始化
MultinomialList * initMultinomialList(void){
    MultinomialList * p = (MultinomialList *)malloc(sizeof(MultinomialList));
    if (!p) {
        EXIT_FAILURE;
    }
    p->next = NULL;
    return  p;
}

//打印多项式
void printMultinomialList(MultinomialList * L){
    MultinomialList * p = L->next;
    while (p) {
        printf("( %f %d )",p->formula.coefficient,p->formula.power);
        p = p->next;
    }
    printf("\n");
}

//创建多项式
void creatMultinomialList(MultinomialList * L,int a){
    srand((unsigned int)time(NULL));
    MultinomialList * q = L;
    for (int i = 0; i < a; i++) {
        MultinomialList * p = (MultinomialList *)malloc(sizeof(MultinomialList));
        if (!p) {
            EXIT_FAILURE;
        }
        p->formula.power = i+1;
        p->formula.coefficient = (float)rand()/RAND_MAX * 10;
        q->next = p;
        q = p;
    }
    q->next = NULL;
    printMultinomialList(L);
}



//比较系数
int compare(int a,int b){
    if (a > b) {
        return 1;
    }else if (a == b){
        return 0;
    }else{
        return -1;
    }
}

//完成多项式的相加
MultinomialList * addMultinomialList(MultinomialList *L1,MultinomialList * L2){
    MultinomialList * p1 = L1->next;
    MultinomialList * p2 = L2->next;
    MultinomialList * L3 = (MultinomialList*)malloc(sizeof(MultinomialList));
    if (!L3) {
        EXIT_FAILURE;
    }
    MultinomialList * p = L3;
    while (p1 && p2) {
        switch (compare(p1->formula.power, p2->formula.power)) {
//                L1比L2的系数小
            case -1:
                p->next = p1;
                p = p1;
                p1 = p1->next;
                break;
            case 0:{
                float sum = p1->formula.coefficient + p2->formula.coefficient;
                if (sum) {
                    p->next = p1;
                    p = p1;
                    p1->formula.coefficient = sum;
                    p1 = p1->next;
                    p2 = p2->next;
                }else{
                    p->next = p1->next;
                    p1 = p1->next;
                    p2 = p2->next;
                }
                break;
            }
            case 1:
                p->next = p2;
                p = p2;
                p2 = p2->next;
                break;
        }
    }
    
    p->next = p1 ? p1:p2;
//    free(L2);
//    free(L1);
    
    return L3;
}
//返回多项式的相数
int lengthOfMultinomialList(MultinomialList *L){
    int length = 0;
    printf("计算长度的函数内%p\n",L);
    MultinomialList * p = L->next;
    while (p) {
        length++;
        p = p->next;
    }
    return length;
}

//计算一项与后面多项式的乘积
MultinomialList * multiplyMultinomial(multinomial a,MultinomialList *b){
    MultinomialList * result = (MultinomialList*)malloc(sizeof(MultinomialList));
    if (!result) {
        EXIT_FAILURE;
    }
    MultinomialList * q = result;
    MultinomialList * p = b->next;
    while (p) {
        MultinomialList * temp = (MultinomialList*)malloc(sizeof(MultinomialList));
        if (!temp) {
            EXIT_FAILURE;
        }
        temp->formula.coefficient = p->formula.coefficient * a.coefficient;
        temp->formula.power = p->formula.power + a.power;
        q->next = temp;
        q = temp;
        p = p->next;
    }
    q->next = NULL;
    return result;
}

//多项式相乘
MultinomialList * multiplyMultinomialList(MultinomialList *L1,MultinomialList * L2){
    int count = 0;
    printf("相乘函数内%p\n",L1);
    
    int length = lengthOfMultinomialList(L1);
    MultinomialList * total[length];
    MultinomialList * p1 = L1->next;
    
    while (p1) {
        MultinomialList * temp = multiplyMultinomial(p1->formula, L2);
        total[count] = temp;
        count++;
        p1 = p1->next;
    }
    
//    将计算出来的多项式进行相加
    for (int i = 0; i < length-1; i++) {
        total[i+1] = addMultinomialList(total[i], total[i+1]);
    }
    printf("多项式的相乘函数返回前：  ");
    printMultinomialList(total[length-1]);
    
    return total[length-1];
    
    
}






