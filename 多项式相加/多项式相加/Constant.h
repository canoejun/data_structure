//
//  Constant.h
//  多项式相加
//
//  Created by 张俊 on 2018/10/9.
//  Copyright © 2018年 zhangjun. All rights reserved.
//

#ifndef Constant_h
#define Constant_h

typedef struct mul{
    float coefficient;//系数
    int power;//指数
} multinomial;

typedef struct node{
    multinomial formula;
    struct node * next;
}MultinomialList;

#endif /* Constant_h */
