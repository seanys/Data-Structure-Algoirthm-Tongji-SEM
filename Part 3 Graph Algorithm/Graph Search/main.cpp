//
//  main.cpp
//  Graph Search
//
//  Created by Sean Yang on 2019/4/28.
//  Copyright © 2019 Sean Yang. All rights reserved.
//

#include <iostream>
#include <queue>
#include <list>
#include <ctime>

using namespace std;

class GRAPH{
public:
    int V;
    list<int> *adj;
    //生成随机图
    GRAPH(int V){
        srand((unsigned)time(NULL));
        this->V=V;
        adj = new list<int>[V];//需要定义其长度
        for(int i=0;i<V;i++){
            int adj_num=rand()%(V-5);
            adj[i].push_back(adj_num);
            for(int j=0;j<adj_num;j++){
                while(true){
                    int adj_v=rand()%V;
                    if(adj_v!=i){
                        bool not_exit=true;
                        list<int>::iterator k;
                        for(k=adj[i].begin();k!=adj[i].end();++k){
                            if(*k==adj_v){
                                not_exit=false;
                            }
                        }
                        if(not_exit){
                            adj[i].push_back(adj_v);
                            break;
                        }
                    }
                }
                
            }
        }
    }
    ~GRAPH(){
        delete adj;
    }
    void TravleGraph(){
        for(int i=0;i<V;i++){
            list<int>::iterator k;
            cout<<i<<"的邻边：";
            //begin和end应该指向都是空的
            bool begin_not=true;
            for(k=adj[i].begin();k!=adj[i].end();++k){
                if(begin_not){
                    begin_not=false;
                }else{
                    cout<<",";
                }
                cout<<*k;
            }
            cout<<endl;
        }
    }
    
    void BFS(int start){
        int status[V],d[V],f[V];
        for(int i=0;i<V;i++){
            status[i]=d[i]=0;
            f[i]=-2;
        }
        queue<int> myqueue;
        cout<<"开始执行BFS:"<<endl;
        myqueue.push(start);
        status[start]=1;
        f[start]=-1;
        int t;
        while (!myqueue.empty()) {
            t=myqueue.front();
            myqueue.pop();
            list<int>::iterator k;
            for(k=adj[t].begin();k!=adj[t].end();++k){
                if(status[*k]==0){
                    status[*k]=1;
                    d[*k]=d[t]+1;
                    f[*k]=t;
                    myqueue.push(*k);
                }
            }
            status[t]=2;
        }
        BFS_travel(d,f);
    }
    
    void BFS_travel(int d[],int f[]){
        for(int i=0;i<V;i++){
            cout<<"第"<<i<<"个点在第"<<d[i]<<"层，父节点为"<<f[i]<<endl;
        }
    }
    
    
    
    void DFS(){
        int status[V];
        int d[V],f[V],father[V];
        cout<<"开始执行DFS:"<<endl;
        int time=0;
        cout<<"V："<<V<<endl;
        for(int i=0;i<V;i++){
            d[i]=f[i]=status[i]=0;
            father[i]=-1;
        }
        for(int i=0;i<V;i++){
            if(status[i]==0){
                cout<<"最外层检索"<<endl;
                DFS_until(status,d,f,i,time,father);
            }
        }
        DFS_travel(d,f,father);
    }
    
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
    
    void DFS_travel(int d[],int f[], int father[]){
        for(int i=0;i<V;i++){
            cout<<"第"<<i<<"个点的dtime为"<<d[i]<<"；ftime为"<<f[i]<<"；父节点为"<<father[i]<<endl;
        }
    }
    
    void Topology(){
        srand((unsigned)time(NULL));
        int status[V];
        int d[V],f[V],father[V];
        cout<<"开始执行topology排序:"<<endl;
        int record_time=0;
        cout<<"V："<<V<<endl;
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
        TopologyTravel(f);
    }
    void TopologyTravel(int f[]){
        int max_index=0, count=0, max_travel[V];
        for(int i=0; i<V; i++){
            max_travel[i]=0;
        }
        cout<<"拓扑排序顺序:"<<endl;
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
            cout<<max_index<<",";
        }
        cout<<endl;
    }
    
    void Tarjan(){
        int status[V],new_status[V];
        int d[V],f[V],father[V];
        cout<<"Tarjon的初始DFS......"<<endl;
        int time=0;
        for(int i=0;i<V;i++){
            d[i]=f[i]=status[i]=new_status[i]=0;
            father[i]=-1;
        }
        for(int i=0;i<V;i++){
            if(status[i]==0){
                DFS_until(status,d,f,i,time,father);
            }
        }
        list<int> *new_adj;
        new_adj=new list<int>[V];
        for(int i=0;i<V;i++){
            list<int>::iterator k;
            for(k=adj[i].begin();k!=adj[i].end();++k){
                new_adj[*k].push_back(i);
            }
        }
        int max_index=0;
        cout<<"强连通结果输出："<<endl;
        while(true){
            bool finish=true;
            for(int i=0;i<V;i++){
                if(new_status[i]==0){
                    finish=false;
                }
            }
            if(finish){
                break;
            }else{
                cout<<"未完成"<<endl;
            }
            
            for(int i=0;i<V;i++){
                max_index=-1;
                for(int i=0;i<V;i++){
                    if(max_index==-1){
                        if(new_status[i]==0)
                            max_index=i;
                        else
                            continue;
                    }
                    if(new_status[i]==0&&f[i]>f[max_index]){
                        max_index=i;
                    }else{
                        continue;
                    }
                }
                if(max_index<0){
                    break;
                }else{
//                    cout<<"起始位置："<<max_index<<endl;
                    cout<<"组合：";
                    Tarjan_DFS_until(new_status,new_adj,max_index);
                    cout<<endl;
                }
            }
        }
        
    }
    
    void Tarjan_DFS_until(int new_status[],list<int> *new_adj,int i){
        cout<<i<<",";
        new_status[i]=1;
        list<int>::iterator k;
        for(k=new_adj[i].begin();k!=new_adj[i].end();++k){
            if(new_status[*k]==0){
                new_status[*k]=1;
                cout<<*k<<",";
//                Tarjan_DFS_until(new_status,new_adj,*k);
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    GRAPH *mygraph=new GRAPH(10);
    mygraph->TravleGraph();
    mygraph->DFS();
    mygraph->BFS(1);
    mygraph->Topology();
    mygraph->Tarjan();
    return 0;
}
