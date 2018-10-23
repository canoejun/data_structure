//
//  Queue.h
//  数据结构队列
//
//  Created by 张俊 on 2018/10/23.
//  Copyright © 2018年 zhangjun. All rights reserved.
//

#ifndef Queue_h
#define Queue_h

#include <stdio.h>
#include "Constant.h"

#pragma mark ------ 顺序循环队列 ------
//创建顺序队列
SQueueList* initQueueList(void);
//计算存在多少
int lengthOfQueueList(SQueueList *list);
//入队
void enQueueList(SQueueList * list,int e);
//出队
void deQueueList(SQueueList * list,int * e);

#pragma mark ------ 链表队列 ------
LinkQueue* initQueueListPtr(void);
//计算存在多少
int lengthOfQueueListPtr(LinkQueue *list);
//入队
void enQueueListPtr(LinkQueue * list,int e);
//出队
void deQueueListPtr(LinkQueue * list,int * e);

#endif /* Queue_h */
