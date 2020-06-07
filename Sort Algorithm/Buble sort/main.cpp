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
    for(int i=0;i<LENGTH;i++){
        cout<<num[i]<<endl;
    }
    cout<<"排序后："<<endl;
    
    
    int key=0;
    while(key==0){
        key=1;
        for(int i=0;i<LENGTH-1;i++){
            if(num[i]>num[i+1]){
                int t=num[i];
                num[i]=num[i+1];
                num[i+1]=t;
                key=0;
            }
        }
    }
    
    for(int i=0;i<LENGTH;i++){
        cout<<num[i]<<endl;
    }
    
    return 0;
}

