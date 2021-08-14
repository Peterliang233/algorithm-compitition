#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        if(n<=2){
            cout<<"0"<<endl;
            continue;
        }
        ll sum=2;
        ll count=0;
        while(sum<n){
            sum+=sum;
            count++;
        }
        ll ans=1ll<<count;
        ans--;
        cout<<ans<<endl;
    }
    return 0;
}