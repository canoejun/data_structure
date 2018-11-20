//
//  BinaryTree.c
//  tree创建和遍历
//
//  Created by 张俊 on 2018/11/12.
//  Copyright © 2018年 zhangjun. All rights reserved.
//

#include "BinaryTree.h"
#include <stdlib.h>
#include <time.h>


binaryTree*  CreatBiTree(FILE *fp){
    //ABD#FI####C#EG#J##H##
    char ch;
    binaryTree * btree = NULL;
    ch = fgetc(fp);
    if(ch != EOF) {
        //        叶节点
        if (ch == '#') {
            btree = NULL;
        }else{
            btree = (binaryTree*)malloc(sizeof(binaryTree));
            if (!btree) {
                EXIT_FAILURE;
            }
            btree->data = ch;
            btree->lchild = CreatBiTree(fp);
            btree->rchild = CreatBiTree(fp);
        }
    }
    return btree;
}

//遍历二叉树
//前
void travelBiTreePre(binaryTree * tree){
    if (!tree) {
        return;
    }else{
        printf("%c ",tree->data);
        travelBiTreePre(tree->lchild);
        travelBiTreePre(tree->rchild);
    }
}
//中
void travelBiTreeMid(binaryTree * tree){
    if (!tree) {
        return;
    }else{
        travelBiTreeMid(tree->lchild);
        printf("%c ",tree->data);
        travelBiTreeMid(tree->rchild);
    }
}
//后
void travelBiTreeLast(binaryTree * tree){
    if (!tree) {
        return;
    }else{
        travelBiTreeLast(tree->lchild);
    travelBiTreeLast(tree->rchild);
        printf("%c ",tree->data);
    }
}


