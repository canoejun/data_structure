//
//  SqList.h
//  线性表的动态分配
//
//  Created by 张俊 on 2018/10/18.
//  Copyright © 2018年 zhangjun. All rights reserved.
//

#ifndef SqList_h
#define SqList_h

#include <stdio.h>
#include "Constant.h"


//init
void InitSqList(SqList *L);

//creat
void CreatSqList(SqList *L);

//insert
void ListInsert(SqList * L,int i,int word);

//delete
void ListDelete(SqList * L,int i,int * word);

//    locate
int ListLocate(SqList * L,int word);

//MergeList
void ListMergeList(SqList * L1,SqList * L2);

#endif /* SqList_h */
