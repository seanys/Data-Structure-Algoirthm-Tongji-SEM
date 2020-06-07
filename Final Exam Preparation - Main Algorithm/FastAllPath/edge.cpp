#include "edge.h"


edge::edge(int w, node * node1, node * node2)
{
	_w = w;
	_node1 = node1;
	_node2 = node2;
	node1->getAdjNodes().push_back(node2);
}

edge::~edge()
{
}