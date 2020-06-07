//
//  main.cpp
//  Binary tree
//
//  Created by Sean Yang on 2019/4/21.
//  Copyright © 2019 Sean Yang. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

class Node{
private:
    int key;
    Node *leftNode;
    Node *rightNode;
    Node *parentNode;
public:
    Node(int value){
        leftNode=NULL;
        rightNode=NULL;
        parentNode=NULL;
        key=value;
    }
    void print(){
        cout<< "key:" << key <<endl;
    }
    void setValue(int value){
        key=value;
    }
    int getValue(){
        return key;
    }
    void setParentNode(Node *node){
        parentNode=node;
    }
    void setLeftNode(Node *node){
        leftNode=node;
    }
    void setRightNode(Node *node){
        rightNode=node;
    }
    Node * getParentNode(){
        return parentNode;
    }
    Node * getRightNode(){
        return rightNode;
    }
    Node * getLeftNode(){
        return leftNode;
    }
};

class Tree{
private:
    Node *root;
public:
    Tree(){
        root=NULL;
    }
    Node *getRoot(){
        return root;
    }
    void setRoot(Node *node){
        root = node;
    }
    void inorderTreeWalk(Node *node){ //注意这里是一个指针
        if(node!=NULL){
            inorderTreeWalk(node->getLeftNode());
            node->print();
            inorderTreeWalk(node->getRightNode());
        }
    }
    void insertNode(int newKey){
        Node *childNode=root;
        Node *parentNode=NULL;
        Node *newNode=new Node(newKey);
        while(childNode!=NULL){
            parentNode=childNode;
            if(newKey>parentNode->getValue()){
                childNode=parentNode->getRightNode();
            }else{
                childNode=parentNode->getLeftNode();
            }
        }
        newNode->setParentNode(parentNode);
        if(parentNode==NULL){
            root=newNode;
        }else if(newKey>parentNode->getValue()){
            parentNode->setRightNode(newNode);
        }else{
            parentNode->setLeftNode(newNode);
        }
    }
    Node * TreeMinimum(Node *node){
        while(node->getLeftNode()!=NULL){
            node=node->getLeftNode();
        }
        return node;
    }
    Node * TreeMaximum(Node *node){
        while(node->getRightNode()!=NULL){
            node=node->getRightNode();
        }
        return node;
    }
    Node * treeSuccessor(Node *node){
        if(node->getRightNode()!=NULL){
            return TreeMinimum(node->getRightNode());
        }
        Node *parent=node->getParentNode();
        while(parent!=NULL&&node==parent->getRightNode()){
            node=parent;
            parent=node->getParentNode();
        }
        return parent;
    }
    Node * treeSearch(Node *node,int value){
        if(node==NULL||node->getValue()==value){
            cout<<"未找到元素："<<value<<endl;
            return node;
        }
        if(value>node->getValue()){
            return treeSearch(node->getRightNode(), value);
        }else{
            return treeSearch(node->getLeftNode(), value);
        }
    }
    void transplate(Node *node, Node *newNode){
        if(node->getParentNode()==NULL){
            setRoot(newNode);
            return;
        }
        if(node->getParentNode()->getRightNode()==node){
            node->getParentNode()->setRightNode(newNode);
        }else{
             node->getParentNode()->setLeftNode(newNode);
        }
        if(newNode!=NULL)
            newNode->setParentNode(node->getParentNode());
    }
    void deleteNode(Node *node){
        if(node->getRightNode()==NULL){
            transplate(node, node->getLeftNode());
        }else if(node->getLeftNode()==NULL){
            transplate(node, node->getRightNode());
        }else{
            Node *successorNode=TreeMinimum(node->getRightNode());
            if(successorNode->getParentNode()!=node){
                transplate(successorNode, successorNode->getRightNode());
                successorNode->setRightNode(node->getRightNode());
                node->getRightNode()->setParentNode(successorNode);
            }
            transplate(node,successorNode);
            successorNode->setLeftNode(node->getLeftNode());
            node->getLeftNode()->setParentNode(successorNode);
        }
    }
};

int main(int argc, const char * argv[]) {
    Tree *tree=new Tree();
    cout<<"insertNode:"<<endl;
    tree->insertNode(10); //root
    tree->insertNode(27);
    tree->insertNode(9);
    tree->insertNode(19);
    tree->insertNode(6);
    tree->insertNode(15);
    tree->insertNode(30);
    Node *root=tree->getRoot();
    tree->inorderTreeWalk(root);
    Node *newNode=tree->treeSuccessor(root);
    cout<<"测试后继元素："<<endl;
    newNode->print();
    cout<<"测试寻找元素："<<endl;
    Node *deleteNode=tree->treeSearch(root,10);
//    tree->treeSearch(root,19);
//    tree->treeSearch(root,31);
//    tree->treeSearch(root,30);
    cout<<"测试删除root："<<endl;
    tree->deleteNode(deleteNode);
    tree->inorderTreeWalk(tree->getRoot());

    return 0;
}
