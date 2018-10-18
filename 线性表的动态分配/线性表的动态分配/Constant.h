//
//  Constant.h
//  线性表的动态分配
//
//  Created by 张俊 on 2018/9/14.
//  Copyright © 2018年 zhangjun. All rights reserved.
//

#ifndef Constant_h
#define Constant_h

#define ListInitSize 100
#define ListIncrement 10

typedef struct{
    int * elem;     //存储空间开始的位置
    int length;     //当前存储量
    int listSize;  //当前分配的存储容量
} SqList;
#endif /* Constant_h */







