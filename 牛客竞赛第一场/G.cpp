/*
给两个序列，我们需要对A序列操作k次，求最大化两个序列相同位置的差值绝对值的和。
由于题目要求一定要交换k次，我们需要先特判2，然后k是奇数的情况，这是一定要交换的。
对于题目中的k次，我们发现可以指定为a[i]=max(a[i],b[i]),b[i]=min(a[i],b[i])。
这样我们交换增加的价值为2*min(a[i],b[i])-2*max(a[i],b[i])。这样我们可以先求出mi数组和
mx数组，然后大的配小的，一直到max(n,k)次。最后就是我们要求的结果了
*/

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=500010;
ll a[N],b[N];
ll mi[N],mx[N];
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    
    for(int i=1;i<=n;i++){
        scanf("%lld",&b[i]);
    }
    
    if(n==2&&k%2==1) swap(a[1],a[2]);
    
    ll ans=0;
    for(int i=1;i<=n;i++){
        ans+=abs(a[i]-b[i]);
    }
    
    if(n<=2){
        cout<<ans<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++){
        mi[i]=2*min(a[i],b[i]);
        mx[i]=2*max(a[i],b[i]);
    }
    
    sort(mi+1,mi+1+n,greater<int>());
    sort(mx+1,mx+1+n);
    
    ll res=ans;
    for(int i=1;i<=n&&i<=k;i++){
        res+=(mi[i]-mx[i]);
        ans=max(ans,res);
    }
    cout<<ans<<endl;
    //小的从
    return 0;
}