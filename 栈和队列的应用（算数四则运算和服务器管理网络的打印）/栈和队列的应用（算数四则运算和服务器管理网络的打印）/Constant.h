//
//  Constant.h
//  栈和队列的应用（算数四则运算和服务器管理网络的打印）
//
//  Created by 张俊 on 2018/10/29.
//  Copyright © 2018年 zhangjun. All rights reserved.
//

#ifndef Constant_h
#define Constant_h

#define StackInitSize 100
#define StackIncrement 10
#define row 8
#define column 8


typedef struct {
    char * base;
    char * top;
    int stackSize;
}OPTR;//运算符栈

typedef struct {
    double * base;
    double * top;
    int stackSize;
}OPND;//操作数栈

static char pRI[row][column] = {
    {' ','+','-','*','/','(',')','#'},
    {'+','>','>','<','<','<','>','>'},
    {'-','>','>','<','<','<','>','>'},
    {'*','>','>','>','>','<','>','>'},
    {'/','>','>','>','>','<','>','>'},
    {'(','<','<','<','<','<','=',' '},
    {')','>','>','>','>',' ','>','>'},
    {'#','<','<','<','<','<',' ','='},
};

//打印任务
typedef struct node{
    int rank;
    int isNeedPrint;
    struct node * next;
} PrintTask;

typedef struct{
    PrintTask * head;
    PrintTask * rear;
} LinkQueue;


#endif /* Constant_h */
