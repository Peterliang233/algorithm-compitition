#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=1000010;

int head[N<<1],ver[N<<1],nxt[N<<1],tot;
int low[N],dfn[N],sz[N];
int num,root,cnt;
ll ans,sum;

int a[N];
int n,m;

template<typename T>
inline void read(T &x)
{
    T f=1;x=0;
    char ch=getchar();
    while(0==isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(0!=isdigit(ch)) x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
    x*=f;
}
template<typename T>
inline void write(T x)
{
    if(x<0){x=~(x-1);putchar('-');}
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
void init(){
    memset(head,0,sizeof(int)*(n+5));
    memset(dfn,0,sizeof(int)*(n+5));
    memset(sz,0,sizeof(int)*(n+5));
    memset(low,0,sizeof(int)*(n+5));
    tot=cnt=num=root=0;
    sum=0;
    ans=-1e18;
}

void add(int x,int y){
    ver[++tot]=y;
    nxt[tot]=head[x];
    head[x]=tot;
}

void tarjan(int u){
    dfn[u]=low[u]=++num;
    int flag=0;
    bool ok=true;
    sz[u]=1;
    for(int i=head[u];i;i=nxt[i]){
        int y=ver[i];
        if(!dfn[y]){
            tarjan(y);
            sz[u]+=sz[y];
            low[u]=min(low[u],low[y]);
            if(low[y]>=dfn[u]){
                flag++;
                if(u!=root||flag>1){
                    if(sz[y]&1){
                        ok=false;
                    }
                }
            }
        }else{
            low[u]=min(low[u],dfn[y]);
        }
    }

    if(ok){
        ans=max(ans,sum-2*a[u]);
    }
}

int main(){
    int t;
    read(t);
    while(t--){
        init();
        read(n),read(m);
        for(int i=1;i<=n;i++){
            read(a[i]);
            sum+=a[i];
        }
        while(m--){
            int u,v;
            read(u),read(v);
            add(u,v);
            add(v,u);
        }



        if(n%2==0){
            printf("%lld\n",sum);
            continue;
        }

        for(int i=1;i<=n;i++){
            if(!dfn[i]){
                root=i;
                tarjan(i);
            }
        }

        printf("%lld\n",ans);
        
    }
    return 0;
}