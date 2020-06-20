//
//  main.cpp
//  Buble sort
//
//  Created by Sean Yang on 2019/2/27.
//  Copyright © 2019 Sean Yang. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;


#define LENGTH 100

int main(int argc, const char * argv[]) {
    srand((unsigned)time(NULL));
    int num[LENGTH];
    int rand_num;
    //生成随机数
    for(int i=0;i<LENGTH;i++){
        rand_num=rand()%1000+1;
        num[i]=rand_num;
    }
    cout<<"排序前："<<endl;
    for(int i=0;i<LENGTH;i++){
        cout<<num[i];
        cout<<'\t';
    }
    cout<<endl;
    cout<<"排序后："<<endl;
    
    
    for(int i=0;i<LENGTH;i++){
        for(int j=LENGTH-1;j>i;j--){
            if(num[j]<num[j-1]){
               swap(num[j], num[j-1]);
            }
        }
    }
    
    for(int i=0;i<LENGTH;i++){
        cout<<num[i]<<'\t';
    }
     cout<<endl;
    
    return 0;
}

