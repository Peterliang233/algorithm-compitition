/*
线段树模板，抄上去剪枝就行了
*/
#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;

ll a[200010],key[200010];
ll tot;
void build(int l,int r){
    //cout<<l<<" "<<r<<endl;
    tot++;
    if(l==r){
        return;
    }
    if(l+1==r){
        build(l,l);
        build(r,r);
    }else{
        int tmp=(r-l)/3;
        if((r-l)%3) tmp++;
        int b=l+tmp-1;
        int c=(b+r)>>1;
        build(l,b);
        build(b+1,c);
        build(c+1,r);
    }
} 
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
        }
        tot=0;
        build(1,n);
        printf("%lld\n",tot);
    }
    return 0;
}