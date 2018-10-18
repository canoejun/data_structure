//
//  Constant.h
//  栈的基本操作和应用
//
//  Created by 张俊 on 2018/10/16.
//  Copyright © 2018年 zhangjun. All rights reserved.
//

#ifndef Constant_h
#define Constant_h


#define kInitSize 100
#define kIncreaseOfSize 10

#define kRows 8
#define kColumns 8
#pragma mark ------ 进制转换 ------

//存储进制转换栈的类型
typedef struct {
    int * top;
    int * base;
    int sizeOfStack;
}SystemList;



#pragma mark ------ 迷宫 ------
//迷宫的类型
typedef struct {
    int *maze[kRows+2];
}MazeType;

//坐标的位置
typedef struct {
    int x;
    int y;
}PositionType;

//栈的数据类型
typedef struct {
    int order;
    int direction;
    PositionType seat;
}SElemType;

//迷宫栈
typedef struct {
    SElemType * top;
    SElemType * base;
    int sizeOfStack;
}MazePathStack;



#endif /* Constant_h */
