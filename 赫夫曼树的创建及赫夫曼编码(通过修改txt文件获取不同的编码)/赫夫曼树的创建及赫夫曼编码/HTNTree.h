//
//  HTNTree.h
//  赫夫曼树的创建及赫夫曼编码
//
//  Created by 张俊 on 2018/11/20.
//  Copyright © 2018年 zhangjun. All rights reserved.
//

#ifndef HTNTree_h
#define HTNTree_h

#include <stdio.h>
#include "Constants.h"

//赫夫曼树的创建
void HuffmanCreat(HuffmanTree ** HT,FILE * fp,int* count);

//赫夫曼编码
void HuffmanCoding(HuffmanTree * HT,int n);

#endif /* HTNTree_h */
