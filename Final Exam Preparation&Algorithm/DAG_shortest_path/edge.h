#include<vector>
using namespace std;

class node;
class edge
{
public:
	int id;
	int weight;
	node * Node1;  //±ßÆðµã
	node * Node2;   //±ßÖÕµã

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
}

edge::~edge()
{
}

