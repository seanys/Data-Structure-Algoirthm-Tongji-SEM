//
//  main.cpp
//  Final Exam 6.5
//
//  Created by Sean Yang on 2019/6/5.
//  Copyright © 2019 Sean Yang. All rights reserved.
//

#include"Graph.h"
#define VexNum 12
vector <node *> node_list;
vector <vector <int>> weight1;
vector <vector <int>> weight2;
int start=0;
void dealNode(int final_id,bool AB);
void printPath();
Graph *g =new Graph(VexNum);

int main()
{
    
    g->addEdge(0, 2, 0, 1);
    g->addEdge(0, -1, 1, 2);
    g->addEdge(1, 1, 2, 3);
    g->addEdge(-1, 4, 4, 5);
    g->addEdge(2, 1, 5, 6);
    g->addEdge(1, -3, 6, 7);
    g->addEdge(2, 1, 8, 9); //change g->addEdge(2, 1, 8, 10); 
    g->addEdge(1, -2, 9, 10);
    g->addEdge(1, 1, 10, 11);
    
    g->addEdge(3, 1, 0, 4);
    g->addEdge(-1, 0, 4, 8);
    g->addEdge(-1, 4, 1, 5);
    g->addEdge(2, 1, 5, 9);
    g->addEdge(2, 1, 2, 6);
    g->addEdge(1, -2, 6, 10);
    g->addEdge(1, -3, 3, 7);
    g->addEdge(1, 1, 7, 11);
    
    node_list=g->getNodeList();
    weight1=g->getWeight1();
    weight2=g->getWeight2();

    int final_id;
    
    for(int i=0;i<VexNum;i++){
        label *new_label=new label(node_list[i]);
        if(i==0){
            //每个点的初始化
            new_label->_totApples=1;
            new_label->_totHoney=1;
        }
        node_list[i]->setLabel(new_label);
        if(i>=4){
            node_list[i]->pushNewAdjNodes(node_list[i-4]);
        }
        if(i%4!=0){
            node_list[i]->pushNewAdjNodes(node_list[i-1]);
        }
    }
    
    while(start<3){
        for(int i=start;i<=2;i++){
            final_id=i*4+start;
            dealNode(final_id,false);
        }
        for(int i=start;i<=3;i++){
            final_id=i+start*4;
            dealNode(final_id,false);
        }
        start++;
    }
    
    cout<<"按照A>B计算路径（有两条）"<<endl;
    g->printNodes();
    printPath();
    
    for(int i=0;i<VexNum;i++){
        label *new_label=node_list[i]->getLabel();
        if(i==0){
            new_label->_totApples=1;
            new_label->_totHoney=1;
        }else{
            new_label->_totApples=0;
            new_label->_totHoney=0;
        }
        node_list[i]->setPreNode(NULL);
    }
    start=0;
    
    while(start<3){
        for(int i=start;i<=2;i++){
            final_id=i*4+start;
            dealNode(final_id,true);
        }
        for(int i=start;i<=3;i++){
            final_id=i+start*4;
            dealNode(final_id,true);
        }
        start++;
    }
    cout<<"按照A<B计算路径（有两条，在1_2/2_1中间）"<<endl;
    g->printNodes();
    printPath();
    return 0;
}

void printPath(){
    node *current_node=node_list[11];
    vector<node *> route;
    int edges_num=1;
    while(current_node->getPreNode()!=NULL){
        edges_num++;
        route.push_back(current_node);
        current_node=current_node->getPreNode();
    }
    route.push_back(node_list[0]);
    
    cout<<"路径:"<<endl;
    for(int i=edges_num-1;i>=0;i--){
        cout<<route[i]->getName()<<endl;
    }
}

void dealNode(int final_id,bool AB){
    vector<node* > pre_node_list;
    pre_node_list=node_list[final_id]->getNewAdjNodes();
    
    if(pre_node_list.size()==1){
        node_list[final_id]->setPreNode(pre_node_list[0]);
    }
    
    if(pre_node_list.size()==2){
        label *label1=pre_node_list[0]->getLabel();
        label *label2=pre_node_list[1]->getLabel();
        if(AB){
            if(g->AdominateB(label1, label2)){
                node_list[final_id]->setPreNode(pre_node_list[0]);
            }else{
                node_list[final_id]->setPreNode(pre_node_list[1]);
            }
        }else{
            if(g->BdominateA(label1,label2)){
                node_list[final_id]->setPreNode(pre_node_list[1]);
            }else{
                node_list[final_id]->setPreNode(pre_node_list[0]);
            }
        }
    }
    
    node *pre_node=node_list[final_id]->getPreNode();
    label *current_label=node_list[final_id]->getLabel();
    if(pre_node!=NULL){
        label *pre_label=pre_node->getLabel();
        int pre_id=pre_node->getId();
        current_label->_totApples=pre_label->_totApples+weight1[pre_id][final_id];
        current_label->_totHoney=pre_label->_totHoney+weight2[pre_id][final_id];
    }
}
