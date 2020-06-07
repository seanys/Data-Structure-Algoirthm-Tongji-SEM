//
//  main.cpp
//  FastAllPath
//
//  Created by Sean Yang on 2019/5/30.
//  Copyright © 2019 Sean Yang. All rights reserved.
//

#include"Graph.h"
#define VexNum 6

int main()
{
    Graph *g =new Graph(VexNum);
    g->addEdge(3, 0,1);
    g->addEdge(8, 0,2);
    g->addEdge(-4, 0,4);
    g->addEdge(7, 1,4);
    g->addEdge(1, 1,3);
    g->addEdge(4,2,1);
    g->addEdge(2, 3,0);
    g->addEdge (-5, 3,2);
    g->addEdge(6, 4,3);
    g->addEdge(4, 2, 5);
    g->addEdge(2, 4, 5);
    g->addEdge(3, 5, 3);
    vector<vector<int>> L;
    L=g->FastAllPath(g->getWeight());
    
    g->printPath(L);
    
    
    return 0;
}
