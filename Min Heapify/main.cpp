#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

void min_heapify(int arr[], int start,int end) {
    // 建立父节点和子节点的指标
    int left =  start * 2 + 1;
    int right = start * 2 + 2;
    int least;
    if(left<=end&&arr[left]<arr[start]){
        least=left;
    }else{
        least=start;
    }
    if(left<=end&&arr[right]<arr[least]){
        least=right;
    }
    cout<<least<<endl;
    if(least!=start){
        swap(arr[start],arr[least]);
        min_heapify(arr, least, end);
    }
}

int main() {
    int num[]={30,55,93,52,26,37,62,94,10,30,78,10,40,73,82};
    int len = (int) sizeof(num) / sizeof(*num);
    cout<<"Heapify前："<<endl;
    int line=1;
    for(int i=0;i<len;i++){
        cout<<num[i]<< ' ';
        if(i==pow(2,line)-2){
            cout<<endl;
            line=line+1;
        }
    }
    cout << endl;
    
    min_heapify(num,2,len);
    
    cout<<"min_heapify(num,2,len)："<<endl;
    line=1;
    for(int i=0;i<len;i++){
        cout<<num[i]<< ' ';
        if(i==pow(2,line)-2){
            cout<<endl;
            line=line+1;
        }
    }
    
    cout<<"分析：目标对象是93，经过min_heapify之后到了最下层"<<endl;
    
    min_heapify(num,1,len);
    
    cout<<"min_heapify(num,1,len)："<<endl;
    line=1;
    for(int i=0;i<len;i++){
        cout<<num[i]<< ' ';
        if(i==pow(2,line)-2){
            cout<<endl;
            line=line+1;
        }
    }
    
    cout<<"分析：目标对象是55，经过min_heapify之后到了最下层右侧"<<endl;
    
    
    return 0;
}
