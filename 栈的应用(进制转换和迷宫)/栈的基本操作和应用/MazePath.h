//
//  MazePath.h
//  栈的基本操作和应用
//
//  Created by 张俊 on 2018/10/16.
//  Copyright © 2018年 zhangjun. All rights reserved.
//

#ifndef MazePath_h
#define MazePath_h

#include <stdio.h>
#include "Constant.h"


#pragma mark ------ 栈的方法 ------
//创建stack
MazePathStack * creatMazeStack(void);
//出栈
void popMazeStack(MazePathStack *list,SElemType *element);
//压栈
void pushMazeStack(MazePathStack *list,SElemType element);
//遍历stack
void printMazeStack(MazePathStack *list);
//是否为空栈
int notEmptyStack(MazePathStack *list);

#pragma mark ------ 迷宫的方法 ------
//初始化迷宫
MazeType initMaze(void);

//迷宫路径
MazePathStack* lookMazePath(MazeType maze,PositionType start,PositionType end);

//检测是否能够通过
int isPass(MazeType maze,PositionType position);

//判断四周
PositionType nextPosition(PositionType position,int d);

//记录路径
void recordMazePath(MazeType* maze,PositionType position);

//打印迷宫
void printMaze(MazeType maze);

//记录迷宫当前位置不能通过
void recordUnenableMazePath(MazeType* maze,PositionType position);

//更新栈元素
SElemType newElement(int step,PositionType position,int direction);


#endif /* MazePath_h */






