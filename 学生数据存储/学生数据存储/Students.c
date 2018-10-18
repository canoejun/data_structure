//
//  Students.c
//  学生数据存储
//
//  Created by 张俊 on 2018/10/16.
//  Copyright © 2018年 zhangjun. All rights reserved.
//

#include "Students.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//计算链表的长度
int CalculateLinkList(StudentList *L){
    int length = 0;
    StudentList * q = L->next;
    while (q) {
        length++;
        q = q->next;
    }
    return length;
}

//输入函数
void inputMessage(Student *temp){
    printf("请输入学号:");
    scanf("%d",&(*temp).studentNumber);
    printf("请输入性别(男为0，女为1):");
    scanf("%d",&(*temp).sex);
    while ((*temp).sex<0||(*temp).sex>1) {
        printf("请输入性别(男为0，女为1):");
        scanf("%d",&(*temp).sex);
    }
    printf("请输入年龄:");
    scanf("%d",&(*temp).age);
    printf("请输入专业:");
    scanf("%s",(*temp).major);
}

StudentList* LinkListInit(){
    StudentList * L = (StudentList*)malloc(sizeof(StudentList));
    L->next = NULL;
    return L;
}


int LinkListCreat(StudentList *L){
    if(!CalculateLinkList(L)){
        //    尾插法
        StudentList * q = L;
        Student temp ;
        printf("请输入姓名:");
        scanf("%s",temp.name);
        if (strcmp(temp.name,"#")== 0) {
            return -1;
        }
        inputMessage(&temp);
        while (strcmp(temp.name,"#")!= 0) {
            StudentList * p = (StudentList*)malloc(sizeof(StudentList));
            printf("%s",p->data.name);
            p->data = temp;
            q->next = p;
            q = p;
            printf("请输入姓名(#键退出):");
            scanf("%s",temp.name);
            if (strcmp(temp.name,"#")== 0) {
                break;
            }
            inputMessage(&temp);
        }
        q->next = NULL;
        
//        头插法
//        while (strcmp(temp.name,"#")!= 0) {
//            StudentList * p = (StudentList*)malloc(sizeof(StudentList));
//            printf("%s",p->data.name);
//            p->data = temp;
//            p->next = L->next;
//            L->next = p;
//            printf("请输入姓名(#键退出):");
//            scanf("%s",temp.name);
//            if (strcmp(temp.name,"#")== 0) {
//                break;
//            }
//            inputMessage(&temp);
//        }
    }else{
        printf("链表已经存在!");
        getchar();getchar();
    }
    return 0;
}

int LinkListInsert(StudentList *L,int i,Student e){
    //    首先判断i值的有效性
    StudentList * p = L;
    int j = 0;
    while (p && j < i-1) {
        p = p->next;
        j++;
    }
    if (i != 0) {
        //  防止从文件中读取的时候出现打印的错误
        if (!p || j > i-1) {
            printf("输入的删除位置的数值有误!\n");
            return -1;
        }
    }
    StudentList * s = (StudentList *)malloc(sizeof(StudentList));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return 0;
}

void LinkListDelete(StudentList *L,int i,Student *e){
    //    e是删除的，返回去
    //    首先判断i值的有效性
    StudentList * p = L;
    int j = 0;
    while (p && j < i-1) {
        p = p->next;
        j++;
    }
    if (!p || j > i-1) {
        EXIT_FAILURE;
    }
    StudentList * q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);
}

Student LinkListLocate1(StudentList *L,int i){
    StudentList * p = L->next;
    int j = 0;
    while (p && j < i-1) {
        p = p->next;
        ++j;
    }
    if (!p || j > i-1) {
        printf("查找的范围超过学生数!\n");
        return L->data;
    }
    return p->data;
}

int LinkListLocate2(StudentList *L,char * name){
    StudentList * p = L->next;
    int j = 0;
    while (p && strcmp(p->data.name, name) != 0) {
        p = p->next;
        ++j;
    }
    if (!p) {
        printf("查无此人!\n");
        return -1;
    }
    return j;
}

void LinkListMerge(StudentList * L1,StudentList * L2){
    StudentList * pa = L1->next;
    StudentList * pb = L2->next;
    StudentList * pc = L1->next;
    while (pa &&  pb) {
        if (pa->data.studentNumber <= pb->data.studentNumber) {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        }else{
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    pc->next = pa ? pa:pb;
    free(L2);
}

int PrintLinkList(StudentList *L){
    int length = 0;
    StudentList * q = L->next;
    while (q) {
        length++;
        printf("\n姓名:%10s ",q->data.name);
        printf("学号:%3d ",q->data.studentNumber);
        printf("性别:%6s ",(q->data.sex == 0 ? "male":"female"));
        printf("年龄:%2d ",q->data.age);
        printf("专业:%10s\n",q->data.major);
        q = q->next;
    }
    return length;
}

void ReadFromFileToLink(StudentList * L,FILE* fp){
    //    读取
    int i = 1;
    if (!(fp = fopen("/Users/jun/Desktop/Student.txt", "r+"))) {
        EXIT_FAILURE;
    }
    Student  q;
    while (!feof(fp)) {
        fscanf(fp, "%s%d%d%d%s",q.name,&q.studentNumber,&q.sex,&q.age,q.major);
        LinkListInsert(L,i, q);
        i++;
    }
    LinkListDelete(L, CalculateLinkList(L),&q);
    PrintLinkList(L);
    
    fclose(fp);
}
