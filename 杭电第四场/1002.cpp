#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=2010;
const int mod2=1e9+9;
const int mod1=1e9+7;
const int mod=19560929;
vector<int> v[N];

ll qp(ll a,ll b,ll mod){
  ll c=1;
  while(b){
    if(b&1) c=c*a%mod;
    a=a*a%mod;
    b>>=1;
  }
  return c;
}

ll p[N],c[N],n;
ll ans[N][2];
ll cnt[N],tot;
ll inv1[N],inv2[N];
void DFS(int root,int x,int fa){
  ans[root][0]=(ans[root][0]+inv1[x-1]*tot)%mod1;
  ans[root][1]=(ans[root][1]+inv2[x-1]*tot)%mod2;
  for(auto y:v[x]){
    if(y==fa) continue;
    cnt[c[y]]++;
    if(cnt[c[y]]==1) tot++;
    DFS(root,y,x);
    cnt[c[y]]--;
    if(cnt[c[y]]==0){
      tot--;
    }
  }
}
void solve(){
  memset(ans,0,sizeof(ans));
  scanf("%lld",&n);
  for(int i=1;i<=n;i++){
    v[i].clear();
  }
  for(int i=2;i<=n;i++){
    scanf("%lld",&p[i]);
    v[p[i]].push_back(i);
    v[i].push_back(p[i]);
  }
  for(int i=1;i<=n;i++){
    scanf("%lld",&c[i]);
  }
  for(int i=1;i<=n;i++){
    memset(cnt,0,sizeof(cnt));
    tot=1;
    cnt[c[i]]++;
    DFS(i,i,0);
  }
  for(int i=1;i<=n;i++){
    printf("%lld %lld\n",ans[i][0],ans[i][1]);
  }
}
int main(){
  //freopen("data.in","r",stdin);
  inv1[0]=1,inv2[0]=1;
  for(int i=1;i<=2005;i++){
    inv1[i]=qp(mod,i,mod1);
    inv2[i]=qp(mod,i,mod2);
  }
  int t;
  scanf("%d",&t);
  while(t--){
    solve();
  }
  return 0;
}

