//
//  main.cpp
//  Radix Sort
//
//  Created by 爱学习的兔子 on 2020/6/11.
//  Copyright © 2020 Yang Shan. All rights reserved.
//

#include <iostream>

//计数排序，npRadix为对应的关键字序列，nMax是关键字的范围。npData是具体要
//排的数据，nLen是数据的范围，这里必须注意npIndex和npData对应的下标要一致
//也就是说npIndex[1] 所对应的值为npData[1]
int RadixCountSort(int* npIndex, int nMax, int* npData, int nLen)
{
    //这里就不用说了，计数的排序。不过这里为了是排序稳定
    //在标准的方法上做了小修改。
    
    int* pnCount  = (int*)malloc(sizeof(int)* nMax);        //保存计数的个数
    for (int i = 0; i < nMax; ++i)
    {
        pnCount[i] = 0;
    }
    for (int i = 0; i < nLen; ++i)    //初始化计数个数
    {
        ++pnCount[npIndex[i]];
    }
    
    for (int i = 1; i < 10; ++i)  //确定不大于该位置的个数。
    {
        pnCount[i] += pnCount[i - 1];
    }
    
    int * pnSort  = (int*)malloc(sizeof(int) * nLen);    //存放零时的排序结果。
    
    //注意：这里i是从nLen-1到0的顺序排序的，是为了使排序稳定。
    for (int i = nLen - 1; i >= 0; --i)
    {
        --pnCount[npIndex[i]];
        pnSort[pnCount[npIndex[i]]] = npData[i];
    }
    
    for (int i = 0; i < nLen; ++i)        //把排序结构输入到返回的数据中。
    {
        npData[i] = pnSort[i];
    }
    free(pnSort);                        //记得释放资源。
    free(pnCount);
    return 1;
}

//基数排序
int RadixSort(int* nPData, int nLen)
{
    //申请存放基数的空间
    int* nDataRadix    = (int*)malloc(sizeof(int) * nLen);
    
    int nRadixBase = 1;    //初始化倍数基数为1
    bool nIsOk = false; //设置完成排序为false
    
    //循环，知道排序完成
    while (!nIsOk)
    {
        nIsOk = true;
        nRadixBase *= 10;
        for (int i = 0; i < nLen; ++i)
        {
            nDataRadix[i] = nPData[i] % nRadixBase;
            nDataRadix[i] /= nRadixBase / 10;
            if (nDataRadix[i] > 0)
            {
                nIsOk = false;
            }
        }
        if (nIsOk)        //如果所有的基数都为0，认为排序完成，就是已经判断到最高位了。
        {
            break;
        }
        RadixCountSort(nDataRadix, 10, nPData, nLen);
    }
    
    free(nDataRadix);
    
    return 1;
}

int main()
{
    //测试基数排序。
    int nData[10] = {123,5264,9513,854,9639,1985,159,3654,8521,8888};
    RadixSort(nData, 10);
    for (int i = 0; i < 10; ++i)
    {
        printf("%d ", nData[i]);
    }
    printf("\n");
    
    return 0;
}
