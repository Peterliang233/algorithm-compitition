/*
一个差分差分再差分的题目，可信我知道了第一步就直接放弃了。
首先，不同的字符之间可以进行独立的处理，不会互相干涉的。
然后就可以列出公式，通过两次差分最后可以利用每一段的长度进行维护了。
*/

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod = 998244353;
const int N=100010;
char c[N];
ll a[N];
ll len[N];
void solve(){
    getchar();
    scanf("%s",c+1);
    int n=strlen(c+1);
    ll res=0;
    for(char s='a';s<='z';s++){
        memset(len,0,sizeof(len));
        memset(a,0,sizeof(a));
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(c[i]==s){
                a[++cnt]=i;
            }
        }
        
        if(cnt==0) continue;
        
        a[0]=0,a[++cnt]=n+1;
        for(int i=0;i<cnt;i++){
            len[i]=a[i+1]-a[i];
        }
        
        
        ll ans=0,sum=0,d1=0,d2=0,d3;
        for(int i=1;i<=cnt-1;i++){
            if(i==1){
                d3=len[i-1];
            }else{
                d3=(len[i-1]+len[i-2])%mod;
            }
            d2=(d2+d3)%mod;
            d1=(d1+d2)%mod;
            sum=(sum+d1)%mod;
            ans=(ans+len[i]*sum%mod)%mod;
        }
        res=(res+ans)%mod;
    //    cout<<"res:"<<res<<endl;
    }
    
    cout<<res<<endl;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}

