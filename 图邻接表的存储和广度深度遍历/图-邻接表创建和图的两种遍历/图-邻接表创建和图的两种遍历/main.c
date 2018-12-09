//
//  main.c
//  图-邻接表创建和图的两种遍历
//
//  Created by 张俊 on 2018/12/9.
//  Copyright © 2018年 zhangjun. All rights reserved.
//

#include <stdio.h>
#include "Constants.h"
#include "Graphic.h"

int main(int argc, const char * argv[]) {
    char a[GraphicSize][10] = {
        {'A','0','2','1','#'},
        {'B','1','5','4','3','0','#'},
        {'C','2','6','5','0','#'},
        {'D','3','7','1','#'},
        {'E','4','7','1','#'},
        {'F','5','7','2','1','#'},
        {'G','6','7','2','#'},
        {'H','7','6','5','4','3','#'},
    };
    
//    深度遍历
    Graphic graph1,graph2;
    createGraph(&graph1, a);
    printGraphList(graph1);
    DFSTraverseGraph(&graph1, 0);
    
//    广度遍历
    createGraph(&graph2, a);
    BFSTraverseGraph(&graph2, 0);
    
    return 0;
}
