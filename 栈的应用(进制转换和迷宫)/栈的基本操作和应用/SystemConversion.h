//
//  SystemConversion.h
//  栈的基本操作和应用
//
//  Created by 张俊 on 2018/10/16.
//  Copyright © 2018年 zhangjun. All rights reserved.
//

#ifndef SystemConversion_h
#define SystemConversion_h

#include <stdio.h>
#include "Constant.h"

//创建stack
SystemList* creatSystemList(void);

//出栈
void popSystemList(SystemList *list,int *element);

//压栈
void pushSystemList(SystemList *list,int element);

//遍历stack
void printSystemList(SystemList *list);





#endif /* SystemConversion_h */
