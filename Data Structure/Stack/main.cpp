#include<iostream>
#include<stack>
#include<queue>
using namespace std;

int main()
{
    stack<int> s;
    
    //stack的五种操作
//    s.push(item);       //将item压入栈顶
//    s.pop();            //删除栈顶的元素，但不会返回
//    s.top();            //返回栈顶的元素，但不会删除
//    s.size();           //返回栈中元素的个数
//    s.empty();          //检查栈是否为空，如果为空返回true，否则返回false
    
    int stack_array[]={10,1,8,2,1,29,5,28};
    int stack_arrar_size=sizeof(stack_array)/sizeof(stack_array[0]);
    
    cout<<"输入数组为 {10,1,8,2,1,29,5,28}"<<endl;
    
    cout<<endl;
    
    for(int i=0;i<stack_arrar_size;i++){
        s.push(stack_array[i]);
    }

    
    cout<<"栈有 "<<s.size()<<" 个元素:"<<endl;
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    cout<<"\n去除后的长度 "<<s.size()<<endl;
    cout<<"\n是否为空 "<<s.empty()<<endl;
    
    cout<<"可以看到stack是后进先出"<<endl;
    
    return 0;
}
