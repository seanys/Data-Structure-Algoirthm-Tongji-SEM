//
//  main.cpp
//  Quick sort
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

void PrintArray(int array[],int length){
    for(int i=0;i<length;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

int Partition(int array[], int start, int end){
    int min_border=start-1;
    int partion_value=array[end];
    for(int i=start;i<end;i++){
        if(array[i]<partion_value){
            min_border=min_border+1;
            swap(array[min_border], array[i]);
        }
    }
    min_border=min_border+1;
    swap(array[min_border],array[end]);
    return min_border;
}

int RandomPartiton(int array[],int start, int end){
    srand((unsigned)time(NULL));
    int i=rand()%(end-start+1)+start;
    swap(array[i], array[end]);
    return Partition(array,start,end);
}

void QuickSort(int array[],int start, int end){
    if(start<end){
//        int partition=Partition(array, start, end);
        int partition=RandomPartiton(array, start, end);
//        PrintArray(array, 14);
        QuickSort(array, start , partition-1);
        QuickSort(array, partition+1 , end);
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
    
//    int array[]={1,10,7,2,3,1,6,3,5,2,9,9,7,4,9,5};
    int array_size=sizeof(array)/sizeof(array[0]);
    cout<<"初始数组："<<endl;
    PrintArray(array, array_size);
//    Partition(array, 0, array_size-1);
    QuickSort(array, 0, array_size-1);
    cout<<"排序后数组："<<endl;
    PrintArray(array, array_size);
    
    return 0;
}
