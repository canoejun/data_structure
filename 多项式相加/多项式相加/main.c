//
//  main.c
//  多项式相加
//
//  Created by 张俊 on 2018/10/9.
//  Copyright © 2018年 zhangjun. All rights reserved.
//

#include <stdio.h>
#include "Multinomial.h"

int main(int argc, const char * argv[]) {
    MultinomialList * list = initMultinomialList();
    MultinomialList * list1 = initMultinomialList();
    
    
    creatMultinomialList(list, 3);
    creatMultinomialList(list1, 3);
    
    

    MultinomialList * sum =  addMultinomialList(list1, list);
    printf("多项式的相加：  ");
    printMultinomialList(sum);
    
    printf("主函数中的地址%p\n",list);
    MultinomialList * result = multiplyMultinomialList(list, list1);
    printf("多项式的相乘：  ");
    printMultinomialList(result);

    return 0;
}






