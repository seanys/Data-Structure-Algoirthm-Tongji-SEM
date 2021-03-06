//
//  main.cpp
//  Binary Tree
//
//  Created by 爱学习的兔子 on 2020/6/11.
//  Copyright © 2020 Yang Shan. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;
#define LENGTH 100

struct Node
{
    int key;
    struct Node *left, *right;
};

// A utility function to create a new BST Node
struct Node *newNode(int item)
{
    struct Node *temp = new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Stores inoder traversal of the BST
// in arr[]
void storeSorted(Node *root, int arr[], int &i)
{
    if (root != NULL)
    {
        storeSorted(root->left, arr, i);
        arr[i++] = root->key;
        storeSorted(root->right, arr, i);
    }
}

/* A utility function to insert a new
 Node with given key in BST */
Node* insert(Node* node, int key)
{
    /* If the tree is empty, return a new Node */
    if (node == NULL) return newNode(key);
    
    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    
    /* return the (unchanged) Node pointer */
    return node;
}

// 二叉树排序
void treeSort(int arr[], int n)
{
    struct Node *root = NULL;
    
    // Construct the BST
    root = insert(root, arr[0]);
    for (int i=1; i<n; i++)
        insert(root, arr[i]);
    
    // Store inoder traversal of the BST
    // in arr[]
    int i = 0;
    storeSorted(root, arr, i);
}

int main()
{
    
    srand((unsigned)time(NULL));
    int num[LENGTH];
    int rand_num;
    //生成随机数
    for(int i=0;i<LENGTH;i++){
        rand_num=rand()%1000+1;
        num[i]=rand_num;
    }
    
    treeSort(num, LENGTH);
    
    for (int i=0; i<LENGTH; i++)
        cout << num[i] << " ";
    cout<<endl;
    
    return 0;
}
