//
//  main.cpp
//  heap
//
//  Created by Sean Yang on 2019/2/27.
//  Copyright © 2019 Sean Yang. All rights reserved.
//

#include <iostream>
#include <cstlib>

int main(int argc, const char * argv[]) {
    //    选择排序 for双嵌套
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

    return 0;
}
