/*
位运算操作
*/
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ll x,s;
    cin>>x>>s;
    ll ans=1;
    for(int i=0;i<32;i++){
        int a=(x>>i)&1;
        int b=(s>>i)&1;
        if(a==1){
            if(b==1) ans=ans*2;
            else ans=0;
        }
    }
    if(x==s) ans--;
    cout<<ans<<endl;
    return 0;
}