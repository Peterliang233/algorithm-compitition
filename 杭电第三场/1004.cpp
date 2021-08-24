/*
由n条直线，A在里面选择k条直线(0=<k<=n)，然后，对于每个k，B会会一条直线使得与这k条直线由尽可能多的交点，然后
就是A为了使交点数尽可能少，问对于每个k，B最多可以得到多少交点。
首先，我们对直线按照斜率进行分组，然后，比如有v组，如果k<=v，那么就是每组里面选择一条，然后如果超过了v组，那么就是对每组循环拿，从多的那组开始，已知遍历下去即可。
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e9+7;
ll gcd(ll x,ll y){
    if(y==0) return x;
    return gcd(y,x%y);
}
map<ll,int> mp;
int num[100010];
int x[100010];  // 记录集合大小为i的集合的个数 
int pre[100010];
int a[100010];
void solve(){
    memset(a,0,sizeof(a));
    memset(x,0,sizeof(x));
    memset(num,0,sizeof(num));
    mp.clear();
    int n;
    scanf("%d",&n);
    int tot=0;
    for(int i=1;i<=n;i++){
        ll x1,x2,y1,y2;
        scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
        ll tmpx=x1-x2;
        ll tmpy=y1-y2;
        ll g=gcd(tmpx,tmpy);
        tmpx/=g,tmpy/=g;
        ll sum=tmpx*N+tmpy;
        if(mp[sum]==0){
            mp[sum]=++tot;
        }
        num[mp[sum]]++;
    }
    for(int i=1;i<=tot;i++) {
        x[num[i]]++;
    }
    int sum=tot;
    for(int i=1;i<=100005;i++){
        pre[i]=sum;
        sum-=x[i];
    }
    sum=0;
    a[1]=1;
    for(int i=1;i<=100005;i++){
        sum+=pre[i];
        a[sum+1]=1;
    }
    sum=0;
    for(int i=1;i<=n;i++){
        sum+=a[i];
        printf("%d\n",i-sum);
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}