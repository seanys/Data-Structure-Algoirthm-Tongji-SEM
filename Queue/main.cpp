// queue::push/pop
#include <iostream>       // std::cin, std::cout
#include <queue>          // std::queue

using namespace std;

//几个模式：push、pop

int main ()
{
    queue<int> myqueue;  //定义一个myqueue
    
    int stack_array[]={10,1,8,2,1,29,5,28};
    int stack_arrar_size=sizeof(stack_array)/sizeof(stack_array[0]);
    
    cout<<"输入数组为 {10,1,8,2,1,29,5,28}"<<endl;
    
    cout<<endl;
    
    for(int i=0;i<stack_arrar_size;i++){
        myqueue.push(stack_array[i]);
    }
    
    cout << "输出的queue的第一个值为: "<<endl;

    cout << myqueue.front()<<endl;
    
    cout << "输出的queue为: "<<endl;
    
    while (!myqueue.empty())  //判断是否为空
    {
        cout << myqueue.front()<<endl;
        myqueue.pop();  //pop queue
    }
    cout << '\n';
    
    cout<<"queue为先进先出"<<endl;
    
    return 0;
}
