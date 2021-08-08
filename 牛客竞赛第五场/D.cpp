/*
就是求两个字符串的某两个位置相同前缀的个数乘上后面A字符串
小于B字符串的个数后面剩余的就随机进行选取
*/

#include<bits/stdc++.h> 

using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int N=5010;

char a[N],b[N];
int dp[N][N],w[N][N];
int main(){
	scanf("%s%s",a+1,b+1);
	int n=strlen(a+1);
	int m=strlen(b+1);
    dp[0][0]=w[0][0]=1;
	for(int i=1;i<N;i++){
		dp[i][0]=dp[0][i]=w[0][i]=w[i][0]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			w[i][j]=(w[i][j-1]+w[i-1][j])%mod;
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			dp[i][j]=((ll)dp[i-1][j]+dp[i][j-1]-((a[i]!=b[j])?dp[i-1][j-1]:0))%mod;
		}
	}
	
	ll ans=0;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
            // 枚举两个字符串的这两个位置是否满足题目的条件
			if(a[i]<b[j]){
				ll tmp=(ll)dp[i-1][j-1]*w[n-i][m-j]%mod;
				ans=(ans+tmp)%mod;
			}
		}
	}
	printf("%lld\n",(ans+mod)%mod);
	return 0;
}