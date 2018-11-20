
//
//  Constants.h
//  赫夫曼树的创建及赫夫曼编码
//
//  Created by 张俊 on 2018/11/20.
//  Copyright © 2018年 zhangjun. All rights reserved.
//

#ifndef Constants_h
#define Constants_h
typedef struct node{
    char symbol;
    int weight;
    struct node * next;
} SymbolLink;
typedef struct{
    char symbol;
    SymbolLink * L;
    int weight;
    int parent,lchild,rchild;
} HuffmanTree;



#endif /* Constants_h */
