//
//  edge.cpp
//  Final Exam 6.5
//
//  Created by Sean Yang on 2019/6/5.
//  Copyright © 2019 Sean Yang. All rights reserved.
//

#include "edge.h"


edge::edge( node * node1, node * node2)
{
    _node1 = node1;
    _node2 = node2;
    node1->pushAdjNodes(node2);
    
}

edge::~edge()
{
}
