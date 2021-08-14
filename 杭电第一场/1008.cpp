#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[2010][2010],b[2010][2010];
ll st[2010],w[2010];
int main(){
    //freopen("test.in","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%lld",&a[i][j]);
            }
        }
        for(int i=1;i<=m;i++){
            b[n][i]=1;
        }
        for(int i=n-1;i;i--){
            for(int j=1;j<=m;j++){
                if(a[i][j]<=a[i+1][j]){
                    b[i][j]=b[i+1][j]+1;
                }else{
                    b[i][j]=1;
                }
            }
        }
        ll ans=1,cnt;
        for(int i=1;i<=n;i++){
            b[i][m+1]=0;
            cnt=0;
            for(int j=1;j<=m+1;j++){
                if(b[i][j]>st[cnt]){
                    st[++cnt]=b[i][j],w[cnt]=1;
                }else{
                    ll width=0;
                    while(st[cnt]>b[i][j]){
                        width+=w[cnt];
                        ans=max(ans,width*st[cnt]);
                        cnt--;
                    }
                    st[++cnt]=b[i][j],w[cnt]=width+1;
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}