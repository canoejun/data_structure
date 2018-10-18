//
//  main.c
//  线性表的动态分配
//
//  Created by 张俊 on 2018/9/14.
//  Copyright © 2018年 zhangjun. All rights reserved.
//

#include <stdio.h>
//#include <stdlib.h>
#include "Constant.h"
#include "SqList.h"


int main(int argc, const char * argv[]) {
    SqList list;
    SqList list_1;
    int  wordWillDelete;
    
    //    init
    InitSqList(&list);
    printf("init--listSize %d\n",list.listSize);
    
    //    creat
    CreatSqList(&list);
    printf("creat--randWord %d\n",*(list.elem+3));
    for (int i = 0; i < list.length; i++) {
        printf("%d ",*(list.elem+i));
    }
    
    
    //    init
    InitSqList(&list_1);
    printf("init--listSize %d\n",list_1.listSize);
    
    //    creat
    CreatSqList(&list_1);
    printf("creatList_1--randWord %d\n",*(list_1.elem+3));
    for (int i = 0; i < list_1.length; i++) {
        printf("%d ",*(list_1.elem+i));
    }
    
    
    //  insert
    ListInsert(&list, 90, 3);
    printf("insert--length %d\n",list.length);
    
    //    delete
    ListDelete(&list, 3,&wordWillDelete);
    printf("delete--word %d\n",wordWillDelete);
    
    //        locate
    int location = ListLocate(&list,0);
    if (location > -1) {
        printf("locate--wordLocation %d",location);
    }else{
        printf("查找数字的不存在\n");
    }
    
    //        MergeList
    ListMergeList(&list, &list_1);
    printf("\n%d\n\n",list.length);
    for (int i = 0; i < list.length; i++) {
        printf("%d ",*(list.elem+i));
    }
    
    return 0;
}
