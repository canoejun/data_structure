//
//  Queue.c
//  数据结构队列
//
//  Created by 张俊 on 2018/10/23.
//  Copyright © 2018年 zhangjun. All rights reserved.
//

#include "Queue.h"
#include <stdlib.h>


#pragma mark ------ 顺序循环队列 ------
//创建顺序队列
SQueueList* initQueueList(void){
    SQueueList * list = (SQueueList *)malloc(sizeof(SQueueList));
    if (!list) {
        EXIT_FAILURE;
    }
    list->base = (int *)malloc(MaxQSize * sizeof(int));
    if (!list->base) {
        EXIT_FAILURE;
    }
    list->head = list->rear = 0;
    return list;
}
//计算存在多少
int lengthOfQueueList(SQueueList *list){
    return (list->rear-list->head+MaxQSize) % MaxQSize;
}
//入队
void enQueueList(SQueueList * list,int e){
//    队满
    if ((list->rear+1)%MaxQSize == list->head) {
        EXIT_FAILURE;
    }
    *(list->base+list->rear) = e;
    list->rear = (list->rear+1)%MaxQSize;
}
//出队
void deQueueList(SQueueList * list,int * e){
    if (list->rear == list->head) {
        EXIT_FAILURE;
    }
    *e = *(list->base+list->head);
    list->head = (list->head+1) % MaxQSize;
}

#pragma mark ------ 链表队列 ------
LinkQueue* initQueueListPtr(void){
    LinkQueue * listQ = (LinkQueue *)malloc(sizeof(LinkQueue));
    if (!listQ) {
        EXIT_FAILURE;
    }
    listQ->head = listQ->rear = (QueuePtr *)malloc(sizeof(QueuePtr));
    if (!listQ->head) {
        EXIT_FAILURE;
    }
    listQ->head->next = NULL;
    return listQ;
}
//计算存在多少
int lengthOfQueueListPtr(LinkQueue *list){
    QueuePtr * temp = list->head;
    int length = 0;
    while (temp != list->rear) {
        length++;
        temp = temp->next;
    }
    return length;
}
//入队
void enQueueListPtr(LinkQueue * list,int e){
    QueuePtr * p = (QueuePtr *)malloc(sizeof(QueuePtr));
    if (!p) {
        EXIT_FAILURE;
    }
    p->data = e;
    p->next = NULL;
    list->rear->next = p;
    list->rear = p;
}
//出队
void deQueueListPtr(LinkQueue * list,int * e){
    if (list->head == list->rear) {
        EXIT_FAILURE;
    }
    QueuePtr *p = list->head->next;
    *e = p->data;
    list->head->next = p->next;
    if (list->rear == p) {
        list->rear = list->head;
    }
    free(p);
}
