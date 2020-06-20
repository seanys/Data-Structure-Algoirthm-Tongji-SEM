
#include "node.h"

class edge
{
private:
	int _id;
	int _w;
	node * _node1;
	node * _node2;
public:
	edge(int w, node * node1, node * node2);
	~edge();

};





