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
    
    
    for(int i=0;i<LENGTH-1;i++){
        int min=num[i],min_index=0;
        int u=0;
        for(int j=i;j<LENGTH;j++){
            if(num[j]<min){
                min=num[j];
                min_index=j;
                u=1;
            }
        }
        if(u==1){
            int t=num[i];
            num[i]=num[min_index];
            num[min_index]=t;
        }
    }
        
        
    for(int i=0;i<LENGTH;i++){
        cout<<num[i]<<endl;
    }
    
    return 0;
}

