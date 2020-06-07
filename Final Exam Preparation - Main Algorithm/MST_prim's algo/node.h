#pragma once
#include<vector>
using namespace std;

class edge;
class node
{
public:
	int id;
	int key;
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
	key = 999999;
	prevNode = NULL;
}

node::~node()
{
}
