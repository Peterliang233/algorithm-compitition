/*
分别对两个方向进行处理，通过二分最后的值，
利用差值进行判断
*/
#include<bits/stdc++.h> 
#define eps 1e-8
using namespace std;
typedef long long ll;
int n,m,x,y;
double a[100010],b[100010],c[100010],sum[100010];
bool judge1(double mid){
	for(int i=1;i<=n;i++){
		c[i]=a[i]-mid;
	}
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+c[i];
	}
	double mi=1e9,mx=-1e9;
	for(int i=x;i<=n;i++){
		mi=min(mi,sum[i-x]);
		mx=max(mx,sum[i]-mi);
	}
	return mx>=0;
}
bool judge2(double mid){
	for(int i=1;i<=m;i++){
		c[i]=b[i]-mid;
	}
	for(int i=1;i<=m;i++){
		sum[i]=sum[i-1]+c[i];
	}
	double mi=1e9,mx=-1e9;
	for(int i=y;i<=m;i++){
		mi=min(mi,sum[i-y]);
		mx=max(mx,sum[i]-mi);
	}
	return mx>=0;
}

int main(){
	cin>>n>>m>>x>>y;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cin>>b[i];
	}
	double l=0,r=1000000.0,mid;
	while(r-l>eps){
		mid=(l+r)/2.0;
		if(judge1(mid)) l=mid;
		else r=mid;
	}
	double res1=r;
	l=0,r=1000000.0,mid;
	while(r-l>eps){
		mid=(l+r)/2.0;
		if(judge2(mid)) l=mid;
		else r=mid;
	}
	double res2=r;
	double ans=res1+res2;
	printf("%.10lf\n",ans);
	return 0;
}