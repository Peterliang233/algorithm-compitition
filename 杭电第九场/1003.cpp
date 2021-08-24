/*
给出一个a序列和一个b序列，要求对于a序列中的每个数字，在和b序列的某种匹配的方式下可以得到的
最高排名和最低排名是多少
*/

#include<bits/stdc++.h> 

using namespace std;
const int N=5010;

struct node{
	int val;
	int id;
	int mi,mx;
}a[N];

int b[N];

bool cmp(node x,node y){
	return x.val<y.val;
}

bool cmp1(node x,node y){
	return x.id<y.id;
}

void solve(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].val);
		a[i].id=i;
	}
	
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
	}
	sort(a+1,a+1+n,cmp);
	sort(b+1,b+1+n);
	for(int i=1;i<=n;i++){
		int sum=a[i].val+b[n];
		int l=0,less=0;
		// a数组从大到小开始进行枚举 
		// b数组从小到大开始进行枚举 
		for(int j=n;j;j--){
			if(i!=j){
				bool tag=true;
				while(b[l+1]+a[j].val<=sum&&l+1<n){
					tag=false;
					l++;
				}
				
				if(tag){
					if(less<l){
						less++;
					}
				}else{
					less++; 
				}
			}
		}
		
		a[i].mx=n-less;
		
		sum=a[i].val+b[1];
		
		int r=n+1,more=0;
		
		for(int j=1;j<=n;j++){
			if(i!=j){
				bool tag=true;
				while(b[r-1]+a[j].val>sum&&r-1>1){
					tag=false;
					r--;
				}
				if(tag){
					if(n-r+1>more){
						more++;
					}
				}else{
					more++;
				}
			}
		}
		
		a[i].mi=more+1;
	}
	
	
	sort(a+1,a+1+n,cmp1);
	for(int i=1;i<=n;i++){
		cout<<a[i].mx<<" "<<a[i].mi<<endl;
	}
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		solve();
	}
	return 0;
}