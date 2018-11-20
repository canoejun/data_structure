//
//  main.c
//  tree创建和遍历
//
//  Created by 张俊 on 2018/11/12.
//  Copyright © 2018年 zhangjun. All rights reserved.
//

#include <stdio.h>
#include "StackTravelTree.h"
#include "BinaryTree.h"

int main(int argc, const char * argv[]) {
    FILE * fp;
    if (!(fp = fopen("/Users/jun/Desktop/大学/大二上/数据结构/实验4tree/Tree.txt", "r"))) {
        return 1;
    }
    binaryTree *tree;
    tree = CreatBiTree(fp);
    fclose(fp);
    printf("前：");
    travelBiTreePre(tree);printf("\n中：");
    travelBiTreeMid(tree);printf("\n后：");
    travelBiTreeLast(tree);printf("\n");
    
    
    printf("非循环前序的遍历算法:");
    inOrderTrvaerselTreePre(tree);printf("\n");
    printf("非循环中序的遍历算法:");
    inOrderTrvaerselTreeMid(tree);printf("\n");
    printf("非循环后序的遍历算法:");
    inOrderTrvaerselTreeLast(tree);printf("\n");
    
    return 0;
}


