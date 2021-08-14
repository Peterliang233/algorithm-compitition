/*
首先，找规律，发现肯定不存在-1的情况，负数可以通过加法变成正数，正数肯定存在比他大的质数
所以，我们可以只需要找到某一个数大的两个质数就行了。
*/
#include<bits/stdc++.h>


using namespace std;

const int N=30001100;
typedef long long ll;

int v[N];
int prime[N];
int m;

void init(){
    memset(v,false,sizeof(v));
    m=0;
    for(int i=2;i<N;i++){
        if(v[i]==0){
            v[i]=i;
            prime[++m]=i;
        }
        for(int j=1;j<=m;j++){
            if(prime[j]>v[i]||prime[j]>N/i) break;
            v[i*prime[j]]=prime[j];
        }
    }
}


void solve(){
    int x;
    scanf("%d",&x);
    if(x<=0){
        int ans=0;
        x=-x;
        ans+=x;
        ans+=x;
        ans++;
        x++;
        int pos=lower_bound(prime+1,prime+1+m,x)-prime;
        for(int i=x;i<=prime[pos];i++){
            if(v[i]==i){
                ans++;
                break;
            }else if(v[i+i+1]==i+i+1){
                ans+=2;
                break;
            }
            ans+=2;
        }
        
        printf("%d\n",ans);
    }else{
        int pos=lower_bound(prime+1,prime+1+m,x)-prime;
        int ans=0x3f3f3f3f;
        if(v[x]==x){
            ans=min(ans,1);
        }
        if(v[x+x-1]==x+x-1||v[x+x+1]==x+x+1){
            ans=min(ans,2);
        }
        int res=x+x+1;
        for(int i=x+1;i<=prime[pos];i++){
            if(v[i]==i){
                ans=min(ans,res+1);
                break;
            }else if(v[i+i+1]==i+i+1){
                ans=min(ans,res+2);
                break;
            }
            res+=2;
        }
        
        
        printf("%d\n",ans);
        
    }
}
int main(){
    int t;
    scanf("%d",&t);
    init();
//    cout<<m<<endl;
    while(t--){
        solve();
    }
    return 0;
}

