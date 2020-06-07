//
//  node.cpp
//  Final Exam 6.5
//
//  Created by Sean Yang on 2019/6/5.
//  Copyright © 2019 Sean Yang. All rights reserved.
//

#include "node.h"
int node::_countId = 0;

node::node(int i,int j)
{
    _id = _countId++;
    _prevNode = NULL;//for DFS
    _shape = 1;
    _dtime = 0;
    _ftime = 0;
    
    _name=to_string(i) + "_" + to_string(j);
    
}

node::~node()
{
}

bool node::campByFtime(node* a, node* b)
{
    return a->getFtime() > b->getFtime();
}
