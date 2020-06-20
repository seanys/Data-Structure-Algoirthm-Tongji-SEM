//
//  main.cpp
//  Merge Sort
//
//  Created by Sean Yang on 2019/3/20.
//  Copyright © 2019 Sean Yang. All rights reserved.
//

#include <cstdio>
#include <iostream>

using namespace std;

#define LENGTH 100

void Merge(int *A,int *L,int leftCount,int *R,int rightCount) {
    int i,j,k;
    
    i = 0; j = 0; k =0;
    
    while(i<leftCount && j< rightCount) {
        if(L[i]  < R[j]) A[k++] = L[i++];
        else A[k++] = R[j++];
    }
    while(i < leftCount) A[k++] = L[i++];
    while(j < rightCount) A[k++] = R[j++];
}

void MergeSort(int *A,int n) {
    int mid,i, *L, *R;
    if(n < 2) return;
    
    mid = n/2;  // 寻找中点
    
    L = new int[mid];
    R = new int [n - mid];
    
    for(i = 0;i<mid;i++) L[i] = A[i]; // 左侧
    for(i = mid;i<n;i++) R[i-mid] = A[i]; // 右侧
    
    MergeSort(L,mid);  // 左侧排序
    MergeSort(R,n-mid);  // 右侧排序
    Merge(A,L,mid,R,n-mid);
    delete [] R;
    delete [] L;
}

int main() {
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
    
    MergeSort(list,LENGTH);
    
    for(int i = 0;i < LENGTH;i++)
        cout << " " << list[i];
    
    endTime = clock();
    cout << "Totle Time : " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    return 0;
}
