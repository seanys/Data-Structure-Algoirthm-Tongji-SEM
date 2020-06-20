//
//  main.cpp
//  struct
//
//  Created by Sean Yang on 2019/2/27.
//  Copyright © 2019 Sean Yang. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

struct BOOKS{
    char name[50];
    char author[50];
    int  book_id;
};

int main(int argc, const char * argv[]) {
    BOOKS book1;
    BOOKS book2;
//    book1.name="测试直接输入name";
    strcpy(book1.author,"测试复制名称");
    cout<<book1.name<<endl;
    cout<<book1.author<<endl;
    
    //测试参数传递
    char name_test[50];
    strcpy(name_test,"测试名称复制");
    strcpy(book2.name,name_test);
    strcpy(book2.author,name_test);
    cout<<book2.name<<endl;
    cout<<book2.author<<endl;
    
    return 0;
}
