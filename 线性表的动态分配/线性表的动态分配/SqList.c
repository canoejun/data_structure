//
//  SqList.c
//  线性表的动态分配
//
//  Created by 张俊 on 2018/10/18.
//  Copyright © 2018年 zhangjun. All rights reserved.
//


#include <stdlib.h>
#include "SqList.h"


#pragma mark ------ Function ------
//init
void InitSqList(SqList *L){
    L->elem = (int*)malloc(ListInitSize * sizeof(int));
    if (!L->elem) {
        EXIT_FAILURE;
    }
    L->length = 0;
    L->listSize = ListInitSize;
}

//creat
void CreatSqList(SqList *L){
    int * temp = L->elem;
    for (int i = 0; i < 90; i++) {
        *(temp+i) = i+1;
        L->length++;
    }
    
}

//insert
void ListInsert(SqList * L,int i,int word){
    //    是否合法
    if (i < 1 || i > L->length+1) {
        EXIT_FAILURE;
    }
    
    //  由于多次都调用，可能造成长度超过
    if (L->length >= L->listSize) {
        L->elem = realloc(L->elem, (ListInitSize+ListIncrement)*sizeof(int));
        if (!L->elem) {
            EXIT_FAILURE;
        }
        L->listSize += ListIncrement;
    }
    int * q = L->elem+i-1;
    for (int * p = L->elem + L->length-1; p >= q; p--) {
        *(p+1) = *p;
    }
    *q = word;
    L->length ++;
}

//delete
void ListDelete(SqList * L,int i,int * word){
    //    是否合法
    if (i < 1 || i > L->length) {
        EXIT_FAILURE;
    }
    
    int * q = L->elem+i-1;
    *word = *q;
    for (int * p = L->elem + L->length-1; q <= p; q++) {
        *(q-1) = *q;
    }
    L->length --;
}

//    locate
int ListLocate(SqList * L,int word){
    int i = 0;
    int * temp = L->elem;
    while (i < L->length) {
        if (*(temp++) != word) {
            i++;
        }else{
            return ++i;
        }
    }
    return -1;
}

//MergeList
void ListMergeList(SqList * L1,SqList * L2){
    L1->listSize = L1->length+L2->length;
    L1->elem  = (int*)realloc(L1->elem, L1->listSize*sizeof(int));
    if (!L1->elem) {
        EXIT_FAILURE;
    }
    int * L2temp = L2->elem;
    int * p = L1->elem+L1->length;
    while (L2temp < L2->elem+L2->length) {
        *p++ = *L2temp++;
        L1->length++;
    }
    int temp;
    for (int * i = L1->elem; i < L1->elem+L1->length; i++) {
        for (int * j = i; j < L1->elem+L1->length; j++) {
            if (*i>*j) {
                temp = *j;
                *j = *i;
                *i = temp;
            }
        }
    }
    
    L1->listSize = L1->length;
}
