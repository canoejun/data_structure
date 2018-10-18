//
//  SystemConversion.c
//  栈的基本操作和应用
//
//  Created by 张俊 on 2018/10/16.
//  Copyright © 2018年 zhangjun. All rights reserved.
//

#include "SystemConversion.h"
#include <stdlib.h>


//创建stack
SystemList* creatSystemList(void){
    SystemList * list = (SystemList *)malloc(sizeof(SystemList));
    if (!list) {
        EXIT_FAILURE;
    }
    list->base = list->top = (int *)malloc(kInitSize * sizeof(int));
    if (!list->base) {
        EXIT_FAILURE;
    }
    list->sizeOfStack = kInitSize;
    return list;
}

//压栈
void pushSystemList(SystemList *list,int element){
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
void popSystemList(SystemList *list,int *element){
    if (list->top>list->base) {
        *element = *(list->top-1);
        list->top--;
    } else {
        printf("此时为空栈");
        EXIT_FAILURE;
    }
}

//遍历stack
void printSystemList(SystemList *list){
    int * p = list->top-1;
    while (p >= list->base) {
        printf("%d",*p);
        p--;
    }
}
