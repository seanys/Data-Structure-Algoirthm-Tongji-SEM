//
//  edge.h
//  Final Exam
//
//  Created by Sean Yang on 2019/6/4.
//  Copyright © 2019 Sean Yang. All rights reserved.
//

#ifndef edge_h
#define edge_h


#endif /* edge_h */

class Edge{
public:
    int node1,node2;
    int weight;
    Edge(int i,int j,int new_weight){
        node1=i;
        node2=j;
        weight=new_weight;
    }
};
