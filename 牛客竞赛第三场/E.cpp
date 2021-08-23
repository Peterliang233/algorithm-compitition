/*
考的是一个数论题目，题目比较玄学，n很大，首先，肯定是个结论题目或者打表题目，找到规律即可，
需要用int128
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 i128;
const i128 N = 2e18;
i128 a[5000010];
int tot=0;
int main(){
	a[++tot]=1;
	for(i128 i=2;i<=1000002;i++){
		i128 x=i;
		i128 y=i*i*i;
		i128 k=i*i;
		a[++tot]=y;
		while(1){
			i128 tmp=k*y-x;
			if(tmp>N) break;
			a[++tot]=tmp;
			x=a[tot-1];
			y=a[tot];
		}
	}
	sort(a+1,a+1+tot);
	int t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		int ans=upper_bound(a+1,a+1+tot,n)-a;
		cout<<ans-1<<endl;
	}
	return 0;
}