/*
n各结点，结点之间两两连边，边权为这两个结点编号的最小公倍数。
现在，我们需要找到一个最小生成树。根据贪心的思想，我们为了使这个生成树最小的话，尽可能选择小的边权，
比如，我们可以找到每个数的最小质因数，让这个数和它的最小质因数连边，那么边权就是它的最小质因数了。
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e7+10;
const int N=1e7+5;
bool vis[maxn];
void prime(){
    for(int i=2;i<=N;i++){
        if(!vis[i]){
            for(int j=i+i;j<=N;j+=i){
                vis[j]=1;
            }
        }
    }
}
int main(){
    int t;
    scanf("%d",&t);
    prime();
    while(t--){
        ll n;
        scanf("%lld",&n);
        ll ans=0;
        for(int i=3;i<=n;i++){
            if(!vis[i]){
                ans+=i;
                ans+=i;
            }else{
                ans+=i;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
