#pragma once
#include<vector>
using namespace std;

class edge;
class node
{
public:
	int id;
	int dis;
	node * prevNode;
	vector<node *> adjNodes;

	static int countId;

	node();
	~node();

};

int node::countId = 0;

node::node()
{
	id = countId++;
	dis = 999999;
	prevNode = NULL;

}

node::~node()
{
}

