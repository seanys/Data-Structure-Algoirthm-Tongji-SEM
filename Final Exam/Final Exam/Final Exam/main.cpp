//
//  main.cpp
//  Final Exam
//
//  Created by Sean Yang on 2019/6/3.
//  Copyright © 2019 Sean Yang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;
#define INF 99999
#define V 6

#include "node.h"
#include "graph.h"

vector<Node *>nodeList;
vector<Edge *>edgeList;

//输出部分
void printMid();
void printGraph();
//初始化部分
void iniMid();
void copyArray();

int Mid[V][V];

int main(int argc, const char * argv[]) {
    //初始化数据
    iniMid();
    //输出parents
    printGraph();
    printMid();

    
    //输出parents
    printGraph();
    printMid();
    return 0;
}

void iniMid(){
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            Mid[i][j]=-1;
        }
    }
}

void printMid(){
    cout<<"输出mid矩阵"<<endl;
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(Mid[i][j]==INF)
                cout<<"INF"<<" ";
            else
                cout<<Mid[i][j]<<" ";
        }
        cout<<endl;
    }
}

void printGraph(){
    cout<<"输出Graph"<<endl;
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(Graph[i][j]==INF)
                cout<<"INF"<<" ";
            else
                cout<<Graph[i][j]<<" ";
        }
        cout<<endl;
    }
}
