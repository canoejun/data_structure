//
//  NetWorkPrintTask.c
//  栈和队列的应用（算数四则运算和服务器管理网络的打印）
//
//  Created by 张俊 on 2018/10/29.
//  Copyright © 2018年 zhangjun. All rights reserved.
//

#include "NetWorkPrintTask.h"
#include <stdlib.h>


//创建链队
LinkQueue* creatLinkQueue(void){
    LinkQueue * list = (LinkQueue *)malloc(sizeof(LinkQueue));
    if (!list) {
        EXIT_FAILURE;
    }
    list->head = list->rear = (PrintTask *)malloc(sizeof(PrintTask));
    if (!list->head) {
        EXIT_FAILURE;
    }
    list->head->next = NULL;
    
    for (int i = 0; i < 6; i++) {
        PrintTask * p = (PrintTask*)malloc(sizeof(PrintTask));
        if (!p) {
            EXIT_FAILURE;
        }
        p->rank = 1;
        p->isNeedPrint = 0;
        if (i == 2) {
            p->rank = 9;
        }
        p->next = NULL;
        list->rear->next = p;
        list->rear = p;
    }
    
    return list;
}
////入队
//void enLinkQueue(LinkQueue * list,int e,int isNeedPrint){
//    PrintTask * p = (PrintTask *)malloc(sizeof(PrintTask));
//    if (!p) {
//        EXIT_FAILURE;
//    }
//    p->rank = e;
//    p->isNeedPrint = isNeedPrint;
//    p->next = NULL;
//    list->rear->next = p;
//    list->rear = p;
//}
//出队
void deLinkQueue(LinkQueue * list,int *e,int * isNeedPrint){
    if (list->rear == list->head) {
        EXIT_FAILURE;
    }
    PrintTask * p = list->head->next;
    *e = p->rank;
    *isNeedPrint = p->isNeedPrint;
    list->head->next = p->next;
    if (list->rear == p) {
        list->rear = list->head;
    }
    free(p);
}
void printQueue(LinkQueue * list){
    PrintTask * p = list->head->next;
    while (p != list->rear->next) {
        printf("%d ",p->rank);
        p = p->next;
    }
}

//打印主体函数
void printTaskMain(void){
    LinkQueue * q = creatLinkQueue();
    printQueue(q);
    int position = 0;
    printf("\n请输入你想要打印的位置：");
    scanf("%d",&position);
//    改变是否需要打印的值
    searchPosition(q, position);
    
    int count = 0;
    int t;int isNeedPrint = 0;
    while (1) {
        int temp = q->head->next->rank;
        int select = isMaxRank(q, temp);
        if (select) {
            deLinkQueue(q, &t,&isNeedPrint);
            count++;
            if (isNeedPrint) {
                printf("%d min",count);
                break;
            }
        }else{
            q->rear->next = q->head->next;      //尾指针将移向队尾的首元素串接起来
            q->rear = q->rear->next;                //并更新rear指针指向
            q->head->next = q->head->next->next;    //再更新head指针的next指向
            q->rear->next = NULL;        //尾指针的next置为NULL
            printQueue(q);printf("\n");
        }
    }
}
//找到位置，并改变相应的是否需要打印的值
void searchPosition(LinkQueue * list,int position){
    int i = 1;
    PrintTask * p = list->head->next;
    while (p != list->rear->next) {
        if (i == position) {
            p->isNeedPrint = 1;
        }
        p = p->next;
        i++;
    }
}
//判断是否是最大的等级
int isMaxRank(LinkQueue * list,int positionRank){
    PrintTask * p = list->head->next;
    while (p != list->rear->next) {
        if (p->rank > positionRank) {
            return 0;
        }
        p = p->next;
    }
    return 1;
}
