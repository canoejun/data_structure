//
//  main.c
//  数据结构队列
//
//  Created by 张俊 on 2018/10/23.
//  Copyright © 2018年 zhangjun. All rights reserved.
//

#include <stdio.h>
#include "Constant.h"
#include "Queue.h"

int main(int argc, const char * argv[]) {
    #pragma mark ------ 顺序的循环队列 ------
    SQueueList * list = initQueueList();
    int count = 3,temp;
    while (count > -1) {
        enQueueList(list, count);
        count--;
    }
    printf("QueueLength---%d\n",lengthOfQueueList(list));//结果是 4
    while (count < 3) {
        deQueueList(list, &temp);
        printf("%d ",temp);
        count++;
    }//结果是  3 2 1 0
    
    #pragma mark ------ 链表队列 ------
    LinkQueue * listPtr = initQueueListPtr();
    while (count > -1) {
        enQueueListPtr(listPtr, count);
        count--;
    }
    printf("\nQueuePtrLength---%d\n",lengthOfQueueListPtr(listPtr));//结果是4
    while (count < 3) {
        deQueueListPtr(listPtr,&temp);
        printf("%d ",temp);
        count++;
    } //结果是  3 2 1 0
    return 0;
}









