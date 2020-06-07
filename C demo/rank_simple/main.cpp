//
//  main.cpp
//  rank_simple
//
//  Created by Sean Yang on 2019/2/27.
//  Copyright © 2019 Sean Yang. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

#define LENGTH 20

int *getMergeArray(int arr1[],int arr2[],int max_length_array_a,int max_length_array_b);


int main(int argc, const char * argv[]) {
    srand((unsigned)time(NULL));
    int num[LENGTH];
    int rand_num;
    //生成随机数
    for(int i=0;i<LENGTH;i++){
        rand_num=rand()%100+1;
        num[i]=rand_num;
    }
    cout<<"排序前："<<endl;
//    for(int i=0;i<LENGTH;i++){
//        cout<<num[i]<<endl;
//    }
    cout<<"排序后："<<endl;
    
    //MERGE SORT
    
//    for(int i;i<LENGTH;i++){
//
//    }
    
    int a[]={1,50,90};
    int max_length_array_a=sizeof(a)/4;
    int b[]={2,10,20};
    int max_length_array_b=sizeof(b)/4;
    int *c;
    c=getMergeArray(a,b,max_length_array_a,max_length_array_b);
//    cout<<*c<<endl;
    for(int i=0;i<max_length_array_a+max_length_array_b;i++){
        cout<<*(c+i)<<endl;
    }
    



    //插入排序 for双嵌套
//    for(int i=1;i<LENGTH;i++){
//        int num1;
//        num1=num[i];
//        for(int j=i-1;j>=0;j--){
//            if(num1<num[j]){
//                num[j+1]=num[j];
//                num[j]=num1;
//            }
//        }
//    }
    
    //插入排序，for-while嵌套
//    for(int i=1;i<LENGTH;i++){
//        int num1;
//        num1=num[i];
//        int j=i-1;
//        while(num1<num[j]&&j>=0){
//            num[j+1]=num[j];
//            num[j]=num1;
//            j--;
//        }
//    }

    
//    for(int i=0;i<LENGTH;i++){
//        cout<<num[i]<<endl;
//    }

    return 0;
}

// 要生成和返回随机数的函数
int * getMergeArray(int arr1[],int arr2[],int max_length_array_a,int max_length_array_b)
{
    int index_of_a=0,index_of_b=0;
    int merge_length=max_length_array_a+max_length_array_b;
    int array_merge[merge_length];
    int array_merge_index=0;
    //进行数组合并
    for(array_merge_index=0;array_merge_index<merge_length;array_merge_index++){
        if(index_of_a<max_length_array_a&&index_of_b<max_length_array_b){
            if(*(arr1+index_of_a)<*(arr2+index_of_b)){
                array_merge[array_merge_index]=*(arr1+index_of_a);
                index_of_a++;
            }else{
                array_merge[array_merge_index]=*(arr2+index_of_b);
                index_of_b++;
            }
        }else{
            if(index_of_a==max_length_array_a){
                array_merge[array_merge_index]=*(arr2+index_of_b);
                index_of_b++;
            }else{
                array_merge[array_merge_index]=*(arr1+index_of_a);
                index_of_a++;
            }
        }
    }
    for(array_merge_index=0;array_merge_index<merge_length;array_merge_index++){
        cout<< array_merge[array_merge_index] <<endl;
    }
//    cout<<sizeof*arr1+1<<endl;
//    int size1=sizeof(*arr1);
//    int size2=sizeof(*arr2);

    return array_merge;
}
