//
//  main.cpp
//  Shortest Path
//
//  Created by Sean Yang on 2019/5/11.
//  Copyright © 2019 Sean Yang. All rights reserved.
//

#include <iostream>
#include <stack>
#include <list>
#include <algorithm>
#define INFINITE 2147483647
#define ArrayLength 6
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
    void addEdgeaddEdge(int v, int w , int cost)
    {
        adj[v].push_back(w);
        pre_list[w].push_back(v);
        GraphCost[v][w]=cost;
    };
    void InitailizeSingleSource(int root){
        for(int i=0;i<ArrayLength;i++){
            E[i].pre=NULL;
            E[i].d=INFINITE;
        }
        E[root].d=0;
    };
    void BellmanFordRelax(int pre,int next){
        if(E[next].d>GraphCost[pre][next]+E[pre].d){
            E[next].d=GraphCost[pre][next]+E[pre].d;
            E[next].pre=pre;
            BellmanFord(next);
        }
    };
    void BellmanFord(int root){
        list<int>::iterator j;
        for (j = adj[root].begin(); j != adj[root].end(); ++j){
            BellmanFordRelax(root, *j);
        }
    };
    void addEdge(int v, int w, int cost)
    {
        adj[v].push_back(w);
        GraphCost[v][w]=cost;
    };
    void travelEdge(int root){
        list<int>::iterator i;
        cout<<"point "<<root<<",parent "<<E[root].pre<<",distance "<<E[root].d<<endl;
        for (i = adj[root].begin(); i != adj[root].end(); ++i){
            if(E[*i].pre==root){
                travelEdge(*i);
            }
        }
    }
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
        srand((unsigned)time(NULL));
        int status[V];
        int d[V],f[V],father[V];
        int record_time=0;
        for(int i=0;i<V;i++){
            d[i]=f[i]=status[i]=0;
            father[i]=-1;
        }
        while(true){
            bool finish=true;
            for(int i=0;i<V;i++){
                if(status[i]==0){
                    finish=false;
                }
            }
            if(finish){
                break;
            }
            int t;
            while(true){
                t=rand()%V;
                if(status[t]==0)break;
            }
            DFS_until(status,d,f,t,record_time,father);
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
//    Graph g1(ArrayLength);
//
//    g1.addEdge(0, 1 , 6);
//    g1.addEdge(0, 4 , 7);
//    g1.addEdge(1, 3 , -4);
//    g1.addEdge(1, 2 , 5);
//    g1.addEdge(1, 4 , 8);
//    g1.addEdge(2, 1 , -2);
//    g1.addEdge(3, 0 , 2);
//    g1.addEdge(3, 2 , 7);
//    g1.addEdge(4, 2 , -3);
//    g1.addEdge(4, 3 , 9);
//
//    g1.InitailizeSingleSource(0);
//    g1.BellmanFord(0);
//    g1.travelEdge(0);
    
    Graph g2(ArrayLength);
    
    g2.addEdge(1, 0 , 5);
    g2.addEdge(1, 2 , 3);
    g2.addEdge(0, 2 , 2);
    g2.addEdge(0, 3 , 6);
    g2.addEdge(2, 3 , 7);
    g2.addEdge(2, 5 , 4);
    g2.addEdge(2, 4 , 2);
    g2.addEdge(3, 5 , -1);
    g2.addEdge(3, 4 , 1);
    g2.addEdge(5, 4 , -2);
    
    
    g2.DAG();
    
    return 0;
}
