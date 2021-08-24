/*
输出存在最大众数的区间的个数，也算是一个模板题了
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int read() {
    char c=getchar(); int x=0,f=1;
    while (c<'0' || c>'9') {
          if (c=='-') f=-1;
          c=getchar();
    }
    while (c>='0' && c<='9') {
          x=x*10+c-'0';
          c=getchar();
    }
    return x*f;
}
int a[1000005];
int delta,mx;
ll t[2000005][3];
vector<int> vec[1000005];
ll sum(int x) {
    x+=delta;
    if (x<=0) return 0LL;
    ll ans=0;
    for (int i=x; i; i-=i&-i) {
        ans+=t[i][0]*(x+2)*(x+1)-t[i][1]*(2*x+3)+t[i][2];
    }
    return ans/2;
}
void add(int x,int k) {
    x+=delta;
    for (int i=x; i<=mx; i+=i&-i) {
        t[i][0]+=k;
        t[i][1]+=k*x;
        t[i][2]+=1LL*k*x*x;
    }
}
int main() {
    int T=read();
    while (T--) {
        int n=read();
        for (int i=1; i<=n; i++) {
            a[i]=read();
            vec[a[i]].push_back(i);
        }
        delta=n+1; mx=n+n+1;
        ll ans=0;
        for (int i=0; i<=1000000; i++) {
            if (vec[i].size()==0) continue;
            vec[i].push_back(n+1);
            int last=0,now=-1;
            int len1=vec[i].size();
            for (int j=0; j<len1; j++) {
                int p=vec[i][j];
                int l=now+1-(p-1-last),r=now+1;
                ans+=sum(r-1)-sum(l-2);
                add(l,1); add(r+1,-1);
                last=p; now=l;
            }
            
            last=0,now=-1;
            len1=vec[i].size();
            for (int j=0; j<len1; j++) {
                int p=vec[i][j];
                int l=now+1-(p-1-last),r=now+1;
                add(l,-1); add(r+1,1);
                last=p; now=l;
            }
        }
        printf("%lld\n", ans);
        for (int i=1; i<=n; i++) vec[a[i]].clear();
    }
    return 0;
}