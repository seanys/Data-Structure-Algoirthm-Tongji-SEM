//
//  main.cpp
//  Bellman Ford
//
//  Created by Sean Yang on 2019/5/13.
//  Copyright © 2019 Sean Yang. All rights reserved.
//

#include <iostream>
#include <stack>
#include <list>
#include <algorithm>
#define INFINITE 2147483647
#define ArrayLength 9
using namespace std;

struct node
{
    int d;
    int pre;
}E[ArrayLength];

class Graph
{
    int V;
    list<int> *adj;
    list<int> *pre_list;
    int GraphCost[ArrayLength][ArrayLength]={INFINITE};
    int DAGroot=0;
public:
    Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    };
    void InitailizeSingleSource(int root){
        for(int i=0;i<ArrayLength;i++){
            E[i].pre=NULL;
            E[i].d=INFINITE;
        }
        E[root].d=0;
    };
    void Relax(int pre,int next){
        if(E[pre].d<INFINITE){
            if(E[next].d>GraphCost[pre][next]+E[pre].d){
                E[next].d=GraphCost[pre][next]+E[pre].d;
                E[next].pre=pre;
            }
        }
    };
    bool BellmanFord(){
        for(int i=0;i<100;i++){
            for(int j=0;j<=ArrayLength-1;j++){
                list<int>::iterator k;
                for (k = adj[j].begin(); k!= adj[j].end(); ++k){
                    Relax(j, *k);
                }
            }
        }
        //判断是否存在无限环
        for(int i=0;i<ArrayLength+2;i++){
            for(int j=0;j<ArrayLength;j++){
                list<int>::iterator k;
                for (k = adj[j].begin(); k!= adj[j].end(); ++k){
                    if(E[*k].d>GraphCost[j][*k]+E[j].d){
                        return false;
                    }
                }
            }
        }
        return true;
    };
    void addEdge(int v, int w, int cost)
    {
        adj[v].push_back(w);
        GraphCost[v][w]=cost;
    };
    void travelEdge(){
        for(int i=0;i<ArrayLength;i++){
            cout<<"point "<<i<<",parent "<<E[i].pre<<",distance "<<E[i].d<<endl;
        }
    }
    void printPath(int root,string before){
        bool print=true;
        for(int i=0;i<ArrayLength;i++){
            if(E[i].pre==root&&i!=root){
                before=before+"-"+to_string(i);
                printPath(i,before);
                print=false;
            }
        }
        if(print){
            cout<<before<<endl;
        }
    }
    
    void printChoosen(){
        for(int i=0;i<ArrayLength;i++){
            list<int>::iterator k;
            for(k=adj[i].begin();k!=adj[i].end();++k){
                if(E[*k].pre==i){
                    cout<<i<<"-"<<*k<<endl;
                }
            }
        }
    }
    
};

int main(int argc, const char * argv[]) {
    Graph g1(ArrayLength);
    
    g1.addEdge(0, 1 , 4);
    g1.addEdge(1, 2 , 8);
    g1.addEdge(2, 3 , 7);
    g1.addEdge(3, 4 , 9);
    g1.addEdge(5, 4 , 10);
    g1.addEdge(6, 5 , 2);
    g1.addEdge(7, 6 , 1);
    g1.addEdge(0, 7 , 8);
    g1.addEdge(1, 7 , 11);
    g1.addEdge(8, 2 , 2);
    g1.addEdge(7, 8 , 7);
    g1.addEdge(8, 6 , 6);
    g1.addEdge(2, 5 , 4);
    g1.addEdge(3, 5 , 14);
    g1.addEdge(8, 5 , -1);
    g1.addEdge(7, 3 , -2);

    g1.InitailizeSingleSource(0);
    if(g1.BellmanFord()){
        g1.travelEdge();
        g1.printPath(0,"0");
    }else{
        cout<<"存在负环"<<endl;
    }
    

    return 0;
}
