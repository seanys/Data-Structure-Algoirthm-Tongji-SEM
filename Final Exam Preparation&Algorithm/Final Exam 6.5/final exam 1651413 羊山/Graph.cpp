//
//  Graph.cpp
//  Final Exam 6.5
//
//  Created by Sean Yang on 2019/6/5.
//  Copyright © 2019 Sean Yang. All rights reserved.
//

#include "Graph.h"

Graph::Graph(int vexNum)
{
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0;j < 4;j++)
        {
            node * z = new node(i,j);
            _nodeList.push_back(z);
        }
        
    }
    
    
    _weight1.resize(vexNum);
    for (int i = 0; i < _weight1.size(); i++)
    {
        _weight1[i].resize(vexNum);
        for (int j = 0; j < _weight1[i].size(); j++)
        {
            _weight1[i][j] = INFI;
        }
    }
    for (int i = 0; i < _weight1.size(); i++)
    {
        _weight1[i][i] = 0;
    }
    
    
    _weight2.resize(vexNum);
    for (int i = 0; i < _weight2.size(); i++)
    {
        _weight2[i].resize(vexNum);
        for (int j = 0; j < _weight2[i].size(); j++)
        {
            _weight2[i][j] = INFI;
        }
    }
    for (int i = 0; i < _weight2.size(); i++)
    {
        _weight2[i][i] = 0;
    }
    
    
}
Graph::~Graph()
{
}

void Graph::addEdge(int w1,int w2, int node1, int node2)
{
    edge *e = new edge(_nodeList[node1],_nodeList[node2]);
    _weight1[node1][node2] = w1;
    _weight2[node1][node2] = w2;
}



void Graph::DFS()
{
    _time = 0;
    for (int i = 0; i < _nodeList.size(); i++)
        if (_nodeList[i]->getShape() == 1)
            DFS_VISIT(_nodeList[i]);
}

void Graph::DFS_VISIT(node * _node)
{
    _node->setShape(0);
    _time++;
    _node->setDtime(_time);
    vector<node *> Adj = _node->getAdjNodes();
    for (int i = 0; i < Adj.size(); i++)
    {
        if (Adj[i]->getShape() == 1)
        {
            Adj[i]->setPreNode(_node);
            Adj[i]->setDtime(_time);
            DFS_VISIT(Adj[i]);
        }
    }
    _node->setShape(-1);
    _time++;
    _node->setFtime(_time);
    
}


bool Graph::AdominateB(label* l1, label* l2)
{
    if(l1->_totApples>=l2->_totApples&&l1->_totHoney>l2->_totHoney){
        return true;
    }
    if(l1->_totApples>=l2->_totApples&&l1->_totHoney>l2->_totHoney){
        return true;
    }
    return false;
}

bool Graph::BdominateA(label* l1, label* l2)
{
    if(l1->_totApples>=l2->_totApples&&l1->_totHoney>=l2->_totHoney){
        return true;
    }
    return false;
}

void Graph::print()
{
    cout<<_nodeList[0]->getName()<<":"<<_nodeList[0]->getDtime()<<" "<<_nodeList[0]->getFtime()<<endl;
    return;
}

void Graph::printNodes(){
    for(int i=0;i<12;i++){
        if((i)%4==0&&i>0)cout<<endl;
        label *new_label=_nodeList[i]->getLabel();
        cout<<_nodeList[i]->getName()<<"("<<_nodeList[i]->getId()<<"):"<<" "<<new_label->_totApples<<" "<<new_label->_totHoney<<"    ";
    }
    cout<<endl;
}
