//
//  main.cpp
//  BFS
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
public:
    GRAPH(int V){
        this->V=V;
        adj=new list<int>[V];
    }
    void addEdge(int v,int w){
        adj[v].push_back(w);
    }
    void BFS(int s){
        bool visited[V];
        int d[V];
        for(int i=0;i<V;i++){
            visited[i]=false;
            d[i]=0;
        }
        list<int> queue;
        visited[0]=true;
        queue.push_back(0);
        list<int>::iterator i;
        
        while(!queue.empty()){
            s = queue.front();
            queue.pop_front();
            for(i = adj[s].begin(); i != adj[s].end(); ++i){
                if(!visited[*i]){
                    d[*i]=d[s]+1;
                    visited[*i] = true;
                    queue.push_back(*i);
                }
            }
        }
        cout<<endl;
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
    g.BFS(0);
    
    return 0;
}
