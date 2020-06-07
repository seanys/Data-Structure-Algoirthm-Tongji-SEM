//
//  main.cpp
//  DFS
//
//  Created by Sean Yang on 2019/4/22.
//  Copyright © 2019 Sean Yang. All rights reserved.
//

#include <iostream>
#include <list>

using namespace std;

class GRAPH{
private:
    int V;
    list<int> *adj;
    int *status,*d,*f,*pai;
    int time;
public:
    GRAPH(int V){
        this->V=V;
        adj=new list<int>[V];
        status=new int[V];
        d=new int[V];
        f=new int[V];
        pai=new int[V];
    }
    ~GRAPH(){
        delete status;
        delete d;
        delete f;
        delete pai;
    }
    void addEdge(int v,int w){
        adj[v].push_back(w);
    }
    void DFS(){
        for(int i=0;i<V;i++){
            status[i]=0;
            d[i]=0;
            f[i]=0;
            pai[i]=NULL;
        }
        time=0;
        
        for(int i=0;i<V;i++){
            if(status[i]==0){
                DFS_VISIT(i);
            }
        }
    }
    void DFS_VISIT(int u){
        time=time+1;
        d[u]=time;
        status[u]=1;
        list<int>::iterator j;
        for(j=adj[u].begin();j!=adj[u].end();++j){
            if(status[*j]==0){
                pai[*j]=u;
                DFS_VISIT(*j);
            }
        }
        status[u]=2;
        time=time+1;
        f[u]=time;
        cout<<"f["<<u<<"]:"<<f[u]<<endl;
        cout<<"d["<<u<<"]:"<<d[u]<<endl;
    }
};

int main(int argc, const char * argv[]) {
    GRAPH g(10);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 4);
    g.addEdge(1, 5);
    g.addEdge(2, 1);
    g.addEdge(2, 5);
    g.addEdge(3, 5);
    g.addEdge(3, 6);
    g.addEdge(4, 7);
    g.addEdge(5, 4);
    g.addEdge(5, 8);
    g.addEdge(6, 8);
    g.addEdge(6, 9);
    g.addEdge(7, 8);
    g.addEdge(8, 4);
    g.addEdge(9, 8);
    g.DFS();
    return 0;
}
