/*
转化为Nim模型，将所有的质数按照质因数进行分解，看可以分解为多少个质因数，然后
每次拿就相当于拿质因数，这样质因数的个数就转化为石头的个数，然后NIM模型求解即可
*/
#include<bits/stdc++.h>
using namespace std;
const int N=1e7+10;

int v[N],a[N],prime[N],m,f[N];
void init(){
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
    
    for(int i=2;i<N;i++){
        if(v[i]==i) f[i]=1;
        else{
            f[i]=f[v[i]]+f[i/v[i]];
        }
    }
}
void solve(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    
    int res=0;
    for(int i=1;i<=n;i++){
        res^=f[a[i]];
    }
    if(res) puts("Alice");
    else puts("Bob");
}

int main(){
    init();
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}