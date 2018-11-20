//
//  StackTravelTree.h
//  tree创建和遍历
//
//  Created by 张俊 on 2018/11/13.
//  Copyright © 2018年 zhangjun. All rights reserved.
//

#ifndef StackTravelTree_h
#define StackTravelTree_h

#include <stdio.h>
#include "Constants.h"

#pragma mark ------ 栈的基本操作 ------
//建立栈
StackTree* initStackTree(void);
//入栈
void pushStackTree(StackTree * stack,binaryTree * element);
//出栈
void popStackTree(StackTree * stack,binaryTree ** element);
//栈是否为空
int isNotStackTreeEmpty(StackTree * stack);
//获取栈顶元素
binaryTree * getStackTreeTop(StackTree * stack);

#pragma mark ------ 树的操作 ------
//中序遍历
void inOrderTrvaerselTreeMid(binaryTree * tree);
//前序遍历
void inOrderTrvaerselTreePre(binaryTree * tree);
//后序遍历
void inOrderTrvaerselTreeLast(binaryTree * tree);

#endif /* StackTravelTree_h */
