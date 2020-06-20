//
//  Graph.h
//  Final Exam 6.5
//
//  Created by Sean Yang on 2019/6/5.
//  Copyright © 2019 Sean Yang. All rights reserved.
//

#ifndef Graph_h
#define Graph_h


#endif /* Graph_h */

#include "label.h"

class Graph
{
private:
    vector<node*> _nodeList;
    vector<edge*> _edgeList;
    vector<vector<int>> _weight1;
    vector<vector<int>> _weight2;
    
    int _time;
    
    
public:
    Graph(int _vexNum);
    ~Graph();
    
    void addEdge(int w1,int w2, int node1, int node2);
    
    
    vector<vector<int>> getWeight1() { return _weight1; }
    vector<vector<int>> getWeight2() { return _weight2; }
    vector<node*> getNodeList() { return _nodeList; }
    vector<edge*> getEdgeList() { return _edgeList; }

    
    void DFS();
    void DFS_VISIT(node * _node);
    
    
    
    bool AdominateB(label* a, label* b);
    bool BdominateA(label* a, label* b);

    
    
    void print();
    void printNodes();

};
