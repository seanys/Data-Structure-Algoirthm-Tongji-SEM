#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

int Partition(int [],int ,int );
void RandomQuicksort(int [],int ,int );
int RandomPartition(int [],int,int );

#define LENGTH 10000

int main(int argc, char const *argv[])
{
    //程序计时
    clock_t startTime,endTime;
    startTime = clock();
    for (int i = 0; i < 1000000; i++)
    {
        i++;
    }
    
    srand((unsigned)time(NULL));
    int list[LENGTH];
    int rand_num;
    
    //生成随机数
    for(int i=0;i<LENGTH;i++){
        rand_num=rand()%100000+1;
        list[i]=rand_num;
    }
    
    int p=0,r=LENGTH-1;
    
    RandomQuicksort(list,p,r);
    
    endTime = clock();
    cout << "Totle Time : " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    
    return 0;
}

void RandomQuicksort(int a[],int p,int r)
{
    int q;
    if(p<r)
    {
        q=RandomPartition(a,p,r);
        RandomQuicksort(a,p,q-1);
        RandomQuicksort(a,q+1,r);
    }
}

int RandomPartition(int a[],int p,int r)
{
    int i=p+rand()%(r-p+1);
    int temp;
    temp=a[r];
    a[r]=a[i];
    a[i]=temp;
    return Partition(a,p,r);
}

int Partition(int a[],int p,int r)
{
    int temp,temp1;
    int x=a[r];
    int i=p-1;
    for(int j=p;j<=r-1;j++)
    {
        if(a[j]<=x)
        {
            
            i=i+1;
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    temp1=a[i+1];
    a[i+1]=a[r];
    a[r]=temp1;
    return i+1;
}
