//
//  Constant.h
//  数据结构队列
//
//  Created by 张俊 on 2018/10/23.
//  Copyright © 2018年 zhangjun. All rights reserved.
//

#ifndef Constant_h
#define Constant_h
#define MaxQSize 100
//顺序队列
typedef struct{
    int * base;
    int  head;
    int  rear;
}SQueueList;

//链式队列
typedef struct QNode{
    int data;
    struct QNode * next;
}QueuePtr;
typedef struct{
    QueuePtr * head;
    QueuePtr * rear;
}LinkQueue;
#endif /* Constant_h */
