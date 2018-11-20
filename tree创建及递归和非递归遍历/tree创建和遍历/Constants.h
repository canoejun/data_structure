//
//  Constants.h
//  tree创建和遍历
//
//  Created by 张俊 on 2018/11/12.
//  Copyright © 2018年 zhangjun. All rights reserved.
//

#ifndef Constants_h
#define Constants_h

#define kInitSize 100
#define kIncreaseSize 10
//树节点的定义
typedef struct node{
    char data;
    int tag;//0 1
    struct node * lchild;
    struct node * rchild;
} binaryTree;

//栈的数据类型
typedef  struct{
    int sizeOfStack;
    binaryTree ** top;
    binaryTree ** base;
} StackTree;

//队列数据类型
typedef struct node1{
    binaryTree * element;
    struct node1 * next;
}QueueTree;
typedef struct{
    QueueTree * head;
    QueueTree * rear;
} LinkQueue;


#endif /* Constants_h */
