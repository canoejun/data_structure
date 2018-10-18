//
//  main.c
//  学生数据存储
//
//  Created by 张俊 on 2018/9/17.
//  Copyright © 2018年 zhangjun. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "Constant.h"
#include "Students.h"
#include <string.h>

int main(int argc, const char * argv[]) {
    int selectNumber = -1;
    
    
    
    //    init
    StudentList * stu = LinkListInit();
    
    
    FILE *fp = NULL;
    //    if (!(fp = fopen("/Users/jun/Desktop/Student.txt", "w+"))) {
    //        EXIT_FAILURE;
    //    }
    
    while (selectNumber) {
        printf("********按0退出**************\n");
        printf("********1.初始化和创建数据********\n");
        printf("********2.从文件中读取数据********\n");
        printf("********3.添加**************\n");
        printf("********4.删除**************\n");
        printf("********5.按位置查找*********\n");
        printf("********6.按姓名查找*********\n");
        printf("********7.合并两个***********\n");
        printf("********8.查看**************\n");
        printf("请输入你想进行的操作:");
        scanf("%d",&selectNumber);
        if (selectNumber == 0) {
            break;
        }
        switch (selectNumber) {
            case 1:
                //    creat
                LinkListCreat(stu);
                //    print
                PrintLinkList(stu);
                printf("\n--------------------------\n");
                break;
            case 2:
                //                read from file
                ReadFromFileToLink(stu, fp);
                break;
            case 3:{
                Student insertStu;int insertStuNumber = 0;
                //    insert
                while (1) {
                    printf("请输入你将要插入的同学的姓名(#退出):");
                    scanf("%s",insertStu.name);
                    if (strcmp("#", insertStu.name) != 0) {
                        printf("请输入你将要插入的同学的学号:");
                        scanf("%d",&insertStu.studentNumber);
                        printf("请输入你将要插入的同学的性别(男0女1):");
                        scanf("%d",&insertStu.sex);
                        printf("请输入你将要插入的同学的年龄:");
                        scanf("%d",&insertStu.age);
                        printf("请输入你将要插入的同学的专业:");
                        scanf("%s",insertStu.major);
                        printf("请输入你将要插入的位置:");
                        scanf("%d",&insertStuNumber);
                        LinkListInsert(stu, insertStuNumber,insertStu);
                    }else{
                        break;
                    }
                    
                }
            }
                printf("\n--------------------------\n");
                break;
            case 4:{
                //    delete
                Student deleteStu; int deleteStuNumber = 0;
                while (1) {
                    printf("请输入删除的位置(0退出):");
                    scanf("%d",&deleteStuNumber);
                    if (deleteStuNumber != 0) {
                        LinkListDelete(stu,deleteStuNumber , &deleteStu);
                    }else{
                        break;
                    }
                }
            }
                printf("\n--------------------------\n");
                break;
            case 5:{
                int locateStuByNumber = 0;Student locateNumberStu;
                while (1) {
                    printf("请输入你想查找的位置(0退出):");
                    scanf("%d",&locateStuByNumber);
                    if (locateStuByNumber != 0) {
                        locateNumberStu = LinkListLocate1(stu,locateStuByNumber);
                        if (strcmp(locateNumberStu.name,stu->data.name) != 0) {
//                            将没有超过查询范围的学生数据输出
                            printf("姓名:%10s ",locateNumberStu.name);
                            printf("学号:%3d ",locateNumberStu.studentNumber);
                            printf("性别:%6s ",(locateNumberStu.sex == 0 ? "male":"female"));
                            printf("年龄:%2d ",locateNumberStu.age);
                            printf("专业:%10s\n",locateNumberStu.major);
                        }
                    }else{
                        break;
                    }
                }
            }
                
                printf("\n--------------------------\n");
                break;
            case 6:
                while (1) {
                    char locateStuByName[20];
                    printf("请输入你想查找的姓名(#退出):");
                    scanf("%s",locateStuByName);
                    if (strcmp(locateStuByName, "#") != 0) {
                        if (LinkListLocate2(stu,locateStuByName)>0) {
                            printf("位置是%d\n",LinkListLocate2(stu,locateStuByName)+1);
                        }
                    }else{
                        break;
                    }
                    
                }
                break;
            case 7:
                //    mergeList
                //                LinkListMerge(<#StudentList *L1#>, <#StudentList *L2#>)
                break;
            case 8:
                PrintLinkList(stu);
                break;
            default:
                break;
        }
    }
    //    为了将新数据写入进去
    if (!(fp = fopen("/Users/jun/Desktop/Student.txt", "w+"))) {
        EXIT_FAILURE;
    }
    PrintLinkList(stu);
    //    写入到文件中去
    StudentList * p = stu->next;
    while (p) {
        fprintf(fp, "%s %d %d %d %s\n",p->data.name,p->data.studentNumber,p->data.sex,p->data.age,p->data.major);
        p = p->next;
    }
    fclose(fp);
    
    
    
    return 0;
}











