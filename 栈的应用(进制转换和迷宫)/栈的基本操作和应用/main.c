//
//  main.c
//  栈的基本操作和应用
//
//  Created by 张俊 on 2018/10/16.
//  Copyright © 2018年 zhangjun. All rights reserved.
//

#include <stdio.h>
#include "Constant.h"
#include "SystemConversion.h"
#include "MazePath.h"

//进制转换
void systemsConversion(SystemList *list);

int main(int argc, const char * argv[]) {

    
//    SystemList * list = creatSystemList();
//    systemsConversion(list);
    
    #pragma mark ------ 迷宫 ------
    MazeType maze = initMaze();
    
    printMaze(maze);
    printf("\n");
    PositionType start = {1,1};
    PositionType end = {8,8};
    MazePathStack * s = lookMazePath(maze, start, end);
    
    printMazeStack(s);
    printf("\n");
    printMaze(maze);
    
    
    
    return 0;
}

void systemsConversion(SystemList *list){
    int num , systems;
    printf("请输入需要转换的数字：");
    scanf("%d",&num);
    printf("请输入需要转换成的进制：");
    scanf("%d",&systems);
    while (num) {
        pushSystemList(list, num % systems);
        num = num / systems;
    }
    printSystemList(list);
}











