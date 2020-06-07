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

int cost[10][10],a[10][10],i,j,k,c;

int main(){
    
    int n=5,m=5;
    for ( i=1;i<=n;i++){
        for ( j=1;j<m;j++){
            a[i][j]=0;
        }
    }
    a[1][2]=3;
    a[1][3]=8;
    a[1][5]=-4;
    a[2][4]=1;
    a[2][5]=7;
    a[3][2]=4;
    a[4][1]=2;
    a[4][3]=-5;
    a[5][4]=6;

    for ( i=1;i<=n;i++){
        for ( j=1;j<m;j++){
            if (a[i][j]==0 && i!=j)
                a[i][j]=40000;
        }
    }
    
    for (k=1;k<=n;k++)
        for (i=1;i<=n;i++)
            for( j=1;j<=n;j++)
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
    
    cout<<" resultant adj matrix \n";
    for (i=1;i<=n;i++){
        for (j=1;j<=n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
