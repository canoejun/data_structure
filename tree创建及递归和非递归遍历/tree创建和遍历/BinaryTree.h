//
//  BinaryTree.h
//  tree创建和遍历
//
//  Created by 张俊 on 2018/11/12.
//  Copyright © 2018年 zhangjun. All rights reserved.
//

#ifndef BinaryTree_h
#define BinaryTree_h

#include <stdio.h>
#include "Constants.h"

//创建二叉树
binaryTree*  CreatBiTree(FILE *fp);
//遍历二叉树
void travelBiTreePre(binaryTree * tree);
void travelBiTreeMid(binaryTree * tree);
void travelBiTreeLast(binaryTree * tree);

#endif /* BinaryTree_h */
