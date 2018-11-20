//
//  main.c
//  赫夫曼树的创建及赫夫曼编码
//
//  Created by 张俊 on 2018/11/20.
//  Copyright © 2018年 zhangjun. All rights reserved.
//

#include <stdio.h>
#include "Constants.h"
#include "HTNTree.h"

int main(int argc, const char * argv[]) {
    

    //    将文件中存好的信息进行读取，然后进行统计，然后建立赫夫曼树
    FILE * fp;
    if (!(fp = fopen("/Users/jun/Desktop/大学/大二上/数据结构/实验5赫夫曼树/赫夫曼树的创建及赫夫曼编码/code.txt", "r"))) {
        return 1;
    }
    //    创建赫夫曼树
    HuffmanTree * HTtree = NULL ;
    int n = 0;
    HuffmanCreat(&HTtree,fp,&n);
    fclose(fp);
    
//    显示赫夫曼编码
    HuffmanCoding(HTtree, n);
    
    return 0;
}
