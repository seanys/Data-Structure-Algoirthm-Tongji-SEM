//
//  main.cpp
//  DAG Shortest Path
//
//  Created by Sean Yang on 2019/5/13.
//  Copyright © 2019 Sean Yang. All rights reserved.
//

#include <iostream>
#include <stack>
#include <list>
#include <algorithm>
#define INFINITE 2147483647
#define nagINFINITE -2147483647
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
        pre_list = new list<int>[V];
    };
    void addEdge(int v, int w, int cost)
    {
        adj[v].push_back(w);
        GraphCost[v][w]=cost;
    };
    void InitailizeSingleSource(int root){
        for(int i=0;i<ArrayLength;i++){
            E[i].pre=NULL;
            E[i].d=INFINITE;
        }
        E[root].d=0;
    };
    void Relax(int pre,int next){
        if(E[next].d>GraphCost[pre][next]+E[pre].d){
            E[next].d=GraphCost[pre][next]+E[pre].d;
            E[next].pre=pre;
        }
    };
    void DFS_until(int status[], int d[], int f[], int i, int &time,int father[]){
        status[i]=1;
        time++;
        d[i]=time;
        list<int>::iterator k;
        for(k=adj[i].begin();k!=adj[i].end();++k){
            if(status[*k]==0){
                father[*k]=i;
                DFS_until(status,d,f,*k,time,father);
            }
        }
        status[i]=2;
        time++;
        f[i]=time;
    }
    void DAG(){
        int status[V],d[V],f[V],father[V],record_time=0;
        for(int i=0;i<V;i++){
            d[i]=f[i]=status[i]=0;
            father[i]=-1;
        }
        while(true){
            int count=0;
            for(int i=0;i<ArrayLength;i++){
                if(status[i]==0){
                    DFS_until(status,d,f,i,record_time,father);
                    continue;
                }else{
                    count++;
                }
            }
            if(count==ArrayLength){
                break;
            }
        }
        InitailizeSingleSource(0);
        DAGTravel(f);
    }
    void DAGTravel(int f[]){
        int max_index=0, count=0, max_travel[V],begin_relax=false,topo_root=0;
        for(int i=0; i<V; i++){
            max_travel[i]=0;
        }
        while(count<V){
            max_index=-1;
            for(int i=0;i<V;i++){
                if(max_index==-1){
                    if(max_travel[i]==0)
                        max_index=i;
                    else
                        continue;
                }
                if(max_travel[i]==0&&f[i]>f[max_index]){
                    max_index=i;
                }else{
                    continue;
                }
            }
            max_travel[max_index]=1;
            count++;
            cout<<"point "<<max_index<<",parent "<<E[max_index].pre<<",distance "<<E[max_index].d<<endl;
            if(DAGroot==max_index){
                begin_relax=true;
            }
            if(count==1){
                topo_root=max_index;
            }
            if(begin_relax){
                list<int>::iterator k;
                for(k=adj[max_index].begin();k!=adj[max_index].end();++k){
                    Relax(max_index, *k);
                }
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    
    Graph g2(ArrayLength);
    
    g2.addEdge(0, 1 , 4);
    g2.addEdge(1, 2 , 8);
    g2.addEdge(2, 3 , 7);
    g2.addEdge(3, 4 , 9);
    g2.addEdge(5, 4 , 10);
    g2.addEdge(6, 5 , 2);
    g2.addEdge(7, 6 , 1);
    g2.addEdge(0, 7 , 8);
    g2.addEdge(1, 7 , 11);
    g2.addEdge(8, 2 , 2);
    g2.addEdge(7, 8 , 7);
    g2.addEdge(8, 6 , 6);
    g2.addEdge(2, 5 , 4);
    g2.addEdge(3, 5 , 14);
    g2.addEdge(8, 5 , -1);
    g2.addEdge(7, 3 , -2);
    
    g2.DAG();
}
