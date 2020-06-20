//计数排序，适用于排序的所有数都小于k的情况，稳定
#include <iostream>
using namespace std;

int const k = 5;

void DispArray(int a[],int length)
{
    for(int i = 0;i < length;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

//计数排序算法
void CountSort(int a[],int b[],int length)
{
    int i,j;
    int c[k + 1];
    for(i = 0;i <= k;i++)
        c[i] = 0;                   //初始化，其实不用，在定义数组c[k]的时候就已经初始化
    for(j = 0;j < length;j++)
        c[a[j]] = c[a[j]] + 1;
    for(i = 1;i <= k;i++)
        c[i] = c[i] + c[i - 1];     //  跟这样计数真的体现了计数这个思想
    for(j = length - 1;j >= 0;j--)
    {
        b[c[a[j]] - 1] = a[j];      //原伪代码中b[c[a[j]]] = a[j];无形中是在说b是1-->length
        c[a[j]] = c[a[j]] - 1;
    }
}

int main()
{
    int a[8] = {2,5,3,0,2,3,0,3};
    int b[8] = {0,0,0,0,0,0,0,0};
    
    CountSort(a,b,8);       //数组是一种指针
    DispArray(b,8);
    
    return 0;
}
