//
//  main.cpp
//  array_indicator
//
//  Created by Sean Yang on 2019/2/26.
//  Copyright © 2019 Sean Yang. All rights reserved.
//

#include <iostream>
using namespace std;

//使用命名空间
#include <iomanip>
using std::setw;

int main() {
    //第一种i形式
    double balance0[10];
    //此处输出空格
    cout<<balance0[0]<<setw(8)<<1<<endl; //此处赋值为空
    //第二种形式
    double balance1[5] = {1000.0, 2.0, 3.4, 7.0, 50.0};
    cout<<balance1[0]<<endl;
    return 0;
}
