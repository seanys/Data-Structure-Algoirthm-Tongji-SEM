//
//  main.cpp
//  math_include
//
//  Created by Sean Yang on 2019/2/26.
//  Copyright © 2019 Sean Yang. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

int main ()
{
    // 数字定义
    short  s = 10;
    int    i = -1000;
    long   l = 100000;
    float  f = 230.47;
    double d = 200.374;
    
    // 数学运算
    cout << "sin(d) :" << sin(d) << endl;
    cout << "abs(i)  :" << abs(i) << endl;
    cout << "floor(d) :" << floor(d) << endl;
    cout << "sqrt(f) :" << sqrt(f) << endl;
    cout << "pow( d, 2) :" << pow(d, 2) << endl;
    
    return 0;
}
