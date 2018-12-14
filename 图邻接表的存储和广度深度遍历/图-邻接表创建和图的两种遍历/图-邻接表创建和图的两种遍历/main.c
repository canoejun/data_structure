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
    
    char b[GraphicSize][10] = {
        {'A','0','2','1','#'},
        {'B','1','3','0','#'},
        {'C','2','3','0','#'},
        {'D','3','2','1','#'},
        {'E','4','7','5','#'},
        {'F','5','6','4','#'},
        {'G','6','7','5','#'},
        {'H','7','6','4','#'},
    };
#pragma mark ------ 连通图 ------
    printf("连通图\n");
    //    深度遍历
    Graphic graph;
    createGraph(&graph, a);
    printGraphList(graph);
    printf("深：");
    DFSTraverseGraph(&graph, 0);

    //    将邻接表中的flag值进行重置
    for (int i = 0 ; i < GraphicSize; i++) {
        (graph.graph+i)->flag = 1;
    }

    printf("\n");
    //    广度遍历
    printf("广：");
    BFSTraverseGraph(&graph, 0);
    

#pragma mark ------ 非连通图 ------
    printf("\n非连通图\n");
    //    深度遍历
    Graphic graph1;
    createGraph(&graph1, b);
    printGraphList(graph1);
    printf("深：");
    DFSTraverseGraph(&graph1, 0);
    DFSTraverseGraph(&graph1, 4);


    //    将邻接表中的flag值进行重置
    for (int i = 0 ; i < GraphicSize; i++) {
        (graph1.graph+i)->flag = 1;
    }

    printf("\n");
    //    广度遍历
    printf("广：");
    BFSTraverseGraph(&graph1, 0);
    printf("\n");
    
    return 0;
}
