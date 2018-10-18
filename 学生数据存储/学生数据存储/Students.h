//
//  Students.h
//  学生数据存储
//
//  Created by 张俊 on 2018/10/16.
//  Copyright © 2018年 zhangjun. All rights reserved.
//

#ifndef Students_h
#define Students_h

#include <stdio.h>
#include "Constant.h"

//计算链表的长度
int CalculateLinkList(StudentList *L);

//输入函数
void inputMessage(Student *temp);

StudentList* LinkListInit(void);


int LinkListCreat(StudentList *L);

int LinkListInsert(StudentList *L,int i,Student e);

void LinkListDelete(StudentList *L,int i,Student *e);

Student LinkListLocate1(StudentList *L,int i);

int LinkListLocate2(StudentList *L,char * name);

void LinkListMerge(StudentList * L1,StudentList * L2);

int PrintLinkList(StudentList *L);

void ReadFromFileToLink(StudentList * L,FILE* fp);



#endif /* Students_h */
