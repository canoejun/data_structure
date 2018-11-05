//
//  main.c
//  栈和队列的应用（算数四则运算和服务器管理网络的打印）
//
//  Created by 张俊 on 2018/10/29.
//  Copyright © 2018年 zhangjun. All rights reserved.
//

#include <stdio.h>
#include "EvaluateExpression.h"
#include <string.h>
#include "NetWorkPrintTask.h"
#include <stdbool.h>

int main(int argc, const char * argv[]) {
    
//    计算实数的四则表达式
   char * sen =  ScanfExpression();
    printf("%lf",EvaluateExpressionMain(sen));
    
//    打印任务
    printTaskMain();
    
    return 0;
}
