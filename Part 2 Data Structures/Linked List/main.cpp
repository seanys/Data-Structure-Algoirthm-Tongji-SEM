//
//  main.cpp
//  Linked List
//
//  Created by 爱学习的兔子 on 2020/6/11.
//  Copyright © 2020 Yang Shan. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

struct node
{
    int data;
    node *next;
};
// 创建单链表
node *creat()
{
    node *head, *p;
    head = new node;
    p = head;
    
    int x, cycle = 1;
    while (cycle)
    {
        cout << "Please input the data for single linker : ";
        cin >> x;
        
        if (x != 0)
        {
            node *s = new node;
            s->data = x;
            cout << "Input data : " << x << endl;
            
            p->next = s;
            p = s;
        }
        else
        {
            cycle = 0;
            cout << "Input done! " << endl;
        }
    }
    
    head = head->next;
    p->next = NULL;
    //cout << "\nFirst data of single linker is " << head->data << endl;
    
    return head;
}

// 单链表测长
int length(node *head)
{
    int n   = 0;
    node *p = head;
    
    while (p != NULL)
    {
        p = p->next;
        n++;
    }
    
    return n;
}

// 单链表打印
void printL(node *head)
{
    node *p = head;
    
    while(p != NULL)
    {
        cout << "Single Linker data is " << p->data << endl;
        p = p->next;
    }
}

// 单链表插入
node *insert(node *head, int num)
{
    node *p0, *p1, *p2;
    p1 = head;
    
    p2 = new node;
    p0 = new node; // 插入节点
    p0->data = num;// 插入数据
    
    while (p0->data > p1->data && p1->next != NULL)
    {
        p2 = p1;
        p1 = p1->next;// p0,p1和p2位置: p2->p1->p0
    }
    
    if (p0->data <= p1->data)
    {
        if (p1 == head)
        {// 头部前段插入 p0和p1位置: p0->p1->...
            head = p0;
            p0->next = p1;
        }
        else
        {// 插入中间节点 p0,p1和p2位置: p2-> p0 -> p1
            p2->next = p0;
            p0->next = p1;
        }
    }
    else
    {   // 尾部插入节点 p0,p1和p2位置: p2->p1->p0->NULL
        p1->next = p0;
        p0->next = NULL;
    }
    return head;
}

// 单链表删除
node *del(node *head, int num)
{
    node *p1, *p2;
    p2 = new node;
    p1 = head;
    
    while (num != p1->data && p1->next != NULL)
    {
        p2 = p1;
        p1 = p1->next;// p1和p2位置: p2->p1
    }
    
    if (num == p1->data)
    {
        if (p1 == head)// 删除头节点
        {
            head = p1->next;
            delete p1;
        }
        else
        {
            p2->next = p1->next;
            delete p1;
        }
    }
    else
    {
        cout << num << " could not been found in the current single linker!" << endl;
    }
    return head;
}


int main()
{
    cout << "***创建单链表***" << endl;
    node *head = creat();
    cout << endl;
    
    cout << "***计算链表长***" << endl;
    int n = length(head);
    cout << "The length of input single linker is " << n << "." << endl;
    cout << endl;
    
    cout << "***打印单链表***" << endl;
    printL(head);
    cout << endl;
    
    cout << "****插入节点****" << endl;
    cout << "Please input the data for inserting operate : ";
    int inData;
    cin >> inData;
    head = insert(head,inData);
    printL(head);
    cout << endl;
    
    cout << "****删除节点****" << endl;
    cout << "Please input the data for deleting operate : ";
    int outData;
    cin >> outData;
    head = del(head, outData);
    printL(head);
    cout << endl;
    
    return 0;
}
