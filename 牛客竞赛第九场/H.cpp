/*
按位进行拆分就行了，
*/
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll num[20],sum[20];

int main(){
	
	num[0]=1;
	for(int i=1;i<20;i++){
		num[i]=num[i-1]*3ll;
	}
	
	for(int i=1;i<20;i++){
		sum[i]=sum[i-1]+num[i];
	}
	
	
	ll n;
	cin>>n;
	
	// 确定这个数的区间范围
	int k=0;
	for(int i=1;;i++){
		ll tmp=sum[i-1]+num[i];
		if(tmp>=n){
			k=i;
			break;
		}
	}
	
	string ans="";
	for(int i=k;i;i--){
		ll tmp=n-sum[i-1];
		//cout<<"tmp:"<<tmp<<endl;
		int t=tmp/num[i-1];
		if(tmp%num[i-1]) t++;
		if(t==1) ans+="2";
		else if(t==2) ans+="3";
		else ans+="6";
		
		n-=t*num[i-1];
		
		//cout<<ans<<" "<<n<<endl;
	}
	
	cout<<ans<<endl;
	return 0;
}