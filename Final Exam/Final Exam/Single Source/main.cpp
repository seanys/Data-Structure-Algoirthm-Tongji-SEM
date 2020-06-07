//
//  main.cpp
//  Single Source
//
//  Created by Sean Yang on 2019/6/4.
//  Copyright © 2019 Sean Yang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#define INF 99999
#define V 5

using namespace std;

#include "node.h"
#include "edge.h"

vector<Node *> nodeList;
vector<Edge *> edgeList;
stack<int> queue;
void printNode();
void relax(int node1,int node2);
void addEdge(int node1,int node2,int weight);
void ini(int root);
int graphWeight[V][V];
void printGraphWeight();
void printEgde();
void printEgdeList();

int main(int argc, const char * argv[]) {
    //初始化所有的点
    for(int i=0;i<V;i++){
        Node *new_node=new Node();
        nodeList.push_back(new_node);
    }
    //初始化路径
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            graphWeight[i][j]=0;
        }
    }
    addEdge(0,1,10);
    addEdge(0,4,5);
    addEdge(1,2,1);
    addEdge(1,4,2);
    addEdge(2,3,4);
    addEdge(3,2,6);
    addEdge(3,0,7);
    addEdge(4,1,3);
    addEdge(4,2,9);
    addEdge(4,3,2);
    printNode();
    ini(0);//初始化root
    
    
    printEgdeList();
    printNode();
    
    return 0;
}

void printNode(){
    cout<<"输出节点"<<endl;
    for(int i=0;i<V;i++){
        cout<<i<<": distance "<<nodeList[i]->distance <<" parent "<<nodeList[i]->parent<<" color "<<nodeList[i]->color<<endl;
    }
}

//relax包括修改路径之类的
void relax(int node1,int node2){
    int pre=nodeList[node1]->distance+graphWeight[node1][node2];
    int next=nodeList[node2]->distance;
    if(pre<next){
        nodeList[node2]->distance=pre;
        nodeList[node2]->parent=node1;
    }
}

void addEdge(int node1,int node2,int weight){
    Edge *new_edge=new Edge(node1,node2,weight);
    edgeList.push_back(new_edge);
    graphWeight[node1][node2]=weight;
}

void ini(int root){
    nodeList[root]->distance=0;
}


void printGraphWeight(){
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cout<<graphWeight[i][j]<<" ";
        }
        cout<<endl;
    }
}

void printEgde(){
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(graphWeight[i][j]!=0){
                cout<<i<<"-"<<j<<":"<<graphWeight[i][j]<<endl;
            }
        }
    }
}

void printEgdeList(){
    cout<<"输出所有的边"<<endl;
    for(auto edge=edgeList.begin();edge!=edgeList.end();edge++){
        cout<<(*edge)->node1<<"-"<<(*edge)->node2<<":"<<(*edge)->weight<<endl;
    }
}
