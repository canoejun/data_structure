//
//  Graphic.h
//  图-邻接表创建和图的两种遍历
//
//  Created by 张俊 on 2018/12/9.
//  Copyright © 2018年 zhangjun. All rights reserved.
//

#ifndef Graphic_h
#define Graphic_h

#include <stdio.h>
#include "Constants.h"

#pragma mark ------ 图的操作 ------
//创建图
void createGraph(Graphic* a,char elementList[][10]);

//打印邻接表
void printGraphList(Graphic  graph);

//深度遍历
void DFSTraverseGraph(Graphic* graph,int index);

//广度遍历
void BFSTraverseGraph(Graphic* graph,int index);

#pragma mark ------ 队列的操作 ------
//创建队列
void createQueueLink(QueueLink * link);
//入队
void enQueuelink(QueueLink *link,ArcNode * node);
//出队
void deQueuelink(Graphic* graph,QueueLink *link);

#endif /* Graphic_h */
