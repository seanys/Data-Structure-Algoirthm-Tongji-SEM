#include<iostream>
#define SIZE 20

using namespace std;
class Node
{
private:
    int key;
    Node * parentNode;
    Node * leftNode;
    Node * rightNode;
    
public:
    Node(int value) :key(value), parentNode(NULL), leftNode(NULL), rightNode(NULL) {}
    
    void setKey(int value) { key = value; }
    int getKey() { return key; }
    
    void setParentNode(Node * node) { parentNode = node; }
    Node * getParentNode() { return parentNode; }
    
    void setLeftNode(Node * node) { leftNode = node; }
    Node * getLeftNode() { return leftNode; }
    
    void setRightNode(Node * node) { rightNode = node; }
    Node * getRightNode() { return rightNode; }
    
    void print() { cout << "key: " << key << endl; }
};


class Tree
{
private:
    Node * root;
public:
    Tree() { root = NULL; }
    
    void setRoot(Node * rootNode) { root = rootNode; }
    Node * getRoot() { return root; }
    
    void inorderTreeWalk(Node * node);
    
    Node * treeMinium(Node * node);
    Node * treeMaximum(Node * node);
    
    void insert(Tree *tree,Node * node);
    Node * search(Node * node, int k);
    
    Node * successor(Tree * tree,Node * node);
    Node * treedelete(Tree * tree,Node * node);
};

void Tree::inorderTreeWalk(Node * node)
{
    if(node!=NULL)
    {
        inorderTreeWalk(node->getLeftNode());
        node->print();
        inorderTreeWalk(node->getRightNode());
    }
}

Node * Tree:: treeMinium(Node * node)
{
    while(node->getLeftNode()!=NULL)
        node=node->getLeftNode();
    return node;
}

Node * Tree::treeMaximum(Node * node)
{
    while(node->getRightNode()!=NULL)
        node=node->getRightNode();
    return node;
}

void Tree::insert(Tree *tree,Node * node)
{
    Node *y=NULL;
    Node *x=tree->getRoot();
    while(x!=NULL){
        y=x;
        if(node->getKey()<x->getKey())
            x=x->getLeftNode();
        else
            x=x->getRightNode();
    }
    node->setParentNode(y);
    if(y==NULL)
        tree->setRoot(node);
    else
    {
        if(node->getKey()<y->getKey())
            y->setLeftNode(node);
        else
            y->setRightNode(node);
    }
}

Node *Tree:: search(Node * node, int k)
{
    if(node==NULL||k==node->getKey())
    {
        return node;
    }
    if(k<node->getKey())
        return search(node->getLeftNode(),k);
    else
        return search(node->getRightNode(),k);
}

Node *Tree:: successor(Tree * tree,Node * node)
{
    if(node->getRightNode()!=NULL)
        return tree->treeMinium(node->getRightNode());
    Node *y=node->getParentNode();
    while(y!=NULL&&node==y->getRightNode())
    {
        node=y;
        y=node->getParentNode();
    }
    return y;
}

Node * Tree::treedelete(Tree * tree,Node * node)
{
    Node * y=NULL;
    Node * x=NULL;
    if(node->getLeftNode()==NULL || node->getRightNode()==NULL)
    {
        y=node;
    }
    else
    {
        y=tree->successor(tree,node);
    }
    if(y->getLeftNode()!=NULL)
    {
        x =y->getLeftNode();
    }
    else
    {
        x =y->getRightNode();
    }
    if(x!=NULL)
    {
        x->setParentNode(y->getParentNode());
    }
    if(y->getParentNode()==NULL)
    {
        x=tree->getRoot();
    }
    else if(y==((y->getParentNode())->getLeftNode()))
    {
        (y->getParentNode())->setLeftNode(x);
    }
    else
    {
        (y->getParentNode())->setRightNode(x);
    }
    if(y!=node)
    {
        node->setKey(y->getKey());
    }
    return y;
}

int main()
{
    Tree * newTree = new Tree();
    cout << "Before insert\n";
    int a[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        a[i] = rand() % 100;
        cout << a[i] << " ";
    }
    cout << endl << endl;
    
    cout << "Insert Node in the tree\n";
    for (int i = 0; i < SIZE; i++)
    {
        Node * newNode = new Node(a[i]);
        newTree->insert(newTree,newNode);
    }
    
    newTree->inorderTreeWalk(newTree->getRoot());
    cout << endl;
    
    cout << endl << "Tree_Minimun" << endl;
    Node * minNode = newTree->treeMinium(newTree->getRoot());
    minNode->print();
    
    cout << endl <<"Tree_Maximun" << endl;
    Node * maxNode = newTree->treeMaximum(newTree->getRoot());
    maxNode->print();
    
    cout << endl <<"search Node\n";
    int key = a[SIZE - 2];
    Node * node = newTree->search(newTree->getRoot(), key);
    if (node != NULL)
    {
        node->print();
    }
    else
    {
        cout << "can't find node which key is " << key << endl;
    }
    
    cout<< endl <<"Tree_successor" << endl;
    Node * successornode=newTree->successor(newTree,newTree->getRoot());
    successornode->print();
    
    cout<< endl <<"Tree_delete" << endl;
    newTree->getRoot ();
    Node * deletenode=newTree->treedelete(newTree,newTree->getRoot());
    deletenode->print();
    newTree->inorderTreeWalk(newTree->getRoot());
    delete newTree;
}
