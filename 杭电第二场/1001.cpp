/*
同样，打表找规律，然后利用eois找到通项公式即可。
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
set<char> st;
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
    int t;
    scanf("%d",&t);
    while(t--){
        ll n;
        cin>>n;
        n--;
        n%=mod;
        ll tmp1=qp(n+1,2ll);
        ll tmp2=qp(n,2ll);
        ll ans=2*tmp1%mod*tmp2%mod;
        cout<<ans<<endl;
    }
    return 0;
}