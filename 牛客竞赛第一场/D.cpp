/*
把一个字符串放进另外一个矩阵里面，要求放的位置都是0，问有多少种放的方式？
这个题目就是一个简单的模拟，我们把放的位置进行一个枚举，可以先预处理这个位置的右边有多少个连续的0，然后遍历即可
*/

#include<bits/stdc++.h>

using namespace std;

char a[2010][2010];
int pre[2010][2010];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    
    for(int i=1;i<=n;i++){
        int sum=0;
        for(int j=n;j;j--){
            if(a[i][j]=='0'){
                sum++;
            }else{
                sum=0;
            }
            pre[i][j]=sum;
        }
    }
    
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(pre[i][j]>=m){
                ans++;
            }
        }
    }
    
    cout<<ans<<endl;
    return 0;
}