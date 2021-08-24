/*
给26个字符每个字符一个权值，然后输出一个字符串，需要找到本质不同的子串当中权值第k小的字符串的权值。
我们可利用二分这个第k小的权值，然后对于每个权值，我们可以找到小于等于这个权值的字符串的个数，根据个数情况
进行二分。判断小于等于某一个权值的个数我们可以利用height数组和后缀数组。
*/
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=1000010;
ll n,k;
char s[N];
int val[30];
int sum[N],m;
int rk1[N],sa[N],tp1[N],tax[N],height[N];
int *rk=rk1, *tp=tp1;

void bucket()  
{
	for(int i=0; i<=m; ++i) tax[i]=0;
	for(int i=1; i<=n; ++i) tax[rk[i]]++;
	for(int i=1; i<=m; ++i) tax[i]+=tax[i-1];
	for(int i=n; i>=1; i--) sa[tax[rk[tp[i]]]--]=tp[i];
}

void get_sa() 
{
	m=128;
	for(int i=1; i<=n; i++) rk[i]=s[i],tp[i]=i;
	bucket();
	for(int w=1,p=0; p<n; m=p,w<<=1)
	{
		p=0;
		for(int i=1; i<=w; i++) tp[++p]=n-w+i;
		for(int i=1; i<=n; i++) 
			if(sa[i]>w) tp[++p]=sa[i]-w;
		bucket();
		swap(tp,rk);
		rk[sa[1]]=p=1;
		for(int i=2;i<=n;++i)
			rk[sa[i]]=(tp[sa[i-1]]==tp[sa[i]] && tp[sa[i-1]+w]==tp[sa[i]+w])?p:++p;
	}
}

void get_ht()
{
	int k=0;
	for(int i=1; i<=n; i++)
	{
		if(k) k--;
		int j=sa[rk[i]-1];
		while(s[i+k]==s[j+k]) ++k;
		height[rk[i]]=k;
	}
}

bool check(int now){
	ll res=0;
	// 按照rk的排名进行从低到高处理 
	for(int i=1;i<=n;i++){
		// 找到最右边的下标 
		int pos=upper_bound(sum+1,sum+1+n,now+sum[i-1])-sum;
		int tmp=pos-i;
		
		res+=tmp-min(tmp,height[rk[i]]);
	}
	
	if(res<k) return false;
	return true;
}


void solve(){
	m=122;
	scanf("%lld %lld",&n,&k);
	scanf("%s",s+1);
	
	for(int i=1;i<=26;i++){
		scanf("%d",&val[i]);
	}
	
	
	
	// 先得到权值的前缀和 
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+val[s[i]-'a'+1];
	}
	
	// 得到后缀数组 
	get_sa();
	
	
	// 得到height数组 
	get_ht();
	
	int l=0,r=1e7+10,mid;
	
	int ans=-1;
	// 枚举第k小的字符串的权值，
	// 如果这样的字符串有大于等于k，那么答案就<mid
	// 否则，答案就会>mid 
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			r=mid-1; 
		}else{
			l=mid+1;
		}
	}
	
	printf("%d\n",ans);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}