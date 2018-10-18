//
//  MultinomialList.h
//  多项式相加
//
//  Created by 张俊 on 2018/10/9.
//  Copyright © 2018年 zhangjun. All rights reserved.
//

#ifndef MultinomialList_h
#define MultinomialList_h

#include <stdio.h>
#include "Constant.h"

//初始化
MultinomialList * initMultinomialList(void);

//创建多项式
void creatMultinomialList(MultinomialList * L,int a);

//打印多项式
void printMultinomialList(MultinomialList * L);

//完成多项式的相加
MultinomialList * addMultinomialList(MultinomialList *L1,MultinomialList * L2);

//多项式相乘
MultinomialList * multiplyMultinomialList(MultinomialList *L1,MultinomialList * L2);

//返回多项式的相数
int lengthOfMultinomialList(MultinomialList *L);



#endif /* MultinomialList_h */
