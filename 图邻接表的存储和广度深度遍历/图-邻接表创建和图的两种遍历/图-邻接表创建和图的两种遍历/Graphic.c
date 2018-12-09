//
//  Graphic.c
//  图-邻接表创建和图的两种遍历
//
//  Created by 张俊 on 2018/12/9.
//  Copyright © 2018年 zhangjun. All rights reserved.
//

#include "Graphic.h"
#include <stdlib.h>

void createGraph(Graphic* a,char elementList[][10]){
    ListElement * tempListElement;int j;
    for (int i = 0; i < GraphicSize; i++) {
        tempListElement = a->graph+i;
        
        tempListElement->symbol = elementList[i][0];
        //        建立头结点
        ArcNode * q = (ArcNode*)malloc(sizeof(ArcNode));
        if (!q) {
            EXIT_FAILURE;
        }
        tempListElement->firstStart = q;
        tempListElement->firstStart->index = tempListElement->index = elementList[i][1]-'0';
        tempListElement->firstStart->flag = 1;
        tempListElement->firstStart->next = NULL;
        j = 2;
        //        遍历数组，将邻接表内容存入
        while (elementList[i][j] != '#') {
            //            头插法插入元素
            ArcNode * p = (ArcNode *)malloc(sizeof(ArcNode));
            p->index = elementList[i][j]-'0';
            p->flag = 1;
            p->next = tempListElement->firstStart->next;
            tempListElement->firstStart->next = p;
            j++;
        }
    }
}
//打印邻接表
void printGraphList(Graphic  graph){
    ListElement * temp;ArcNode * p;
    for (int  i= 0; i < GraphicSize; i++) {
        temp = graph.graph + i;
        printf("%c ",temp->symbol);
        p = temp->firstStart;
        while (p) {
            printf("%d",p->index);
            p = p->next;
        }
        printf("\n");
    }
}
//深度遍历
void DFSTraverseGraph(Graphic* graph,int index){
    ListElement * tempListElement = graph->graph+index;
    ArcNode * p = tempListElement->firstStart;
    if (p->flag) {
        p->flag = 0;
        printf("%c ",(graph->graph+p->index)->symbol);
        while (p) {
            //    如果这个这个数组元素没有被访问过，那么就访问
            DFSTraverseGraph(graph, p->index);
            p = p->next;
        }
    }
}

//广度遍历
void BFSTraverseGraph(Graphic* graph,int index){
    QueueLink link;ListElement * tempListElement;ArcNode * p;
    createQueueLink(&link);
    for (int i = 0; i < GraphicSize; i++) {
        tempListElement = graph->graph+i;
        p = tempListElement->firstStart;
        while (p) {
            enQueuelink(&link, p);
            p = p->next;
        }
//        出队
        while (link.head != link.rear) {
            deQueuelink(graph, &link);
        }
    }
    
}
#pragma mark ------ 队列的操作 ------
//创建队列
void createQueueLink(QueueLink * link){
    link->head = link->rear = (ArcNode*)malloc(sizeof(ArcNode));
    if (!link->head) {
        EXIT_FAILURE;
    }
    link->head->next = NULL;
}
//入队
void enQueuelink(QueueLink *link,ArcNode * node){
    ArcNode * p = (ArcNode *)malloc(sizeof(ArcNode));
    if (!p) {
        EXIT_FAILURE;
    }
    p->flag = node->flag;
    p->index = node->index;
    p->next = NULL;
    link->rear->next = p;
    link->rear = p;
}
//出队
void deQueuelink(Graphic* graph,QueueLink *link){
    if (link->rear == link->head) {
        EXIT_FAILURE;
    }
    ArcNode * p = link->head->next;
//    判断在邻接表中的flag是否为遍历过的
    if ((graph->graph+p->index)->firstStart->flag) {
        printf("%c ",(graph->graph+p->index)->symbol);
        (graph->graph+p->index)->firstStart->flag = 0;
    }
    
    link->head->next = p->next;
    if (link->rear == p) {
        link->head = link->rear;
    }
    free(p);
}
