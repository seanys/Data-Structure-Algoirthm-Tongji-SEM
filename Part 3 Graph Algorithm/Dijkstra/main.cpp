//
//  main.cpp
//  Dijkstra
//
//  Created by Sean Yang on 2019/5/19.
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
    int status;  //status=0是没有选择过的，status=1是已经被选择出来了
}E[ArrayLength];

class Graph
{
    int V;
    list<int> *adj;
    int GraphCost[ArrayLength][ArrayLength]={INFINITE};
    int DAGroot=0;
public:
    Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    };
    void addEdge(int v, int w, int cost)
    {
        adj[v].push_back(w);
        GraphCost[v][w]=cost;
    };
    void InitailizeSingleSource(int root){
        for(int i=0;i<ArrayLength;i++){
            E[i].pre=-1;
            E[i].d=INFINITE;
            E[i].status=0;
        }
        E[root].d=0;
    };
    void Relax(int pre,int next){
        if(E[next].d>GraphCost[pre][next]+E[pre].d){
            E[next].d=GraphCost[pre][next]+E[pre].d;
            E[next].pre=pre;
        }
    };
    void travelEdge(){
        for(int i=0;i<ArrayLength;i++){
            cout<<"point "<<i<<",parent "<<E[i].pre<<",distance "<<E[i].d<<",status "<<E[i].status<<endl;
        }
    }
    int extractMin(){
        bool existMin=false;
        int index=0;
        for(int i=0;i<ArrayLength;i++){
            if(E[i].status==0&&existMin==false){
                existMin=true;
                index=i;
            }else if(E[i].status==0&&E[i].d<E[index].d){
                index=i;
            }else{
                continue;
            }
        }
        if(existMin){
            E[index].status=1;
            return index;
        }else{
            return -1;
        }
    }
    
    void Dijkstra(){
        InitailizeSingleSource(0);
        while(true){
            int min_index=extractMin();
            if(min_index>=0){
                list<int>::iterator k;
                for(k=adj[min_index].begin();k!=adj[min_index].end();++k){
                    Relax(min_index, *k);
                }
            }else{
                break;
            }
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
    
    Graph g2(ArrayLength);
    
    g2.addEdge(0, 1 , 4);
    g2.addEdge(1, 2 , 8);
    g2.addEdge(2, 3 , 7);
    g2.addEdge(3, 4 , 9);
    g2.addEdge(5, 4 , 10);
    g2.addEdge(6, 5 , 2);
    g2.addEdge(0, 7 , 8);
    g2.addEdge(1, 7 , 11);
    g2.addEdge(8, 2 , 2);
    g2.addEdge(7, 8 , 7);
    g2.addEdge(8, 6 , 6);
    g2.addEdge(2, 5 , 4);
    g2.addEdge(3, 5 , 14);
    g2.addEdge(4, 5 , 7);
    g2.addEdge(3, 2 , 3);
    g2.addEdge(8, 0 , 11);

    
    g2.Dijkstra();
    
    g2.travelEdge();
    g2.printPath(0,"0");
    g2.printChoosen();
    

}
