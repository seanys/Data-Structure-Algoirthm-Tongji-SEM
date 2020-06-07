#include "iostream"
#include "iomanip"
#include "time.h"
using namespace std;


struct btree
{
    struct btree *parent;
    int key;
    struct btree *left;
    struct btree *right;
};

//对的
void IN_ORDER_TREE_WALK(struct btree *x)
{
    if(x != NULL)
    {
        IN_ORDER_TREE_WALK((*x).left);
        cout<<(*x).key<<"  ";
        IN_ORDER_TREE_WALK((*x).right);
    }
}

struct btree *TREE_MINIMUM(struct btree *x)
{
    while((*x).left != NULL)
    {
        x = (*x).left;
    }
    return x;
}

struct btree *TREE_MAXIMUM(struct btree *x)
{
    while((*x).right != NULL)
    {
        x = (*x).right;
    }
    return x;
}

struct btree *TREE_INSERT(struct btree *t, struct btree *z)
{
    struct btree *y = NULL;
    struct btree *x = t;
    while (x != NULL)
    {
        y = x;
        if((*z).key<(*x).key)
        {
            x = (*x).left;
        }
        else
        {
            x = (*x).right;
        }
    }
    (*z).parent = y;
    if(y == NULL)
    {
        t = z;
    }
    else
    {
        if( (*z).key<(*y).key)
        {
            (*y).left = z;
        }
        else
        {
            (*y).right = z;
        }
    }
    return t;
}

struct btree *TREE_SEARCH(struct btree *x , int k)
{
    if( x == NULL || k ==(*x).key)
    {
        return x;
    }
    if(k < (*x).key)
    {
        return TREE_SEARCH((*x).left,k);
    }
    else
    {
        return TREE_SEARCH((*x).right,k);
    }
    
}

struct btree *TREE_SUCCESSOR(struct btree *x)
{
    struct btree *y = NULL;
    if((*x).right != NULL)
    {
        return TREE_MINIMUM((*x).right);
    }
    y = (*x).parent;
    while(y != NULL && x == (*y).right)
    {
        x = y;
        y = (*x).parent;
    }
    return y;
}

struct btree *TREE_DELETE(struct btree *t , struct btree *z)
{
    struct btree *y = NULL;
    struct btree *x = NULL;
    if((*z).left == NULL || (*z).right == NULL)
    {
        y = z;
    }
    else
    {
        y = TREE_SUCCESSOR(z);
    }
    if((*y).left != NULL)
    {
        x = (*y).left;
    }
    else
    {
        x = (*y).right;
    }
    if(x != NULL)
    {
        (*x).parent = (*y).parent;
    }
    if((*y).parent == NULL)
    {
        t = x;
    }
    else
    {
        if(y ==  (*(*y).parent).left)
        {
            (*(*y).parent).left = x;
        }
        else
        {
            (*(*y).parent).right = x;
        }
    }
    
    if(y!=z)
    {
        (*z).key =(*y).key;
    }
    return y;
}

int main()
{
    int arr[100];
    struct btree *root = NULL;
    struct btree *t = NULL;
    struct btree *z = new struct btree;
    for (int i = 0; i < 100; i++)
    {
        arr[i] = rand() % 1000;
        cout << arr[i] << "  ";
        
        (*z).key = arr[i];
        t = TREE_INSERT(root,z);
        root = t;
    }
    cout<<endl;
    delete z;
    
    cout << "？？？？: " << endl;
    struct btree *a = TREE_MINIMUM(root);
    cout<<(*a).key<<" ";
    for(int i = 1;i<100;i++)
    {
        a = TREE_SUCCESSOR(a);
        cout<<(*a).key<<" ";
    }
    
    int j = 0;
    while (j<=50)
    {
        int m = rand() % 1000;
        struct btree *n = TREE_SEARCH(root,m);
        if(n != NULL)
        {
            TREE_DELETE(root,n);
            j++;
        }
    }
    
    cout << "？？？？？" << endl;
    struct btree *a1 = TREE_MINIMUM(root);
    cout<<(*a1).key<<" ";
    for(int i = 1;i<50;i++)
    {
        a1 = TREE_SUCCESSOR(a1);
        cout<<(*a1).key<<" ";
    }
    
    system("pause");
    return 0;
}
