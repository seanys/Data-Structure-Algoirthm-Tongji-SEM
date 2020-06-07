//
//  main.cpp
//  All pairs shortest paths
//
//  Created by Sean Yang on 2019/5/26.
//  Copyright © 2019 Sean Yang. All rights reserved.
//

#include<iostream>

using namespace std;

int Min(int a,int b){
    return a<=b? a:b;
}

int a[10][10],mid[10][10],par[10][10],i,j,k,c;
int n=6,m=6;

void ExtendShortestPaths(){
    for (i=0;i<n;i++)
        for( j=0;j<n;j++)
            for (k=0;k<n;k++){
                if(a[i][j]>a[i][k]+a[k][j]){
                    if(k!=i&&k!=j){
                        par[i][j]=k;
                    }
                    a[i][j]=a[i][k]+a[k][j];
                }
            }
}

void PrintMatrix(){
    cout<<"输出结果：\n";
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

void PrintPar(){
    cout<<"输出par：\n";
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            cout<<par[i][j]<<" ";
        }
        cout<<endl;
    }
}

void NewPrintPath(int i,int j){
    cout<<i<<"-";
    if(par[i][j]>0){
        NewPrintPath(i,par[i][j]);
        NewPrintPath(par[i][j],j);
    }
    cout<<j<<endl;
}

int main(){
    
    for ( i=0;i<n;i++){
        for ( j=0;j<m;j++){
            a[i][j]=0;
        }
    }
    
    a[0][1]=3;
    a[0][2]=8;
    a[0][4]=-4;
    a[1][4]=7;
    a[1][3]=1;
    a[2][1]=4;
    a[3][0]=2;
    a[3][2]=-5;
    a[4][3]=6;
    a[2][5]=4;
    a[4][5]=2;
    a[5][3]=3;
    
    for ( i=0;i<n;i++){
        for ( j=0;j<n;j++){
            if (a[i][j]!=0){
                par[i][j]=j;
            }
        }
    }
    for ( i=0;i<n;i++){
        for ( j=0;j<n;j++){
            if (a[i][j]==0 && i!=j){
                a[i][j]=40000;
            }
        }
    }
    
    int t=1;
    while(t<n){
        ExtendShortestPaths();
        t=t*2;
    }
    
    PrintPar();
    PrintMatrix();
    cout<<"路径:"<<endl;
//    for ( i=0;i<n;i++){
//        for ( j=0;j<n;j++){
//            if(i!=j){
//                NewPrintPath(i, j);
//            }
//        }
//    }
//    
    return 0;
}
