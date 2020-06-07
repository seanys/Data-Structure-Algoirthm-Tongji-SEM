
/* Merge sort in C++ */
#include <cstdio>
#include <iostream>

using namespace std;

#define LENGTH 1000000

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
    if(n < 2) return; // base condition. If the array has less than two element, do nothing.
    
    mid = n/2;  // find the mid index.
    
    L = new int[mid];
    R = new int [n - mid];
    
    for(i = 0;i<mid;i++) L[i] = A[i]; // creating left subarray
    for(i = mid;i<n;i++) R[i-mid] = A[i]; // creating right subarray
    
    MergeSort(L,mid);  // sorting the left subarray
    MergeSort(R,n-mid);  // sorting the right subarray
    Merge(A,L,mid,R,n-mid);  // Merging L and R into A as sorted list.
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
    
    
//    int A[] = {6,2,3,1,9,10,15,13,12,17}; // creating an array of integers.
//    int i,numberOfElements;

//    numberOfElements = sizeof(A)/sizeof(A[0]);
    
    MergeSort(list,LENGTH);
    
//    for(int i = 0;i < LENGTH;i++)
//        cout << " " << list[i];
    
    endTime = clock();
    cout << "Totle Time : " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    return 0;
}
