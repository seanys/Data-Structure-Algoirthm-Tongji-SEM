//
//  main.cpp
//  Merge sort
//
//  Created by Sean Yang on 2019/4/21.
//  Copyright © 2019 Sean Yang. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;
//#define LENGTH=10;

void Merge(int array[], int start, int mid , int end){
    int L[mid-start+1],R[end-mid];
    for(int i=0;i<mid-start+1;i++){
        L[i]=array[start+i];
    }
    for(int i=0;i<end-mid;i++){
        R[i]=array[mid+1+i];
    }
    int j=0,k=0,index=start;
    while(j<mid-start+1&&k<end-mid){
        if(L[j]<R[k]){
            array[index++]=L[j++];
        }else{
            array[index++]=R[k++];
        }
    }
    while(j<mid-start+1)array[index++]=L[j++];
    while(k<end-mid)array[index++]=R[k++];
}

void PrintArray(int array[],int length){
    for(int i=0;i<length;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

void MergeSort(int array[],int start,int end){
    int mid=(start+end)/2;
    if(end>start){
        MergeSort(array,start,mid);
        MergeSort(array,mid+1,end);
        Merge(array, start, mid, end);
    }
}

int main(int argc, const char * argv[]) {
    int array[]={1,10,7,2,3,1,6,3,5,2,9};
//    int array[]={1,3,5,7,9,2,4,7,8,9};
    int array_length=sizeof(array)/sizeof(array[0]);
    cout<<"排序前"<<endl;
    PrintArray(array, array_length);
    MergeSort(array,0,array_length-1);
    cout<<"排序后"<<endl;
    PrintArray(array,array_length);
    return 0;
}

