#pragma once
#include<vector>
using namespace std;

class node;
class edge
{
public:
	int id;
	int weight;
	node * Node1;
	node * Node2;

	static int countId;

	edge(int w, node * node1, node * node2);
	~edge();

};

int edge::countId = 0;

edge::edge(int w, node * node1, node * node2)
{
	id = countId++;
	weight = w;
	Node1 = node1;
	Node2 = node2;
	node1->adjNodes.push_back(node2);
}

edge::~edge()
{
}


