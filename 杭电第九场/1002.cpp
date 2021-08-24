/*
一个思维题，在一个二维矩阵上面，每个位置有一个数字，要求两个人轮流移动一个棋子，第一个人可以在同一行移动，
第二个人可以在同一列移动，两个人移动的次数一共k次。可以提前退出游戏，第一个人想要最后棋子的位置尽可能大，
第二个人反之。问最后的棋子的数字。
首先，我们可以预处理出每一行的最大值和每一列的最小值。然后，我们发现，如果移动的次数为奇数次，那么最后的主动权一定是在第一个人手里，那么第一个人肯定是想要移动到当时所在行的最大的位置，为了使结果尽可能小，第二个人就要在倒数第二次操作的时候将这个棋子移动到所有行的最大值最小的位置。移动的次数为偶数次就反过来。同时还要特判最后的结果和(1,1)最初始的位置的大小进行比较。
*/

#include<iostream>
#include<cstring>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<vector>

#define fi first
#define se second

#define lowbit(x) (x&-x)

using namespace std;

namespace ae86{
    const int bufl=1<<15;
    char buf[bufl],*s=buf,*t=buf;
    inline int fetch(){
        if(s==t){t=(s=buf)+fread(buf,1,bufl,stdin);if(s==t)return EOF;}
        return*s++;
    }
    inline int read(){
        int a=0,b=1,c=fetch();
        while(!isdigit(c))b^=c=='-',c=fetch();
        while(isdigit(c))a=a*10+c-48,c=fetch();
        return b?a:-a;
    }
}
using ae86::read;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int,double> pid;

const int inf=0x3f3f3f3f;
const ll INF=2e18;
const double eps=1e-8;
const double pi=acos(-1);
const int mod=1e9+7;

const int N=100010;

ll T;
ll n,m;
ll k;

ll mx[N],mn[N];

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%lld%lld%lld",&n,&m,&k);
        for(int i=1;i<=n;i++)    mx[i]=-INF;
        for(int i=1;i<=m;i++)    mn[i]=INF;
        ll x;
        ll ans;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%lld",&x);
                if(i==1&&j==1)    ans=x;
                mn[j]=min(mn[j],x);
                mx[i]=max(mx[i],x);
            }
        }
        ll tmp=mx[1];
        ll maxn=0,minn=INF;
        for(int i=1;i<=m;i++)    maxn=max(maxn,mn[i]);
        for(int i=1;i<=n;i++)    minn=min(minn,mx[i]);
        if(k==1)    printf("%lld\n",mx[1]);
        else if(k%2==0){
            ans=max(ans,maxn);
            printf("%lld\n",ans);
        }
        else{
            if(tmp<minn){
                ans=max(ans,tmp);
                printf("%lld\n",ans);
            }
            else{
                ans=max(ans,minn);
                printf("%lld\n",ans);    
            }
        }
    }
}