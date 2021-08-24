/*
一共有n个位置，现在需要选择某一个位置坐人，每次选择坐人的时候会
尽可能和别人间隔得比较远，直到选任何位置旁边都有人为止。
使用DP加记忆化搜索预处理，DP有三个状态，左边坐了人，右边坐了人，左右两边都坐了人。
然后可以进行状态转移。
*/

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int N=1000010;
ll dp[N][3];
ll pre[N][2];

ll qp(ll a,ll b){
	ll c=1;
	while(b){
		if(b&1) c=c*a%mod;
		b>>=1;
		a=a*a%mod; 
	}
	
	return c;
}

ll f(int n,int st){
	if(dp[n][st]!=-1) return dp[n][st];
	int cnt=0;
	
	if(n==0){
		return dp[n][st]=0;
	}
	
	if(st==0){
		if(n==1){
			return dp[n][st]=0;
		}
		cnt=1+f(n-1,2);
	}else if(st==1){
		if(n==1){
			return dp[n][st]=0;
		}
		cnt=1+f(n-1,2);
	}else{
		if(n&1){
			if(n==1) cnt=0;
			else cnt=1+2*f(n/2,2);
		}else{
			if(n==2) cnt=0;
			else cnt=1+f(n/2,2)+f(n/2-1,2);
		}
	}
	
	return dp[n][st]=cnt;
}


int main(){
	int t;
	scanf("%d",&t);
	memset(dp,-1,sizeof(dp));
	for(int i=1;i<=1e6;i++){
		f(i,0);
		f(i,1);
		pre[i][0]=(pre[i-1][0]+dp[i][0])%mod;
		pre[i][1]=(pre[i-1][0]+dp[i][1])%mod;
	}
	while(t--){
		int n;
		scanf("%d",&n);
		
		ll ans=qp(n,mod-2);
		
		ans=ans*(pre[n-1][1]+pre[n-1][0])%mod;
		
		ans=(ans+1)%mod;
		
		printf("%lld\n",ans);
	}
	return 0;
}