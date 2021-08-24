/*
给定一个a序列和b序列，需要我们构造一个c序列，这个序列满足ck=max{ai*bj}(i&j>k)
思路：
我们还是采用按位进行拆解的方法，首先，我们从高位开始进行处理，对于高位的每个下标，我们对这个下标按位进行拆解，
同时我们维护a和b数组的出现的最大值和最小值（因为这里存在负数，最值就会由四种情况，最大值和最大值，最小值和最小值，最大值和最小值以及最小值和最大值。维护好了之后，我们按位进行拆解，如果这个位为0，那么我们就把这个位补成1，然后我们维护出现过的最大值和最小值，同时因为是倒序枚举，所以，我们把这个就确保了出现过的数字的与一定会大于k。
*/

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=1<<19;
const int mod=998244353;
ll a[N],b[N];
ll mxa[N],mia[N];
ll mxb[N],mib[N];

void solve(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%lld",&b[i]);
	}
	
	ll ans=0;
	ll mx=-2e18;
	
	
	// 枚举这个位置的数字 
	for(int i=n-1;i>=0;i--){
		mxa[i]=mia[i]=a[i];
		mxb[i]=mib[i]=b[i];
		
		// 从低位开始向高位进行枚举 
		for(int j=0;j<=18;j++){
			// 枚举这位的所有的位数 
			// 如果i的第j位是0，那么i&j的这一位一定是0 
			if(((i>>j)&1)==0){
				int x=i+(1<<j);  // 我们让x的这个位置为1 
				if(x<n){
					mxa[i]=max(mxa[i],mxa[x]);
					mxb[i]=max(mxb[i],mxb[x]);
					mia[i]=min(mia[i],mia[x]);
					mib[i]=min(mib[i],mib[x]);
				}
			}
		}
			
		if(i==n-1){
			mx=a[i]*b[i];
		}
		
		mx=max(mx,max(mxa[i]*mxb[i],mia[i]*mib[i]));
		mx=max(mx,mxa[i]*mib[i]);
		mx=max(mx,mxb[i]*mia[i]);
		ans=(ans+mx)%mod;
	}
	
	ans=(ans%mod+mod)%mod;
	
	printf("%lld\n",ans%mod);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}