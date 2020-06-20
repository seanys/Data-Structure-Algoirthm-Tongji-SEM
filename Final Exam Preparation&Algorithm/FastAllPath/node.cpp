#include "node.h"
int node::_countId = 0;

node::node()
{
	_id = _countId++;
	_dis = INFI;
	_prevNode = NULL;
}

node::~node()
{
}
