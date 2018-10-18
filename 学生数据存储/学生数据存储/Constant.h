//
//  Constant.h
//  学生数据存储
//
//  Created by 张俊 on 2018/10/16.
//  Copyright © 2018年 zhangjun. All rights reserved.
//

#ifndef Constant_h
#define Constant_h
//学生数据类型
typedef struct stu{
    char name[20];
    int studentNumber;
    int sex;
    int age;
    char major[20];
} Student;
//结构体
typedef struct LNode{
    Student data;
    struct LNode * next;
}StudentList;

#endif /* Constant_h */
