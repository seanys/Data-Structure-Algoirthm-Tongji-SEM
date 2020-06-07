#include<iostream>
#include<vector>
using namespace std;

const int MAX=10001;

int Stop;//栈中的元素个数
int cnt;//记录连通分量的个数
int visitNum;//记录遍历的步数
int DFN[MAX]; //记录节点u第一次被访问时的步数
int LOW[MAX]; //记录与节点u和u的子树节点中最早的步数
bool instack[MAX];//记录节点u是否在栈中
int Stap[MAX];//栈
int Belong[MAX];//记录每个节点属于的强连通分量编号

int N;//节点个数

vector<int> tree[MAX];

void tarjan(int i)
{
    int j;
    DFN[i]=LOW[i]=++visitNum;
    instack[i]=true;
    Stap[++Stop]=i;//将当前节点压入栈中
    for (unsigned k=0;k<tree[i].size();k++)
    {
        j=tree[i][k];
        if (!DFN[j]) //j还没有被访问过
        {
            tarjan(j);
            //父节点是子节点的子节点
            if (LOW[j]<LOW[i])
                LOW[i]=LOW[j];
        }
        //与j相连,但是j已经被访问过,且还在栈中
        //用子树节点更新节点第一次出现的时间
        else if (instack[j] && DFN[j]<LOW[i])
            LOW[i]=DFN[j];
    }
    //节点i是强连通分量的根
    if (DFN[i]==LOW[i])
    {
        cnt++;
        //输出找到的强连通分量
        cout<<"连通分量"<<cnt<<": ";
        //退栈,直至找到根为止
        do
        {
            j=Stap[Stop--];
            instack[j]=false;
            cout<<j<<" ";
            Belong[j]=cnt;
        }
        while (j!=i);
        cout<<endl;
    }
}
void solve()
{
    Stop=cnt=visitNum=0;
    memset(DFN,0,sizeof(DFN));
    for (int i=1;i<=N;i++)
        if (!DFN[i])//有可能图不是连通图
            tarjan(i);
}

int main()
{
    N=6;
    tree[1].push_back(3);
    tree[1].push_back(2);
    tree[2].push_back(4);
    tree[3].push_back(5);
    tree[3].push_back(4);
    tree[4].push_back(1);
    tree[4].push_back(6);
    tree[5].push_back(6);
    solve();
    for(int i=1;i<=N;i++)
        cout<<Belong[i]<<" ";
    cout<<endl;
    return 0;
}  
