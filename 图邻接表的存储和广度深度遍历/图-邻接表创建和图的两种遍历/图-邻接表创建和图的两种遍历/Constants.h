//
//  Constants.h
//  图-邻接表创建和图的两种遍历
//
//  Created by 张俊 on 2018/12/9.
//  Copyright © 2018年 zhangjun. All rights reserved.
//

#ifndef Constants_h
#define Constants_h

#define GraphicSize 8

//链表的结点信息      队列
typedef struct node{
    int index;//数组中的位置
    struct node *next;//头结点
} ArcNode;

//数组中的元素
typedef struct{
    char symbol;//表示的符号
    int index;//位置
    int flag;//用于深度和广度搜索
    ArcNode * firstStart;
}ListElement;
typedef struct{
    ListElement graph[GraphicSize];
} Graphic;

//队列
typedef struct{
    ArcNode * head;
    ArcNode * rear;
} QueueLink;


#endif /* Constants_h */
