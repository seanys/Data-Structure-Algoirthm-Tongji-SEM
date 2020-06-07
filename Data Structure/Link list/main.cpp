//
//  main.cpp
//  Link list
//
//  Created by Sean Yang on 2019/4/23.
//  Copyright © 2019 Sean Yang. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <ctime>

#define LENGTH 20

using namespace std;

class Node{    
public:
    int key;
    Node *pre,*next;
    Node(){
        pre=NULL;
        next=NULL;
        key=0;
    }
};

class DoubleLinkList{
private:
    Node *head;
public:
    DoubleLinkList(){
        head=new Node();
    }
    void insertNode(Node *node){
        Node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=node;
        node->pre=temp;
    }
    void insertNodeOrder(Node *node){
        Node *temp=head;
        int node_value=node->key;
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
    }
    void travelList(){
        Node *temp=head;
        if(temp->next==NULL){
            cout<<"链表为空"<<endl;
            return;
        }
        while(temp->next!=NULL){
            temp=temp->next;
            cout<<temp->key<<" ";
        }
        cout<<endl;
    }
    void deleteValue(int deleteValue){
        Node *temp=head;
        if(temp->next==NULL){
            cout<<"链表为空"<<endl;
            return;
        }
        while(temp->next!=NULL){
            temp=temp->next;
            if(temp->key==deleteValue){
                Node *preNode=temp->pre;
                if(temp->next==NULL){
                    preNode->next=NULL;
                }else{
                    Node *nextNode=temp->next;
                    preNode->next=nextNode;
                    nextNode->pre=preNode;
                    temp=preNode;
                }
            }
        }
    }
    void searchValue(int searchValue){
        Node *temp=head;
        if(temp->next==NULL){
            cout<<"链表为空"<<endl;
            return;
        }
        int count=0;
        while(temp->next!=NULL){
            temp=temp->next;
            if(temp->key==searchValue){
                count++;
            }
        }
        cout<<"搜索结束：共有"<<count<<"个"<<searchValue<<endl;
    }
    void deletePosition(int position){
        Node *temp=head;
        if(temp->next==NULL){
            cout<<"链表为空"<<endl;
            return;
        }
        if(position<=0){
            cout<<"输出值必须大于0"<<endl;
            return;
        }
        int i=0;
        while(temp->next!=NULL){
            temp=temp->next;
            i=i+1;
            if(i==position){
                Node *preNode=temp->pre;
                if(temp->next==NULL){
                    preNode->next=NULL;
                }else{
                    Node *nextNode=temp->next;
                    preNode->next=nextNode;
                    nextNode->pre=preNode;
                    temp=preNode;
                }
                cout<<"success：删除成功"<<endl;
                break;
            }
        }
        if(i<position){
            cout<<"erro：超出范围"<<endl;
        }
    }
    void searchPosition(int position){
        Node *temp=head;
        if(temp->next==NULL){
            cout<<"链表为空"<<endl;
            return;
        }
        if(position<=0){
            cout<<"输出值必须大于0"<<endl;
            return;
        }
        int i=0;
        while(temp->next!=NULL){
            temp=temp->next;
            i=i+1;
            if(i==position){
                cout<<"success：该位置的值为："<<temp->key<<endl;
                break;
            }
        }
        if(i<position){
            cout<<"erro：超出范围"<<endl;
        }
    }

};

int main(int argc, const char * argv[]) {
    DoubleLinkList *dbl=new DoubleLinkList();
    srand((unsigned)time(NULL));
    for(int i=0;i<LENGTH;i++){
        Node *node=new Node();
        node->key=rand()%10+1;
        dbl->insertNodeOrder(node);
    }
    cout<<"链表的内容为：";
    dbl->travelList();
//    int deleteValue;
//    cout<<"请输入需要删除的值：";
//    cin>>deleteValue;
//    dbl->deleteValue(deleteValue);
//    cout<<"删除后的链表："<<endl;
//    dbl->travelList();
    
    dbl->deletePosition(-1);
    dbl->deletePosition(1);
    cout<<"删除位置1后：";
    dbl->travelList();
    dbl->deletePosition(19);
    dbl->deletePosition(19);
    dbl->searchPosition(1);
    dbl->searchValue(2);

    return 0;
}
