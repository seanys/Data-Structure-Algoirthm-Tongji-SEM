#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define INFINITE 0xFFFFFFFF
#define VertexData int  //顶点数据
#define UINT int
#define vexCounts 9  //顶点数量

//Prim算法中的辅助信息Node，并且定义node数组closedge[]
struct node
{
    VertexData data;   //一个点的先驱用data表示
    unsigned int lowestcost;
}closedge[vexCounts];

//原始图的边信息
typedef struct
{
    VertexData u;
    VertexData v;
    unsigned int cost;  //边的代价
}Arc;

//邻接矩阵表示法
void AdjMatrix(unsigned int adjMat[vexCounts][vexCounts])
{
    //初始化邻接矩阵，所有的值默认为-1
    for (int i = 0; i < vexCounts; i++){
        for (int j = 0; j < vexCounts; j++)
        {
            adjMat[i][j] = INFINITE;
        }
    }
    //进行边的赋值
    adjMat[0][1] = 4;
    adjMat[1][2] = 8;
    adjMat[3][2] = 7;
    adjMat[3][4] = 9;
    adjMat[4][5] = 10;
    adjMat[5][6] = 2;
    adjMat[7][6] = 1;
    adjMat[0][7] = 8;
    adjMat[0][2] = 6;
    adjMat[1][7] = 11;
    adjMat[2][8] = 2;
    adjMat[7][8] = 7;
    adjMat[6][8] = 6;
    adjMat[2][5] = 4;
    adjMat[3][5] = 14;

    for (int i = 0; i < vexCounts; i++){
        for (int j = 0; j < vexCounts; j++)
        {
            if(adjMat[i][j]<INFINITE&&i>j){
                adjMat[j][i] = adjMat[i][j];
                adjMat[i][j] = INFINITE;
            }
        }
    }
}

//返回最小代价边
int Minmum(struct node * closedge)
{
    unsigned int min = INFINITE;
    int index = -1;
    for (int i = 0; i < vexCounts;i++)
    {
        if (closedge[i].lowestcost < min && closedge[i].lowestcost !=0)
        {
            min = closedge[i].lowestcost;
            index = i;
        }
    }
    return index;
}

void MiniSpanTree_Prim(unsigned int adjMat[vexCounts][vexCounts], VertexData s)
{
    
    //初始化整体数组
    for (int i = 0; i < vexCounts;i++)
    {
        closedge[i].lowestcost = INFINITE;
    }
    
    //从顶点s开始
    closedge[s].data = s;
    closedge[s].lowestcost = 0;
    
    //初始化辅助数组
    for (int i = 0; i < vexCounts;i++)
    {
        if (i != s)
        {
            closedge[i].data = s;
            closedge[i].lowestcost = adjMat[s][i]<INFINITE ? adjMat[s][i] : (adjMat[i][s]<INFINITE ? adjMat[i][s]:INFINITE ) ;
        }
    }
    
    //n-1条边时退出
    for (int e = 1; e <= vexCounts -1; e++)
    {
        int k = Minmum(closedge);  //选择最小代价边
        cout << closedge[k].data << "--" << k << endl;//加入到最小生成树
        closedge[k].lowestcost = 0; //代价重置为0
        
        //更新v中顶点最小代价边信息，添加最小边
        for (int i = 0; i < vexCounts;i++)
        {
            if ( adjMat[k][i] < closedge[i].lowestcost || adjMat[i][k] < closedge[i].lowestcost)
            {
                closedge[i].data = k;
                closedge[i].lowestcost = adjMat[k][i]<INFINITE ? adjMat[k][i] : (adjMat[i][k]<INFINITE ? adjMat[i][k]:INFINITE ) ;
            }
        }
    }
}

void ReadArc(unsigned int  adjMat[vexCounts][vexCounts],vector<Arc> &vertexArc) //保存图的边代价信息
{
    Arc * temp = NULL;
    for (int i = 0; i < vexCounts;i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (adjMat[j][i]!=INFINITE)
            {
                temp = new Arc;
                temp->u = i;
                temp->v = j;
                temp->cost = adjMat[j][i];
                vertexArc.push_back(*temp);
            }
        }
    }
}

//比较AB，用于向量的排序
bool compare(Arc  A, Arc  B)
{
    return A.cost < B.cost ? true : false;
}

//vector<vector<VertexData> > &Tree 是一个二维数组
bool FindTree(VertexData u, VertexData v,vector<vector<VertexData> > &Tree)
{
    unsigned int index_u = INFINITE;
    unsigned int index_v = INFINITE;
    
    //检查u,v分别属于哪颗树
    for (unsigned int i = 0; i < Tree.size();i++)
    {
        if (find(Tree[i].begin(), Tree[i].end(), u) != Tree[i].end())
            index_u = i;
        if (find(Tree[i].begin(), Tree[i].end(), v) != Tree[i].end())
            index_v = i;
    }
    
    //u,v不在一颗树上，合并两颗树
    if (index_u != index_v)
    {
        for (unsigned int i = 0; i < Tree[index_v].size();i++)
        {
            Tree[index_u].push_back(Tree[index_v][i]);
        }
        Tree[index_v].clear();
        return true;
    }
    return false;
}

void MiniSpanTree_Kruskal(unsigned int adjMat[vexCounts][vexCounts])
{
    vector<Arc> vertexArc;
    ReadArc(adjMat, vertexArc);//读取边信息，输入vertexArc向量边
    sort(vertexArc.begin(), vertexArc.end(), compare);//边按从小到大排序
    vector<vector<VertexData> > Tree(vexCounts); //6棵独立树
    for (unsigned int i = 0; i < vexCounts; i++)
    {
        Tree[i].push_back(i);  //初始化6棵独立树的信息
    }
    for (unsigned int i = 0; i < vertexArc.size() ; i++)//依次从小到大取最小代价边
    {
        VertexData u = vertexArc[i].u;
        VertexData v = vertexArc[i].v;
        if (FindTree(u, v, Tree))//检查此边的两个顶点是否在一颗树内
        {
            cout << u << "--" << v << endl;//把此边加入到最小生成树中
        }
    }
}

int main()
{
    unsigned int  adjMat[vexCounts][vexCounts] = { 0 };
    AdjMatrix(adjMat);   //邻接矩阵
//    cout<<"——————————Prim8——————————"<<endl;
//    MiniSpanTree_Prim(adjMat,8);
    cout<<"——————————Prim0——————————"<<endl;
    MiniSpanTree_Prim(adjMat,0);
//    cout<<"——————————Kruskal——————————"<<endl;
//    MiniSpanTree_Kruskal(adjMat);//Kruskal算法
    return 0;
}
