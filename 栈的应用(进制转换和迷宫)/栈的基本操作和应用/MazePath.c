//
//  MazePath.c
//  栈的基本操作和应用
//
//  Created by 张俊 on 2018/10/16.
//  Copyright © 2018年 zhangjun. All rights reserved.
//

#include "MazePath.h"
#include <stdlib.h>


#pragma mark ------ stack方法 ------
//创建stack
MazePathStack * creatMazeStack(void){
    MazePathStack * list = (MazePathStack *)malloc(sizeof(MazePathStack));
    if (!list) {
        EXIT_FAILURE;
    }
    list->base = list->top = (SElemType *)malloc(kInitSize * sizeof(SElemType));
    if (!list->base) {
        EXIT_FAILURE;
    }
    list->sizeOfStack = kInitSize;

    return list;
}

//压栈
void pushMazeStack(MazePathStack *list,SElemType element){
    if ((list->top - list->base) >= list->sizeOfStack) {
        list->base = realloc(list->base, (list->sizeOfStack + kIncreaseOfSize) * sizeof(int));
        if (!list->base) {
            EXIT_FAILURE;
        }
        list->top = list->base + list->sizeOfStack;
        list->sizeOfStack = (list->sizeOfStack + kIncreaseOfSize);
    }
    *(list->top) = element;
    list->top++;
}

//出栈
void popMazeStack(MazePathStack *list,SElemType *element){
    if (list->top>list->base) {
        *element = *(list->top-1);
        list->top--;
    } else {
        printf("此时无法退回");
        EXIT_FAILURE;
    }
}

//遍历stack
void printMazeStack (MazePathStack *list){
    SElemType * p = list->top-1;
    while (p >= list->base) {
        printf("第%2d步 方向 %d (%d,%d)\n",p->order,p->direction,p->seat.y,p->seat.x);
        p--;
    }
}

//是否为空栈
int notEmptyStack(MazePathStack *list){
    if (list->top > list->base) {
        return 1;
    }
    return 0;
}

#pragma mark ------ 迷宫的方法 ------
//初始化迷宫
MazeType initMaze(void){
    MazeType* tempMaze = (MazeType*)malloc(sizeof(MazeType));
    if (!tempMaze) {
        EXIT_FAILURE;
    }
    int a[kRows+2][kColumns+2]= {
        1,1,1,1,1,1,1,1,1,1,
        1,0,0,1,0,0,0,1,0,1,
        1,0,0,1,0,0,0,1,0,1,
        1,0,0,0,0,1,1,0,0,1,
        1,0,1,1,1,0,0,0,0,1,
        1,0,0,0,1,0,0,0,0,1,
        1,0,1,0,0,0,1,0,0,1,
        1,0,1,1,1,0,1,1,0,1,
        1,1,0,0,0,0,0,0,0,1,
        1,1,1,1,1,1,1,1,1,1
    };
    for (int i = 0; i < kRows+2; i++) {
        tempMaze->maze[i] = (int *)malloc(sizeof(int)*(kColumns+2));
        if (!tempMaze->maze[i]) {
            EXIT_FAILURE;
        }
    }
    for (int i = 0; i < kRows+2; i++) {
        for (int j = 0; j < kColumns + 2;j++) {
            tempMaze->maze[i][j] = a[i][j];
        }
    }
    return *tempMaze;
}

//迷宫路径
MazePathStack* lookMazePath(MazeType maze,PositionType start,PositionType end){
   MazePathStack *s = creatMazeStack();
    SElemType element;
    PositionType currentPosition;//当前位置
    currentPosition = start;
    int currentStep = 1;
    
    do {
        if (isPass(maze,currentPosition)) {
            recordMazePath(&maze, currentPosition);
            element = newElement(currentStep, currentPosition, 1);
            pushMazeStack(s, element);
            if (currentPosition.x == end.x && currentPosition.y == end.y) {
                printf("走出迷宫\n");
                EXIT_SUCCESS;
                return s;
            }
            //        进行下个位置的判断  
            currentPosition = nextPosition(currentPosition, 1);
            currentStep++;
        }else{
            if (notEmptyStack(s)) {
                popMazeStack(s, &element);
                while (element.direction == 4 && notEmptyStack(s)) {
//                    记录不能通过
                    recordUnenableMazePath(&maze, element.seat);
                    popMazeStack(s, &element);
                    currentStep = element.order+1;
                }
            }
            if (element.direction < 4) {
                element.direction++;
                pushMazeStack(s, element);
                currentPosition = nextPosition(element.seat,element.direction);
            }
        }
    } while (notEmptyStack(s));
//    空栈依然出栈  错误
    return NULL;
}

//检测是否能够通过
int isPass(MazeType maze,PositionType position){
    if (maze.maze[position.x][position.y] == 0 ) {
        return 1;
    }else{
        return 0;
    }
}

//判断四周
PositionType nextPosition(PositionType position,int d){
    switch (d) {
//            从开始先向南
            
        case 1://南
            position.x++;
            break;
        case 2://东
            position.y++;
            break;
        case 3://北
            position.x--;
            break;
        case 4://西
            position.y--;
            break;
            
//            从开始先向东
            
//        case 1://东
//            position.y++;
//            break;
//        case 2://南
//            position.x++;
//            break;
//        case 3://西
//            position.y--;
//            break;
//        case 4://北
//            position.x--;
//            break;
        default:
            printf("方向错误");
            break;
    }
    return position;
}


//记录路径
void recordMazePath(MazeType* maze,PositionType position){
    maze->maze[position.x][position.y] = 8;
}

//记录迷宫当前位置不能通过
void recordUnenableMazePath(MazeType* maze,PositionType position){
    maze->maze[position.x][position.y] = 2;
}

//打印迷宫
void printMaze(MazeType maze){
    for (int i = 0; i < kRows+2; i++) {
        for (int j = 0; j < kColumns + 2;j++) {
            printf("%d ",maze.maze[i][j]);
        }
        printf("\n");
    }
}
//更新栈元素
SElemType newElement(int step,PositionType position,int direction){
    SElemType e;
    e.direction = direction;
    e.order = step;
    e.seat = position;
    return e;
}




