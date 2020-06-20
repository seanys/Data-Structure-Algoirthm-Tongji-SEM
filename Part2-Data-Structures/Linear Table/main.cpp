//
//  main.cpp
//  Linear Table
//
//  Created by 爱学习的兔子 on 2020/6/11.
//  Copyright © 2020 Yang Shan. All rights reserved.
//

#include<iostream>
#include<cstdio>
using namespace std;
typedef struct Stacknode//定义链式栈的结构体
{
    int data;//数据域
    Stacknode *next;//下一节点的指针域
}Stacknode,*Stack;

//初始化一个链式栈（返回一个链式栈的头节点）
Stack InitStack()
{
    Stack stack=(Stack)malloc(sizeof(Stacknode));
    stack->next=NULL;
    return stack;
}
//入栈
void Push(Stack stack,int newData)
{
    //判断是否为空
    if(stack==NULL)
    {
        printf("栈未初始化，请初始化以后再使用\n");
        return;
    }
    //找到最后一个节点
    Stacknode *lastnode=stack;
    while(lastnode->next)
    {
        lastnode=lastnode->next;
    }
    lastnode->next=(Stacknode*)malloc(sizeof(Stacknode*));
    lastnode->next->data=newData;
    lastnode->next->next=NULL;
    printf("入栈成功！\n");
}
//出栈
int Pop(Stack stack)
{
    //判断栈是否为空
    if(!stack->next)
    {
        printf("栈为空，无法出栈\n");
        return -1;//-1只是一个自定义的错误代码
    }
    //找到最后一个节点的钱一个节点
    //tempNode:最后一个节点的前一个节点
    Stacknode *tempNode=stack;
    while(tempNode->next->next)
    {
        tempNode=tempNode->next;
    }
    int data=tempNode->next->data;
    free(tempNode->next);
    tempNode->next=NULL;
    return data;
}

int main()
{
    Stack stack=InitStack();
    Push(stack,3);//3进栈
    Push(stack,4);//4进栈
    Push(stack,5);//5进栈
    printf("%d\n",Pop(stack));
    printf("%d\n",Pop(stack));
    printf("%d\n",Pop(stack));
    printf("%d\n",Pop(stack));//第4次出栈，应该出错
    return 0;
}
