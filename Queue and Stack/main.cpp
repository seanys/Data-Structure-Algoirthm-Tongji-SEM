//
//  main.cpp
//  Queue and Stack
//
//  Created by Sean Yang on 2019/4/22.
//  Copyright © 2019 Sean Yang. All rights reserved.
//

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main(int argc, const char * argv[]) {
    queue<int> myqueue;
    myqueue.push(9);
    myqueue.push(4);
    myqueue.push(3);
    myqueue.push(8);
    cout<<"逐步输出一个queue："<<endl;
    //queue是先进先出，所以front会一直变
    while (!myqueue.empty())  //判断是否为空
    {
        cout << myqueue.front()<<endl;
        myqueue.pop();  //pop queue
    }
    //stack是后进先出
    stack<int> mystack;
    mystack.push(9);
    mystack.push(4);
    mystack.push(10);
    mystack.push(3);
    cout<<"逐步输出一个stack："<<endl;
    while(!mystack.empty())
    {
        cout<<mystack.top()<<endl; //top是最后进入的
        mystack.pop();
    }
    return 0;
}
