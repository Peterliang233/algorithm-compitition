/*
题解
有点类似与博弈论的味道，但是其实可以直接暴力打表冲，令人意外的是这个题目
竟然可以开三个5000的for循环
*/

#include<bits/stdc++.h>
using namespace std;
bool vis[5010][5010];
int main(){
    for(int i=0;i<=5000;i++){
        for(int j=0;j<=5000;j++){
            if(!vis[i][j]){
                for(int k=1;k+i<=5000;k++){
                    for(int q=0;q*k+j<=5000;q++){
                        vis[k+i][q*k+j]=1;
                    }
                }
                for(int k=1;k+j<=5000;k++){
                    for(int q=0;q*k+i<=5000;q++){
                        vis[q*k+i][k+j]=1;
                    }
                }
            }
        }
    }
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        if(vis[n][m]||vis[m][n])  puts("Alice");
        else puts("Bob");
    }
    return 0;
}