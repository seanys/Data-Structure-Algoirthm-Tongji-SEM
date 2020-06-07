#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

#define LENGTH 1000000

//max heapify函数
void max_heapify(int arr[], int start, int end) {
    // 建立父节点和子节点的指标
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end) { //比较限制
        if (son + 1 <= end && arr[son] > arr[son + 1]) // 比较节点大小
            son++;
        if (arr[dad] < arr[son]){
            return;
        }else {
            swap(arr[dad], arr[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}

//void min_heapify(int arr[], int start, int end) {
//    // 建立父节点和子节点的指标
//    int dad = start;
//    int son = dad * 2 + 1;
//    while (son <= end) { //比较限制
//        if (son + 1 <= end && arr[son] < arr[son + 1]) // 比较节点大小
//            son++;
//        if (arr[dad] < arr[son]){
//            return;
//        }else {
//            swap(arr[dad], arr[son]);
//            dad = son;
//            son = dad * 2 + 1;
//        }
//    }
//}


void heap_sort(int arr[], int len) {
    for (int i = len / 2 - 1; i >= 0; i--)
        max_heapify(arr, i, len - 1);
    for (int i = len - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        max_heapify(arr, 0, i - 1);
    }
}

void select_max_inter(int arr[], int len){
    //暂时将尾巴变成0，删除数组太麻烦了
    arr[0]=arr[len-1];
    arr[len-1]=0;
    heap_sort(arr,len-1);
}

void insert_new_inter(int arr[], int len,int new_inter){
    //插入新的值需要定义新的数组，更改较为麻烦，暂时不做处理
//    for (int i = len / 2 - 1; i >= 0; i--)
//        max_heapify(arr, i, len - 1);
//    for (int i = len - 1; i > 0; i--) {
//        swap(arr[0], arr[i]);
//        max_heapify(arr, 0, i - 1);
//    }
}

int main() {
    clock_t startTime,endTime;
    startTime = clock();
    for (int i = 0; i < 1000000; i++)
    {
        i++;
    }
    
    srand((unsigned)time(NULL));
    int num[LENGTH];
    int rand_num;
    //生成随机数
    for(int i=0;i<LENGTH;i++){
        rand_num=rand()%100+1;
        num[i]=rand_num;
    }
//    cout<<"排序前："<<endl;
//    for(int i=0;i<LENGTH;i++){
//        cout<<num[i]<< ' ';
//    }
//    cout << endl;
    
//    cout<<"排序后："<<endl;
    
//    int len = (int) sizeof(num) / sizeof(*num);
    
    heap_sort(num, LENGTH-1);
    select_max_inter(num, LENGTH-1);
    
//    for (int i = 0; i < LENGTH; i++)
//        cout << num[i] << ' ';
//    cout << endl;
    endTime = clock();
    cout << "Totle Time : " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    return 0;
}
