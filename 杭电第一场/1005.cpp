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

[ Copy to Clipboard ]    [ Save to File]
