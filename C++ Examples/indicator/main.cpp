//
//  main.cpp
//  indicator
//
//  Created by Sean Yang on 2019/2/26.
//  Copyright © 2019 Sean Yang. All rights reserved.
//

#include <iostream>

using namespace std;

int main ()
{
    int  var1;
    char var2[10];
    int *var3; //var3是指针，是一个地址，*var是指向的对象
    
    cout << "var1 变量的地址： ";
    cout << &var1 << endl;
    
    cout << "var2 变量的地址： ";
    cout << &var2 << endl;
    
    cout << "var3:" ;
    cout << var3 << endl;
    
    cout << "*var3:" ;
    cout << &var3 << endl;
    
    int var4 = 4;
    var3 = &var4; //把var4的地址画赋值到var3
    cout << var3 << endl;
    cout << *var3 << endl; //var3 is a indicator, appear as a address, *var3 is the address's indicated value
    
    return 0;
}
