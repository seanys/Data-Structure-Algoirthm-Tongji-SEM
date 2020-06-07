#pragma once
#include<vector>
using namespace std;

class edge;
class node
{
public:
	int id;
	vector<node *> nodeSet;

	static int countId;

	node();
	~node();

};

int node::countId = 0;

node::node()
{
	id = countId++;
	nodeSet.push_back(this);

}

node::~node()
{
}
