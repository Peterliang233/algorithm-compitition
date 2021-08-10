/*
注意x=0的情况，没了
*/
#include<bits/stdc++.h> 

using namespace std;
typedef long long ll;
const ll mod=4933;

ll qp(ll a,ll b){
	ll c=1;
	while(b){
		if(b&1) c=c*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return c;
}


int main(){
	ll n,m,k,a,l;
	cin>>n>>m>>k>>a>>l;
    ll sum=1;
	for(int i=1;i<=k;i++){
		ll x,y,z;
		cin>>x>>y>>z;
        ll g=__gcd(y,z);
        y/=g,z/=g;
        if(x==0) continue;
		ll tmp=qp(z,mod-2)*(z-y)%mod;
        sum=sum*tmp%mod;
	//	cout<<sum<<endl;
	}
    sum=(sum+a)%mod;
	cout<<(sum%mod+mod)%mod<<endl;
	return 0;
}