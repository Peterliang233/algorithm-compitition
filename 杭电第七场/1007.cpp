/*
根据题目给出的公式，可以看出如果形成了一个环，那么就是在环上不断行走。
首先，我们把不在环的那些点先去掉，然后，剩下的在环里面的点，同一个环里面的点的平均值
需要相同才输出YES，否则输出NO，判断环可以利用拓扑排序进行处理。
*/
#include<bits/stdc++.h> 

using namespace std;
typedef long long ll;
const int N=100010;

ll ans[N],tot;
ll a[N];
ll in[N];

void solve(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        in[i]=0;
    } 
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        in[a[i]]++;
    }
    queue<ll> q;
    for(int i=1;i<=n;i++){
        if(in[i]==0){
            q.push(i);
        }
    }
    
    // 把不在环里面的点都去掉，剩下的就是都在环里面的点了 
    ll u;
    while(!q.empty()){
        u=q.front();
        q.pop();
        in[a[u]]--;
        if(in[a[u]]==0){
            q.push(a[u]);
        }
    }
    
    ll x=-1,y=-1,flag=0;
    for(int i=1;i<=n;i++){
        if(in[i]==0) continue; // 环里面的点入度一定不是0 
        ll sum=0;
        ll cnt=0;
        for(int j=i;in[j];j=a[j]){
            in[j]=0;
            sum+=j;
            cnt++;
        }
        if(x==-1&&y==-1){
            x=sum;
            y=cnt;
        }else{
            if(x*cnt!=y*sum){
                flag=1;
                break;
            }
        }
    }
    if(flag){
        puts("NO");
    }else{
        puts("YES");
    }
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}