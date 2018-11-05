//
//  NetWorkPrintTask.h
//  栈和队列的应用（算数四则运算和服务器管理网络的打印）
//
//  Created by 张俊 on 2018/10/29.
//  Copyright © 2018年 zhangjun. All rights reserved.
//

#ifndef NetWorkPrintTask_h
#define NetWorkPrintTask_h

#include <stdio.h>
#include "Constant.h"

//创建链队
LinkQueue* creatLinkQueue(void);
//入队
//void enLinkQueue(LinkQueue * list,int e,int isNeedPrint);
//出队
void deLinkQueue(LinkQueue * list,int *e,int * isNeedPrint);

void printQueue(LinkQueue * list);

void printTaskMain(void);

void searchPosition(LinkQueue * list,int position);
//判断是否是最大的等级
int isMaxRank(LinkQueue * list,int positionRank);

#endif /* NetWorkPrintTask_h */
