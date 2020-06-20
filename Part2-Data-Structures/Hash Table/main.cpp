//
//  main.cpp
//  Hash Table
//
//  Created by Sean Yang on 2019/4/23.
//  Copyright © 2019 Sean Yang. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <ctime>

#define LENGTH 100
#define TABLESIZE 9
#define HASHTYPE "MULTI"
//#define HASHTYPE "DIV"

int MULTINUM=0.61803398875;

using namespace std;

class Node{
public:
    int key;
    Node *next;
    Node *pre;
    Node(){
        key=0;
        next=NULL;
        pre=NULL;
    }
};


class HashTable{
public:
    Node *list[TABLESIZE];
    HashTable(){
        for(int i=0;i<TABLESIZE;i++){
            list[i]=new Node();
        }
    };
    void insertValue(int value){
        int position=hashFunction(value);

        Node *newNode=new Node();
        newNode->key=value;

        Node *temp=list[position];
        while(temp->next!=NULL){
            temp=temp->next;
        }

        temp->next=newNode;
        newNode->pre=temp;

    };
    void insertValueOrder(int value){
        int position=hashFunction(value);
        
        Node *node=new Node();
        node->key=value;
        
        Node *temp=list[position];
        
        int node_value=value;
        
        while(temp->next!=NULL&&temp->key<node_value){
            temp=temp->next;
        }
        if(temp->key>node_value){
            temp=temp->pre;
        }
        if(temp->next!=NULL){
            node->next=temp->next;
            temp->next->pre=node;
        }
        temp->next=node;
        node->pre=temp;
        
    };
    Node *findValueOrder(int value){
        int position=hashFunction(value);
        Node *findNode=NULL;
        Node *temp=list[position];
        
        while (temp->next!=NULL&&temp->next->key<value) {
            temp=temp->next;
        }
        temp=temp->next;
        if(temp==NULL||temp->key!=value){
            cout<<"未找到该值："<<value<<endl;
        }else{
            cout<<"在第"<<position<<"行找到该值："<<value<<endl;
            findNode=temp;
        }
        return findNode;
    };
    Node *findValue(int value){
        int position=hashFunction(value);
        Node *findNode=NULL;
        Node *temp=list[position];
        
        while (temp->next!=NULL&&temp->next->key!=value) {
            temp=temp->next;
        }
        temp=temp->next;
        if(temp==NULL||temp->key!=value){
            cout<<"未找到该值："<<value<<endl;
        }else{
            cout<<"在第"<<position<<"行找到该值："<<value<<endl;
            findNode=temp;
        }
        return findNode;
    };
    void deleteValue(int value){
        while(findValue(value)!=NULL){
            Node *findNode=findValue(value);
            findNode->pre->next=findNode->next;
            if(findNode->next!=NULL){
                findNode->next->pre=findNode->pre;
            }
            cout<<"删除成功"<<endl;
        }
        cout<<"删除执行结束"<<endl;
    };
    void travelTable(){
        for(int i=0;i<TABLESIZE;i++){
            cout<<"list["<<i<<"]:[";
            Node *temp=list[i]->next;
            while(temp!=NULL){
                if(temp!=list[i]->next){
                    cout<<",";
                }
                cout << temp -> key;
                temp = temp -> next;
            }
            cout<<"]"<<endl;
        }
    };
    int hashFunction(int value){
        if(HASHTYPE=="MULTI"){
            return value%TABLESIZE;
        }else if(HASHTYPE=="DIV"){
            return value%TABLESIZE;
        }else{
            return value%TABLESIZE;
        }
    }
};

int main(int argc, const char * argv[]) {
    HashTable *table=new HashTable();
    
    srand((unsigned)time(NULL));
    for(int i=0;i<LENGTH;i++){
        table->insertValueOrder(rand()%100+1);
    }
    
    
    
    table->travelTable();
    
    table->findValueOrder(90);
    table->findValueOrder(23);
    table->findValueOrder(28);
    table->findValueOrder(9);
    table->findValueOrder(50);
    table->findValueOrder(38);

    return 0;
}
