/*
可以发现最多使用一次预测，其余就是按照大小的顺序进行排列，小的分配大的概率，大的分配小的概率即可
*/
#include<bits/stdc++.h>
using namespace std;
double c[100010];
int main(){
	int n;
	cin>>n;
	double s;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	sort(c+1,c+1+n);
	
	for(int i=1;i<=n;i++){
		c[i]=c[i-1]+c[i];
	}
	double sum=0;
	for(int i=1;i<n;i++){
		sum+=c[i]*pow(2,i-n);
	}
	sum+=s;
	printf("%.10lf\n",min(sum,c[n]));
	return 0;
}