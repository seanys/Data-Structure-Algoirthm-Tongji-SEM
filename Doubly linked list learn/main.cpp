//
//  main.cpp
//  Doubly linked list learn
//
//  Created by Sean Yang on 2019/4/15.
//  Copyright © 2019 Sean Yang. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <ctime>
#include <cstdlib>

using namespace std;

//创建一个Node类，也就是节点，节点中有data，还有指向前后的两个Node，均为指针，指向新节点的位置
class Node {
public:
    int data;
    Node *pre,*next;
};

class DoubleLinkedList{
public:
    DoubleLinkedList(){
        head = new Node;
        head->data=0;
        head->pre=NULL;
        head->next=NULL;
    }
    ~DoubleLinkedList(){delete head;}
    CreateLinkList(){}
private:
    Node *head;
};

DoubleLinkedList::CreateLinkList(){
    cout<<"请输入需要创建的数组长度："<<endl;
    int n;
    cin>>n;
    while(n<0){
        cout<<"请重新输入"<<endl;
        cin>>n;
    }
    Node *ptemp,*pnew;
    ptemp=head;
    for(int i=0;i<n;i++){
        srand((unsigned)time(NULL));
        pnew = new Node;
        pnew->data=rand()%1000+1;
        ptemp->next=pnew;
        pnew->next=NULL;
        ptemp=pnew;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    DoubleLinkedList test;
    test.head->;
    cout << "Hello, World!\n";
    return 0;
}
