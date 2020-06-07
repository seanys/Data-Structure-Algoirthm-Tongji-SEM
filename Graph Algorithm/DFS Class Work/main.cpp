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
        adj[0].push_back(1);
        adj[0].push_back(2);
        adj[0].push_back(3);
        adj[1].push_back(4);
        adj[1].push_back(5);
        adj[1].push_back(6);
        adj[2].push_back(6);
        adj[2].push_back(7);
        adj[3].push_back(5);
        adj[3].push_back(9);
        adj[4].push_back(5);
        adj[5].push_back(4);
        adj[5].push_back(8);
        adj[6].push_back(9);
        adj[7].push_back(8);
        adj[8].push_back(4);
        adj[9].push_back(8);

    }
    ~GRAPH(){
        delete adj;
    }
//    void TravleGraph(){
//        for(int i=0;i<V;i++){
//            list<int>::iterator k;
//            cout<<i<<"的邻边：";
//            //begin和end应该指向都是空的
//            bool begin_not=true;
//            for(k=adj[i].begin();k!=adj[i].end();++k){
//                if(begin_not){
//                    begin_not=false;
//                }else{
//                    cout<<",";
//                }
//                cout<<*k;
//            }
//            cout<<endl;
//        }
//    }
    
    void DFS(){
        int status[V];
        int d[V],f[V],father[V];
        cout<<"开始执行DFS:"<<endl;
        int time=0;
        for(int i=0;i<V;i++){
            d[i]=f[i]=status[i]=0;
            father[i]=-1;
        }
        for(int i=0;i<V;i++){
            if(status[i]==0){
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
            int temp=i;
            string out="";
            cout<<"该节点的路径:";
            while(true){
                if(father[temp]==-1){
                    break;
                }
                out=out+"-"+(to_string(temp));
                temp=father[temp];
            }
            out="0"+out;
            cout<<out<<endl;
        }
    }
    
};

int main(int argc, const char * argv[]) {
    GRAPH *mygraph=new GRAPH(10);
//    mygraph->TravleGraph();
    mygraph->DFS();
    return 0;
}
