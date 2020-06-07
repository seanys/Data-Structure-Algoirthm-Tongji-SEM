//
//  node.h
//  Final Exam 6.5
//
//  Created by Sean Yang on 2019/6/5.
//  Copyright © 2019 Sean Yang. All rights reserved.
//

#ifndef node_h
#define node_h


#endif /* node_h */


#include<vector>
#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;
#define INFI 999999

class edge;
class label;
class node
{
private:
    int _id;
    int _dis;
    node * _prevNode;
    
    
    int _shape;
    int _dtime;
    int _ftime;
    string _name;
    label* _label;
    
    static int _countId;
    vector<node *> _adjNodes;
    vector<node *> new_adjNodes;

    
public:
    
    
    node(int i,int j);
    ~node();
    int getId() { return _id; }
    string getName() { return _name; }
    
    
    int getDis() { return _dis; }
    int getShape() { return _shape; }
    int getFtime() { return _ftime; }
    int getDtime() { return _dtime; }
    
    
    void setName(string name) { _name = name; }
    
    void setDis(int dis) { _dis=dis; }
    void setShape(int shape) { _shape=shape; }
    void setFtime(int ftime) { _ftime=ftime; }
    void setDtime(int dtime) { _dtime=dtime; }
    
    node* getPreNode() { return _prevNode; }
    void setPreNode(node* node) { _prevNode = node; }
    void pushAdjNodes(node * node) { _adjNodes.push_back(node); }
    void pushNewAdjNodes(node * node) { new_adjNodes.push_back(node); }
    vector<node *> getAdjNodes() { return _adjNodes; }
    vector<node *> getNewAdjNodes() { return new_adjNodes; }

    void setLabel(label *new_label){_label=new_label;};
    label* getLabel(){return _label;};

    static bool campByFtime(node* a, node* b);
    
};

