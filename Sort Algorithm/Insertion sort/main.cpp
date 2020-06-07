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


#define LENGTH 1000

int main(int argc, const char * argv[]) {
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
        rand_num=rand()%100000+1;
        num[i]=rand_num;
    }
//    cout<<"排序前："<<endl;
//    for(int i=0;i<LENGTH;i++){
//        cout<<num[i]<<endl;
//    }
//    cout<<"排序后："<<endl;
    

    //插入排序 for双嵌套
    for(int i=1;i<LENGTH;i++){
        int num1;
        num1=num[i];
        for(int j=i-1;j>=0;j--){
            if(num1<num[j]){
                num[j+1]=num[j];
                num[j]=num1;
            }
        }
    }
    
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
    
    endTime = clock();
    cout << "Totle Time : " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    
    return 0;
}

