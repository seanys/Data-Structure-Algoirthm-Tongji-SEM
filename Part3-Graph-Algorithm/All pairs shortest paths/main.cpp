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

int a[10][10],b[10][10],mid[10][10],i,j,k,c;
int n=6,m=6;
int path_length=0;

void CopyArray(int a[10][10],int b[10][10]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            b[i][j]=a[i][j];
        }
    }
}

void ExtendShortestPaths(){
    CopyArray(a,b);
    for (i=0;i<n;i++){
        for( j=0;j<n;j++){
            for (k=0;k<n;k++){
                if(a[i][j]>b[i][k]+b[k][j]){
                    mid[i][j]=k;
                    a[i][j]=b[i][k]+b[k][j];
                }
            }
        }
    }
}

void PrintMatrix(){
    cout<<"输出结果：\n";
    for (i=0;i<n;i++){
        cout<<"第"<<i<<"行：";
        for (j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

void PrintMid(){
    cout<<"输出mid：\n";
    for (i=0;i<n;i++){
        cout<<"第"<<i<<"行：";
        for (j=0;j<n;j++){
            cout<<mid[i][j]<<" ";
        }
        cout<<endl;
    }
}

void PrintMidNode(int i,int j){
    if(mid[i][j]>=0&&i!=j){
        PrintMidNode(i, mid[i][j]);
        cout<<mid[i][j]<<"-";
        PrintMidNode(mid[i][j], j);
    }
}

void PrintPath(int i,int j){
    cout<<i<<"-";
    PrintMidNode(i,j);
    cout<<j<<endl;
}


int main(){
    for ( i=0;i<n;i++){
        for ( j=0;j<m;j++){
            a[i][j]=0;
            mid[i][j]=-1;
        }
    }
    
    a[0][1]=3;
    a[0][2]=8;
    a[0][4]=-4;
    
    a[1][3]=1;
    a[1][4]=7;
    
    a[2][1]=4;
    a[2][5]=4;

    a[3][0]=2;
    a[3][2]=-5;
    
    a[4][3]=6;
    a[4][5]=2;
    
    a[5][3]=3;
    
    for ( i=0;i<n;i++){
        for ( j=0;j<n;j++){
            if (a[i][j]==0 && i!=j)
                a[i][j]=40000;
        }
    }
    
    PrintMatrix();
    int t=1;
    while(t<n){
        PrintMid();
        PrintMatrix();
        ExtendShortestPaths();
        t=t*2;
    }
    
    PrintMid();
    PrintMatrix();
    cout<<"路径,:"<<endl;
    for ( i=0;i<n;i++){
        for ( j=0;j<n;j++){
            if(i!=j){
                PrintPath(i, j);
            }
        }
    }
    
    return 0;
}
