/*
数论题，给出一个集合S，需要计算这个集合的所有子集和的最大公因数的乘积.最后的结果modP。
首先，我们可以枚举集合的最大公因数，考虑每个因子对最后的答案的贡献。假如对于某一个质因子g，如果在
集合里面存在m个是这个g的倍数，那么g对答案的贡献就是C(k,m)？显然不是，因为可能存在g的倍数，比如G=ng(n是整数)，
那么，其实最大公因数就是G了，而不是g，所以我们需要减去这些部分。假设，对于g的倍数ng的数G，集合里面存在nm个这个G的倍数，那么最后的结果就是C(k,m)-C(k,2m)-C(k,3m)...-C(k,nm)，这样就是单独的g对答案的贡献了。
*/

#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
ll P;
ll s,k,a[400010];
ll c[400010][35];
ll f[100010];
ll prime[10000010];
ll add(ll x,ll y,ll mod){
	ll z=x+y;
	return z>=mod?z-mod:z;
}
// 进行快速幂的计算 
ll qp(ll a,ll b){
	ll c=1;
	while(b){
		if(b&1) c=c*a%P;
		a=a*a%P;
		b>>=1;
	}
	return c;
}

// 初始化利用欧拉筛求出所有的质因数 
void init(int L){
	vector<int> vis(L+1,0);
	for(int i=2;i<=L;i++){
		if(!vis[i]){
			prime[++prime[0]]=i;
		}
		for(ll j=1;j<=prime[0]&&i*prime[j]<=L;j++){
			vis[i*prime[j]]=1;
			if(i%prime[j]==0) break;
		}
	}
}

// 计算欧拉函数 
ll phi(ll n){
	ll ans=n;
	for(int i=1;i<=prime[0];i++){
		if(n%prime[i]==0){
			while(n%prime[i]==0){
				n/=prime[i];
			}
			ans=ans/prime[i]*(prime[i]-1);
		}
	}
	if(n>1) ans=ans/n*(n-1);
	return ans;
}

void solve(){
	memset(f,0,sizeof(f));
	cin>>s>>k>>P;
	ll pi=phi(P),m=0,ans=1;
	for(int i=0;i<=s;i++){
		c[i][0]=1;
	}
	// 由于p不是质数，那么就暴力求出杨辉三角 
	for(ll i=1;i<=s;i++){
		for(ll j=1;j<=min(i,k);i++){
			c[i][j]=add(c[i-1][j],c[i-1][j-1],pi);
		}
	}
	
	
	for(int i=1;i<=s;i++) {
		cin>>a[i];
		m=max(m,a[i]);
		f[a[i]]++;
	}
	
	// 枚举所有的gcd，求出每个i对应的有多少个ti，f[i]存储了存在因数i的数的个数 
	for(int i=1;i<=m;i++){
		for(int j=2*i;j<=m;j+=i){
			f[i]+=f[j];
		}
	}
	
	
	// 对于每一个gcd，在所有能被i整除的数里面选出k个数 
	for(int i=1;i<=m;i++){
		f[i]=c[f[i]][k];
	}
	
	
	for(int i=1,p;(p=prime[i])<=m;++i){
		for(ll j=p*p;j<=m;j*=p){
			f[p]+=f[j];
			f[p]>=pi?f[p]-=pi:0;
		}
		ans=ans*qp(p,f[p])%P;
	}
	
	cout<<ans<<endl;
}
int main(){
	init(1e7);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}