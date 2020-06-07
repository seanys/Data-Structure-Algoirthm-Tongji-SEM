//
//  main.cpp
//  Heap sort
//
//  Created by Sean Yang on 2019/4/21.
//  Copyright © 2019 Sean Yang. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;
#define LENGTH 20

void PrintTree(int array[],int length){
    int binary_max=2;
    for(int i=0;i<length;i++){
        cout<<array[i]<<" ";
        if(i==binary_max-2){
            binary_max=binary_max*2;
            cout<<endl;
        }
    }
    cout<<endl;
}

void PrintArray(int array[],int length){
    for(int i=0;i<length;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

int Parent(int i){
    return (i-1)/2;
}

int Left(int i){
    return 2*i+1;
}

int Right(int i){
    return 2*i+2;
}

void MaxHeapify(int array[],int index,int array_size){
    int left=Left(index);
    int right=Right(index);
    int largest=index;
    if(left<=array_size&&array[left]>array[largest]){
        largest=left;
    }
    if(right<=array_size&&array[right]>array[largest]){
        largest=right;
    }
    if(largest!=index){
        swap(array[index],array[largest]);
        MaxHeapify(array, largest, array_size);
    }
}

void BuildHeap(int array[], int array_size){
    for(int i=array_size/2;i>=0;i--){
        MaxHeapify(array, i, array_size);
    }
}

void HeapSort(int array[],int array_size){
    int max_size=array_size-1;
    for(int i=array_size-1;i>=1;i--){
        swap(array[0], array[max_size]);
        max_size=max_size-1;
        MaxHeapify(array, 0, max_size);
    }
}

int main(int argc, const char * argv[]) {
    srand((unsigned)time(NULL));
    int array[LENGTH];
    int rand_num;
    for(int i=0;i<LENGTH;i++){
        rand_num=rand()%1000+1;
        array[i]=rand_num;
    }
    
//    int array[]={1,10,7,2,3,1,6,3,5,2,9,9,7,4,9,2};
    
    int array_size=sizeof(array)/sizeof(array[0]);
    cout<<"建立随机堆："<<endl;
    PrintTree(array,array_size);
    BuildHeap(array,array_size);
    cout<<"BuildHeap："<<endl;
    PrintTree(array,array_size);
    HeapSort(array,array_size);
    cout<<"HeapSort："<<endl;
    PrintArray(array,array_size);
    return 0;
}
