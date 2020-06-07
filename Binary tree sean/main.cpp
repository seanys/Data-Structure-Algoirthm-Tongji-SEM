//
//  main.cpp
//  Binary tree sean
//
//  Created by Sean Yang on 2019/4/24.
//  Copyright © 2019 Sean Yang. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <ctime>

using namespace std;

class Node{
public:
    int key;
    Node *left;
    Node *right;
    Node *parent;
    Node(){
        key=NULL;
        left=right=parent=NULL;
    }
};

class BinaryTree{
public:
    Node *root;
    BinaryTree(){
        root=NULL;
    }
    void buildTree(int TreeSize){
        srand((unsigned)time(NULL));
        for(int i=0;i<TreeSize;i++){
            Node *newNode=new Node();
            newNode->key=rand()%100;
            insertNode(newNode);
        }
    }
    void inorderTravel(Node *node){
        if(node!=NULL){
            inorderTravel(node->left);
            cout<<node->key<<" ";
            inorderTravel(node->right);
        }
    }
    Node *treeMinimum(Node *node){
        if(node->left!=NULL){
            return treeMinimum(node->left);
        }
        return node;
    }
    Node *treeMaximum(Node *node){
        if(node->right!=NULL){
            return treeMaximum(node->right);
        }
        return node;
    }
    Node *treeSuccessor(Node *node){
        if(node->right!=NULL){
            return treeMinimum(node);
        }
        Node *parent=node->parent;
        while(parent!=NULL&&node==parent->right){
            node=node->parent;
            parent=parent->parent;
        }
        return parent;
    }
    Node *treePredecessor(Node *node){
        if(node->left!=NULL){
            return treeMaximum(node);
        }
        Node *parent=node->parent;
        while(parent!=NULL&&node==parent->left){
            node=node->parent;
            parent=parent->parent;
        }
        return parent;
    }
    void insertNode(Node *newNode){
        if(root==NULL){
            root=newNode;
        }else{
            Node *temp=root;
            int value=newNode->key;
            while(true){
                if(temp->key>value){
                    if(temp->left!=NULL){
                        temp=temp->left;
                    }else{
                        temp->left=newNode;
                        newNode->parent=temp;
                        break;
                    }
                }else{
                    if(temp->right!=NULL){
                        temp=temp->right;
                    }else{
                        temp->right=newNode;
                        newNode->parent=temp;
                        break;
                   }
                }
            }
        }
    }
    void searchValue(int value){
        Node *temp=root;
        while(temp!=NULL&&temp->key!=value){
            if(temp->key>value){
                temp=temp->left;
            }else{
                temp=temp->right;
            }
        }
        if(temp==NULL){
            cout<<"未找到元素"<<value<<endl;
        }else{
            cout<<"找到元素"<<value<<endl;
        }
    }
    void transplant(Node *node,Node *newNode){
        if(node->parent!=NULL){
            if(node->parent->right==node){
                node->parent->right=newNode;
            }else{
                node->parent->left=newNode;
            }
            if(newNode!=NULL){
                newNode->parent=node->parent;
            }
        }else{
            root=newNode;
        }
        
    }
    void deleteNode(Node *node){
        if(node->right==NULL){
            transplant(node, node->left);
        }else if(node->left==NULL){
            transplant(node, node->right);
        }else{
            Node *newNode=treeMinimum(node->right);
            if(newNode->parent!=node){
                transplant(newNode, newNode->right);
                newNode->right=node->right;
                newNode->right->parent=newNode;
            }
            transplant(node, newNode);
            newNode->left=node->left;
            newNode->left->parent=newNode;
        }
    }
};

int main(int argc, const char * argv[]) {
    BinaryTree *newTree=new BinaryTree();
    newTree->buildTree(10);
    newTree->inorderTravel(newTree->root);
    cout<<endl;
    newTree->searchValue(89);
    newTree->searchValue(9);
    newTree->searchValue(1);
    newTree->searchValue(67);
    cout<<"root:"<<newTree->root->key<<endl;
    cout<<"key:"<<newTree->root->right->key<<endl;
    Node *newNode=new Node();
//    newNode=newTree->treeMaximum(newTree->root->right->left);
//    cout<<"treeMaximum:"<<newNode->key<<endl;
//    newNode=newTree->treeMinimum(newTree->root->right->left);
//    cout<<"treeMinimum:"<<newNode->key<<endl;
//    newNode=newTree->treeSuccessor(newTree->root->right->left);
//    cout<<"treeSuccessor:"<<newNode->key<<endl;
//    newNode=newTree->treePredecessor(newTree->root->right->left);
//    cout<<"treePredecessor:"<<newNode->key<<endl;
    
    newTree->deleteNode(newTree->root);
    newTree->inorderTravel(newTree->root);
    cout<<endl;
    
    return 0;
}
