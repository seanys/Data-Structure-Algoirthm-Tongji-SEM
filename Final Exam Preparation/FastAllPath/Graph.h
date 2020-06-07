
#include "edge.h"

class Graph
{
private:
	vector<node*> _nodeList;
	vector<edge*> _edgeList;


	vector<vector<int>> _weight;
	vector<vector<int>> _parent;


public:
	Graph(int _vexNum);
	~Graph();

	void addEdge(int w, int node1, int node2);

	vector<vector<int>> getWeight() { return _weight; }
	void printPath(vector<vector<int>> L);

//������Ҫд�ĺ���
	vector<vector<int>> FastAllPath(vector<vector<int>> L);
	vector<vector<int>> EXTEND_SHORTEST_PATH(vector<vector<int>> L);
	int MinDis(int i, int j, vector<vector<int>> L);//�õ�min{l+w}
	void print(int i, int j, int z);//Ҫ��д��·���켣

};
