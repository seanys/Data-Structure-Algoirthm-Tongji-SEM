//
//  node.h
//  Final Exam
//
//  Created by Sean Yang on 2019/6/3.
//  Copyright © 2019 Sean Yang. All rights reserved.
//

#ifndef node_h
#define node_h


#endif /* node_h */

class Node{
public:
    int key;
    int parent=-1;
    bool visited=false;
    Node(int new_key){
        key=new_key;
    }
};

class Edge{
public:
    int preNode,nextNode;
    int weight;
    Edge(int pre,int next,int new_weight){
        preNode=pre;
        nextNode=next;
        weight=new_weight;
    };
};
