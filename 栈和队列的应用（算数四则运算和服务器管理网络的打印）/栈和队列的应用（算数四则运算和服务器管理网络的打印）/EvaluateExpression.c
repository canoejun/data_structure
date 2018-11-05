//
//  EvaluateExpression.c
//  栈和队列的应用（算数四则运算和服务器管理网络的打印）
//
//  Created by 张俊 on 2018/10/29.
//  Copyright © 2018年 zhangjun. All rights reserved.
//

#include "EvaluateExpression.h"
#include <stdlib.h>
#include <string.h>


#pragma mark ------ 栈的函数 ------
OPND* initOPNDStack(void){
    OPND * opnd = (OPND*)malloc(sizeof(OPND));
    if (!opnd) {
        EXIT_FAILURE;
    }
    opnd->base = opnd->top = (double*)malloc(StackInitSize*sizeof(double));
    if (!opnd->base) {
        EXIT_FAILURE;
    }
    opnd->stackSize = StackInitSize;
    return opnd;
    
}//操作数
OPTR* initOPTRStack(void){
    OPTR * optr = (OPTR*)malloc(sizeof(OPTR));
    if (!optr) {
        EXIT_FAILURE;
    }
    optr->base = optr->top = (char *)malloc(StackInitSize * sizeof(char));
    if (!optr->base) {
        EXIT_FAILURE;
    }
    optr->stackSize = StackInitSize;
    *optr->top = '#';
    optr->top++;
    
    return optr;
}//操作符

void PushOPNDStack(OPND * opnd,double number){
    if (opnd->top - opnd->base >= opnd->stackSize) {
        opnd->base = (double *)realloc(opnd->base,(opnd->stackSize+StackIncrement)*sizeof(double));
        if (!opnd->base) {
            EXIT_FAILURE;
        }
        opnd->top = opnd->base + opnd->stackSize;
        opnd->stackSize += StackIncrement;
    }
    *opnd->top++ = number;
}
void PushOPTRStack(OPTR * optr,char operation){
    if (optr->top - optr->base >= optr->stackSize) {
        optr->base = (char *)realloc(optr->base, (optr->stackSize+StackIncrement)*sizeof(char));
        if (!optr->base) {
            EXIT_FAILURE;
        }
        optr->top = optr->base + optr->stackSize;
        optr->stackSize += StackIncrement;
    }
    *optr->top++ = operation;
}

void PopOPNDStack(OPND * opnd,double *number){
    if (opnd->base == opnd->top) {
        EXIT_FAILURE;
    }
    *number = *--opnd->top;
}
void PopOPTRStack(OPTR * optr,char *operation){
    if (optr->base == optr->top) {
        EXIT_FAILURE;
    }
    *operation = *--optr->top;
}
char GetOPTRStackTop(OPTR * optr){
    if (optr->base == optr->top) {
        EXIT_FAILURE;
    }
    return *(optr->top-1);
}
double GetOPNDStackTop(OPND * opnd){
    if (opnd->base == opnd->top) {
        EXIT_FAILURE;
    }
    return *(opnd->top-1);
}
#pragma mark ------ 计算函数 ------
//四则运算的主体
double  EvaluateExpressionMain(char * expression){
    
    ExpressionIsTrue(expression);
    
    char operation;
    double firstNum,secondNum;
    OPND * opnd = initOPNDStack();
    OPTR * optr = initOPTRStack();
    int i = 0;
    
    while (expression[i] != '#' || GetOPTRStackTop(optr)!= '#' ) {
        double num = 0,dotNumber = 1;int flag = 0;
        
        //        如果不是运算数的话，那么直接进栈
        if (IsOpnd(expression[i])) {
            //      进行实数多位数的读入
            while ((expression[i] >= '0' && expression[i] <= '9') || expression[i] == '.') {
                if (flag) {
                    dotNumber = dotNumber * 10;
                }
                if (expression[i] == '.') {
                    num = num ;
                    flag = 1;
                }else{
                    num = num * 10 + (expression[i]-'0');
                }
                i++;
            }
            PushOPNDStack(opnd,num/dotNumber);
        }else{
            switch (Precede(expression[i],GetOPTRStackTop(optr))) {
                case '<':
                    PushOPTRStack(optr, expression[i]);
                    i++;
                    break;
                case '=':
                    PopOPTRStack(optr, &operation);
                    i++;
                    break;
                case '>':
                    PopOPTRStack(optr, &operation);
                    PopOPNDStack(opnd, &firstNum);
                    PopOPNDStack(opnd, &secondNum);
                    PushOPNDStack(opnd, Operate(secondNum, operation, firstNum));
                    break;
                default:
                    break;
            }
        }
    }
    
    return GetOPNDStackTop(opnd);
    
    
}
//优先级的函数
char Precede(char a,char b){
    char result = ' ';
    int columnIndedx = SearchOpteration(a);
    int rowIndex = SearchOpteration(b);
    
    //    返回优先级
    result = pRI[rowIndex][columnIndedx];
    
    return result;
}
//检索运算符所在位置
int SearchOpteration(char a){
    for (int i = 1; i < column; i++) {
        if (pRI[0][i] == a) {
            return i;
        }
    }
    return -1;
}


//计算两个整数的值
double Operate(double a,char opteration,double b){
    double result = 0;
    switch (opteration) {
        case '+':
            result = a+b;
            break;
        case '-':
            result = a-b;
            break;
        case '*':
            result = a*b;
            break;
        case '/':{
            if (b == 0) {
                EXIT_FAILURE;
            }
            result = a/b;
        }
            break;
        default:
            break;
    }
    return result;
}

//输入函数
char* ScanfExpression(void){
    char * expression = NULL;
    static char sentence[50];
    printf("请输入（以#结尾）：");
    scanf("%s",sentence);
    expression = sentence;
    return expression;
}


//判断是否是操作数
int  IsOpnd(char a){
    for (int i = 1; i < column; i++) {
        if (a == pRI[0][i]) {
            return 0;
        }
    }
    return 1;
}


