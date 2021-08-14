/*
记忆化搜索
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
int ans;
map<long long,int>mp;
long long solve(int l,int r){
    if(l>r)return 0;
    if(mp[r-l+1])return mp[r-l+1];
    if(r-l+1<=k){
        return mp[r-l+1]=1;
    }
    //ans++;
    mp[r-l+1]=1;
    int mid=(l+r)>>1;
    mp[r-l+1]+=solve(l,mid);
    mp[r-l+1]+=solve(mid+1,r);
    return mp[r-l+1];
}
signed main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        mp.clear();
        n=10;
        scanf("%lld%lld",&n,&k);
        cout<<solve(1,n)<<endl;
    }
}

