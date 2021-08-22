/*
按照暴力的计算方法，我们发现在1000以后基本都是满足题目的3-友好的数字了，我们可以先预处理出100以内的数字，然后就可以直接计算了，注意区间之间的关系即可
*/

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

bool vis[1010]={false};

bool deal(int x){
    // 一位
    if(x<10){
        if(x%3==0) return true;
        else return false;
    }else if(x<100){
        if(x%3==0) return true;
        int y=x%10;
        if(y%3==0) return true;
        y=x/10;
        if(y%3==0) return true;
        
        return false;
    }else if(x<1000){
        if(x%3==0) return true;
        int y=x%10;
        if(y%3==0) return true;
        y=x%100;
        if(y%3==0) return true;
        y=x/10;
        if(y%3==0) return true;
        y=y%10;
        if(y%3==0) return true;
        y=x/100;
        if(y%3==0) return true;
        return false;
    }
}

void init(){
    for(int i=1;i<=999;i++){
        vis[i]=deal(i);
    }
}

int main(){
    init();
    int t;
    scanf("%d",&t);
    while(t--){
        ll l,r;
        scanf("%lld %lld",&l,&r);
        ll ans=0;
        for(;l<=r;l++){
            if(l>999) break;
            else{
                if(deal(l)) ans++;
            }
        }
        ans+=(r-l+1);
        
        printf("%lld\n",ans);
    }
    return 0;
}