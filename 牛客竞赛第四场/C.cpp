/*
进行构造，首先将三个字符的lcs进行从大到小进行排序a,b,c，若a+b-c>n,那么说明是没有符合情况的;
否则，首先就是先最大的赋值给三个字符串，然后将
最长的剩余的分给前两个，将第二场的分给后两个，最后在进行剩余的分配

*/

#include<bits/stdc++.h>
using namespace std;
string ans[5];
int a,b,c,n;
int num[4];
int dp[1010][1010];
int LCS(string x,string y){
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(x[i-1]==y[j-1]){
            	dp[i][j]=dp[i-1][j-1]+1;
			}else{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
        }
    }
    return dp[n][n];
}
bool judge(string x,string y,string z){
    int k1=LCS(x,y);
    int k2=LCS(y,z);
    int k3=LCS(z,x);
//    cout<<x<<endl;
//    cout<<y<<endl;
//    cout<<z<<endl;
//    cout<<k1<<" "<<k2<<" "<<k3<<endl;
    if(k1==a&&k2==b&&k3==c) return true;
    return false;
}
int main(){
    cin>>a>>b>>c>>n;
    num[1]=a,num[2]=b,num[3]=c;
    sort(num+1,num+4);
    reverse(num+1,num+4);
    if(num[1]+num[2]-n>num[3]){
        puts("NO");
        return 0;
    }
    for(int i=1;i<=3;i++){
        for(int j=1;j<=num[3];j++){
            ans[i]+="a";
        }
    }
    for(int i=1;i<3;i++){
        for(int j=1;j<=num[1]-num[3];j++){
            ans[i]+="b";
        }
    }
    for(int i=2;i<=3;i++){
        for(int j=1;j<=num[2]-num[3];j++){
            ans[i]+="c";
        }
    }
    for(int i=num[1]+1;i<=n;i++){
        ans[1]+="d";
    }
    for(int i=num[2]+num[1]-num[3]+1;i<=n;i++){
        ans[2]+="e";
    }
    for(int i=num[2]+1;i<=n;i++){
        ans[3]+="f";
    }
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            for(int k=1;k<=3;k++){
                if(i==j||j==k||i==k) continue;
                if(judge(ans[i],ans[j],ans[k])){
                    cout<<ans[i]<<endl;
                    cout<<ans[j]<<endl;
                    cout<<ans[k]<<endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}