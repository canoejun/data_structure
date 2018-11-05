//
//  EvaluateExpression.h
//  栈和队列的应用（算数四则运算和服务器管理网络的打印）
//
//  Created by 张俊 on 2018/10/29.
//  Copyright © 2018年 zhangjun. All rights reserved.
//

#ifndef EvaluateExpression_h
#define EvaluateExpression_h


#include <stdio.h>
#include "Constant.h"

#pragma mark ------ 栈的函数 ------
OPND* initOPNDStack(void);//操作数
OPTR* initOPTRStack(void);//操作符

void PushOPNDStack(OPND * opnd,double number);
void PushOPTRStack(OPTR * optr,char operation);

void PopOPNDStack(OPND * opnd,double *number);
void PopOPTRStack(OPTR * optr,char *operation);

double GetOPNDStackTop(OPND * opnd);
char GetOPTRStackTop(OPTR * optr);

#pragma mark ------ 计算函数 ------
//优先级的函数
char Precede(char a,char b);
//检索运算符所在位置
int SearchOpteration(char a);

//四则运算的主体
double EvaluateExpressionMain(char * expression);

//计算两个整数的值
double Operate(double a,char opteration,double b);

//输入函数
char* ScanfExpression(void);
//判断是否是操作数
int IsOpnd(char a);



#endif /* EvaluateExpression_h */
