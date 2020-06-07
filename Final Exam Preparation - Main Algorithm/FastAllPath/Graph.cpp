#include "Graph.h"

Graph::Graph(int vexNum) 
{

	for (int i = 0; i < vexNum; i++)
	{
		node * z = new node();
		_nodeList.push_back(z);
	}

	_weight.resize(vexNum);
	for (int i = 0; i < _weight.size(); i++)
	{
		_weight[i].resize(vexNum);
		for (int j = 0; j < _weight[i].size(); j++)
		{
			_weight[i][j] = INFI;
		}
	}
	for (int i = 0; i < _weight.size(); i++)
	{
		_weight[i][i] = 0;
	}

	_parent.resize(vexNum);
	for (int i = 0; i < _parent.size(); i++)
	{
		_parent[i].resize(vexNum);
		for (int j = 0; j < _parent[i].size(); j++)
		{
			_parent[i][j] = -1;
		}
	}

}
Graph::~Graph()
{
}

void Graph::addEdge(int w, int node1, int node2) 
{
	edge *e = new edge(w,_nodeList[node1],_nodeList[node2]);
	_weight[node1][node2] = w;
	_parent[node1][node2] = node1;
}

void Graph::printPath(vector<vector<int>> L)
{
	for (int i = 0;i < _nodeList.size();i++)
	{
		for (int j = 0;j < _nodeList.size();j++)
		{
			if (i != j)
			{
				cout << "点" << i << "到点" << j << "的最短路径长：" << L[i][j] << " "  ;
				print(i, j, _parent[i][j]);

			    cout << endl;
			}

		}
	}

}



//vector<vector<int>> Graph::FastAllPath(vector<vector<int>> L)
//{
//    return;
//}
//
//vector<vector<int>> Graph::EXTEND_SHORTEST_PATH(vector<vector<int>> L)
//{
//    return;
//}

int Graph::MinDis(int i, int j, vector<vector<int>> L)
{
    return 0;
}


void Graph::print(int i,int j,int z) 
{
    return;
}



