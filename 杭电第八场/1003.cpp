/*
有n个点同时向外进行扩展，问需要的最短的时间
*/

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;


struct node{
    ll x,y;
}Node[5010];

ll dis(node a,node b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

ll a[5010][5010];

ll d[5010];
bool v[5010];
int n;

void prim(){
    memset(v,false,sizeof(v));
    memset(d,0x3f3f3f3f,sizeof(d));
    d[1]=0;
    for(int i=1;i<n;i++){
        int x=0;
        for(int j=1;j<=n;j++){
            if(!v[j]&&(x==0||d[j]<d[x])) x=j;
        }
        v[x]=1;
        for(int y=1;y<=n;y++){
            if(!v[y]){
                d[y]=min(d[y],a[x][y]);
            }
        }
    }
}

int main(){
    //freopen("data.in","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int cnt=0;
        for(int i=1;i<=n;i++){
            scanf("%lld %lld",&Node[i].x,&Node[i].y);
        }
        memset(a,0x3f3f3f3f,sizeof(a));

        for(int i=1;i<=n;i++) a[i][i]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                a[j][i]=a[i][j]=min(a[i][j],dis(Node[i],Node[j]));
            }
        }

        prim();

        printf("%lld\n",d[n]);
    }
    return 0;
}