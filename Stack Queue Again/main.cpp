//
//  main.cpp
//  Stack Queue Again
//
//  Created by Sean Yang on 2019/4/28.
//  Copyright © 2019 Sean Yang. All rights reserved.
//

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    stack <int> mystack;
    mystack.push(2);
    mystack.push(7);
    mystack.push(10);
    mystack.push(8);
    while (!mystack.empty()) {
        cout<<"stack大小："<<mystack.size()<<endl;
        cout<<mystack.top()<<endl;
        mystack.pop();
    }
    queue <int> myqueue;
    myqueue.push(2);
    myqueue.push(7);
    myqueue.push(10);
    myqueue.push(8);
    while (!myqueue.empty()) {
        cout<<"大小："<<myqueue.size()<<endl;
        cout<<"首："<<myqueue.front()<<endl;
        cout<<"尾："<<myqueue.back()<<endl;
        myqueue.pop();
    }
    return 0;
}
