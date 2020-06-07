//
//  label.h
//  Final Exam 6.5
//
//  Created by Sean Yang on 2019/6/5.
//  Copyright © 2019 Sean Yang. All rights reserved.
//

#ifndef label_h
#define label_h


#endif /* label_h */


#include "edge.h"

class label
{
public:
    node* _node;
    label* _preLabel=NULL;
    int _totApples=0;
    int _totHoney=0;
    label(node *which_node){
        _node=which_node;
    }
};
