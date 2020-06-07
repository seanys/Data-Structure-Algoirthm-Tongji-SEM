#include<vector>
using namespace std;

class edge;
class node
{
public:
	int id;
	int shape;      //-1代表矩形，0代表三角，1代表圆
	int d_time;
	int f_time;
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
	shape = 1;
	d_time = 0;
	f_time = 0;
	dis = 999999;
	prevNode = NULL;

}

node::~node()
{
}
