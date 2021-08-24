/*
一个背包题目，首先，每门课有一个最高分限制，同时允许出现若干门课程不及格，
需要我们判断在控制及格的前提下最多可以得到多少分？
对于每门课程，我们先通过01背包得到复习i天最多得到多少分数，用f数组表示，然后在学习第i门课程的情况下
，我们枚举复习j天，挂k门课程得到的最高得分。由目前已经得到的dp方程转移过来。最后就是维护最大值就行了
*/

#include<bits/stdc++.h>

using namespace std;

int dp[550][10],ddp[550][10]; // dp[i][j]表示学习i天，挂j门的最高得分

int f[550];  // f[i]表示学习i天得到的最高的得分

map<string,int> mp;
vector<pair<int,int> > a[55];
void solve(){
	mp.clear();
	int n;
	cin>>n;
	
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		mp[s]=i;
		a[i].clear();
	}
	int m;
	cin>>m;
	for(int i=1;i<=m;i++){
		string s;
		cin>>s;
		int id=mp[s];
		int x,y;
		cin>>x>>y;
		a[id].push_back(make_pair(x,y));
	}
	
	int t,p;
	cin>>t>>p;
	
	memset(dp,-1,sizeof(dp));
	dp[0][0]=0;
	p=min(n,p);
	for(int i=1;i<=n;i++){
		memset(f,0,sizeof(f));
		
		// 对于这门课程，学习t天中每天最多得到多少分数 
		for(auto x:a[i]) {
			for(int j=t;j>=x.second;j--){
				f[j]=max(f[j],min(100,f[j-x.second]+x.first));
			}
		}
		
		memset(ddp,-1,sizeof(ddp));  // ddp是一个临时的dp状态，使得可以由之前的转移过来 
		
		
		// 枚举对于j天，挂了k门课程的最高得分 
		for(int j=0;j<=t;j++){
			for(int k=0;k<=p;k++){
				if(dp[j][k]==-1) continue; // 如果这个状态还没有 
				
				// 从之前计算过得到的dp中进行转移 
				for(int d=0;d<=t;d++){
					int nx=k;
					if(f[d]<60) nx=k+1;
					if(j+d<=t&&nx<=p) {
						ddp[j+d][nx]=max(ddp[j+d][nx],dp[j][k]+f[d]);  // 当前的由之前的状态转移过来 
					}
				}
			}
		}
		
		for(int j=0;j<=t;j++){
			for(int k=0;k<=p;k++){
				dp[j][k]=ddp[j][k];
			}
		}
		
	}
	
	int ans=-1;
	for(int i=0;i<=t;i++){
		for(int j=0;j<=p;j++){
			ans=max(ans,dp[i][j]);
		}
	}
	
	cout<<ans<<endl;
}

int main(){
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}