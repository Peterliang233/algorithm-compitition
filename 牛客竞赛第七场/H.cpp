/*
先利用倍数法快速得到1-n之间的所有的约数，然后假设我们当前放的是第一个位置
枚举a[i]的约数，然后累加另一个约数的个数和这个数字的个数的乘
*/

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int a[1000010];
ll mp[1000010];
vector<int> v[1000010];

int main(){
    int n;
    scanf("%d",&n);
    int mx=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        mx=max(mx,a[i]);
        mp[a[i]]++;
    }
    
    ll ans=0;
    for(int i=1;i<=mx;i++){
        for(int j=1;j<=mx/i;j++){
            if(mp[i]==0||mp[i*j]==0) continue;
            v[i*j].push_back(i);
        }
    }
    
    for(int i=1;i<=n;i++){
        for(auto x:v[a[i]]){
            ans+=mp[x]*mp[a[i]/x];
        }
    }
    
    printf("%lld\n",ans);
    return 0;
}