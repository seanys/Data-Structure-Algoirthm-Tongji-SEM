#include <iostream>
#include <ctime> //时间time()标准库
#include <cstdlib> //NULL值的标准库

using namespace std;

int main ()
{
    int i,j;
    
    // 设置种子
    srand( (int)time( NULL ) );
    
    //必须设置种子，否则系统默认的设置是1
    
//    /* 生成 10 个随机数 */
//    for( i = 0; i < 10; i++ )
//    {
        // 生成实际的随机数
        j= rand();
        cout <<"随机数： " << j << endl;
//    }
    
    srand( (unsigned)time( NULL ) );
    
    /* 生成 10 个 0-19 的随机整数 */
    //相当于使用ssc整除
    for( i = 0; i < 40; i++ )
    {
        // 生成实际的随机数
        j= rand()%20;
        cout <<"随机数： " << j << endl;
    }
    
    //10-29
    for( i = 0; i < 10; i++ )
    {
        // 生成实际的随机数
        j= rand()%20+10;
        cout <<"随机数： " << j << endl;
    }
    
    return 0;
}
