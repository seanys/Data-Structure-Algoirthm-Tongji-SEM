
#include<vector>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define INFI 999999

class edge;
class node
{
private:
	int _id;
	int _dis;
	node * _prevNode;
	vector<node *> _adjNodes;

	static int _countId;

public:


	node();
	~node();
	vector<node *> getAdjNodes() { return _adjNodes; }

};

