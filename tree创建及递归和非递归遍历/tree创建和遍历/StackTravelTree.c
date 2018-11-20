//
//  StackTravelTree.c
//  tree创建和遍历
//
//  Created by 张俊 on 2018/11/13.
//  Copyright © 2018年 zhangjun. All rights reserved.
//

#include "StackTravelTree.h"
#include <stdlib.h>


#pragma mark ------ 栈的基本操作 ------
//建立栈
StackTree* initStackTree(void){
    StackTree * stack = (StackTree *)malloc(sizeof(StackTree));
    if(!stack){
        EXIT_FAILURE;
    }
    stack->base = stack->top = (binaryTree **)malloc(sizeof(binaryTree*)*kInitSize);
    if (!stack->base) {
        EXIT_FAILURE;
    }
    stack->sizeOfStack = kInitSize;
    return stack;
}
//入栈
void pushStackTree(StackTree * stack,binaryTree * element){
    if ((stack->top-stack->base) >= stack->sizeOfStack) {
        stack->base = realloc(stack->base, sizeof(binaryTree*)*(stack->sizeOfStack+kIncreaseSize));
        if (!stack->base) {
            EXIT_FAILURE;
        }
        stack->top = stack->base+stack->sizeOfStack;
        stack->sizeOfStack += kIncreaseSize;
    }
    *(stack->top) = element;
    stack->top++;
}
//出栈
void popStackTree(StackTree * stack,binaryTree ** element){
    if (stack->top>stack->base) {
       *element = *(stack->top-1);
        stack->top--;
    }else{
        printf("栈为空");
        EXIT_FAILURE;
    }
}
//栈是否为空
int isNotStackTreeEmpty(StackTree * stack){
    if (stack->top > stack->base) {
        return 1;
    }
    return 0;
}

//获取栈顶元素
binaryTree * getStackTreeTop(StackTree * stack){
    return *(stack->top-1);
}
#pragma mark ------ 树的操作 ------
//中序遍历
void inOrderTrvaerselTreeMid(binaryTree * tree){
    StackTree *stack = initStackTree();;
    binaryTree * p = tree;
    while (p || isNotStackTreeEmpty(stack)) {
        while (p) {
            pushStackTree(stack, p);
            p = p->lchild;
        }
        if (isNotStackTreeEmpty(stack)){
            popStackTree(stack, &p);
            printf("%c ",p->data);
            p = p->rchild;
        }
    }
}
//前序遍历
void inOrderTrvaerselTreePre(binaryTree * tree){
    StackTree *stack = initStackTree();;
    binaryTree * p = tree;
    while (p || isNotStackTreeEmpty(stack)) {
        while (p) {
             printf("%c ",p->data);
            pushStackTree(stack, p);
            p = p->lchild;
        }
        if (isNotStackTreeEmpty(stack)){
            popStackTree(stack, &p);
            p = p->rchild;
        }
    }
}
//后序遍历
void inOrderTrvaerselTreeLast(binaryTree * tree){
    StackTree *stack = initStackTree();;
    binaryTree * p = tree;
    int flag = 1;
    while (p || isNotStackTreeEmpty(stack)) {
        while (p ) {
            if (flag) {
                pushStackTree(stack, p);
                p->tag = 0;
                p = p->lchild;
            }else{
                return;
            }
        }
        while(isNotStackTreeEmpty(stack) && getStackTreeTop(stack)->tag == 1) {
            popStackTree(stack, &p);
            if (p == tree) {
                flag = 0;
            }
            printf("%c ",p->data);
        }
        if (isNotStackTreeEmpty(stack)){
            getStackTreeTop(stack)->tag = 1;
            p = getStackTreeTop(stack)->rchild;
        }
    }
}
