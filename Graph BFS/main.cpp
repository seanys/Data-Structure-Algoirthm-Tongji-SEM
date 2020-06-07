#include<iostream>
#include <list>

using namespace std;


class Graph
{
    int V;  //G的边对象
    list<int> *adj;   //
public:
    Graph(int V);  //graph函数
    void addEdge(int v, int w);  //增加边
    void BFS(int s);  //bfs函数
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::BFS(int s)
{
    bool *visited = new bool[V];
    int *d = new int[V];
    //设置所有的节点为未访问状态
    for(int i = 0; i < V; i++){
        visited[i] = false;
        d[i]=0;
    }
    //设置root为访问节点，设立一个queue
    list<int> queue;
    visited[s] = true;
    queue.push_back(s);
    list<int>::iterator i;
    
    while(!queue.empty())
    {
        //处理s为queue的
        s = queue.front();
        cout << "s:"<<s <<" ";;
        cout << "根据d[*s]求距离为"<<d[s];
        queue.pop_front();
        //进行边界逐一检索
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            //如果未被检索，则push back
            if (!visited[*i])
            {
                d[*i]=d[s]+1;
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
        cout<<endl;
    }
}

int main()
{
    Graph g(10);
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

    cout<<endl<<"以0为起点进行检索输出："<<endl;
    g.BFS(0);

    
    return 0;
}
