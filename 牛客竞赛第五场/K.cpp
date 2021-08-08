/*
查找一个序列里面满足条件的区间的个数，要求这个区间的最大值和最小值的差值需要大于给定的数字k，多次询问
做法：
维护两个单调队列，一个维护最大，另一个维护最小，因为区间的个数是固定的，所以我们维护区间最大与最小的差值小于等于k的情况，
然后我们两个队列的对首一旦相差k，那么记录下这个区间的长度。
*/
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int a[100010];

deque<int> mi,mx;
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	while(m--){
		while(!mx.empty()) mx.pop_back();
		while(!mi.empty()) mi.pop_back();
		int k;
		cin>>k;
		ll ans=0;
		int l,r; 
		for(l=1,r=1;r<=n;r++){
			// 维护mx这个单调队列里面的数据都大于a[r] 
			while(!mx.empty()&&mx.back()<a[r]) mx.pop_back();
			mx.push_back(a[r]);
			// 维护一个单调递减的单调队列 
			while(!mi.empty()&&mi.back()>a[r]) mi.pop_back();
			mi.push_back(a[r]);
			while(!mx.empty()&&!mi.empty()&&mx.front()-mi.front()>k){
				ans+=(r-l);
				if(mx.front()==a[l]) mx.pop_front();
				if(mi.front()==a[l]) mi.pop_front();
				l++;
			}
		}
		while(l<=n){
			ans+=(r-l);
			l++;
		}
		ll res=(ll)n*(n+1)/2;
		printf("%lld\n",res-ans);
	}
	return 0;
}