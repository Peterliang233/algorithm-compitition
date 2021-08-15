/* 题解
解法一：线段树

解法二：二分
可以先进行分析，我们进行逐行分析，我们可以发现当前的可以到达的点可以通过上一行进行推导。
所以我们先从上到下维护每一行可以到达的区间，然后我们可以枚举当前的区间的那些情况，更新当前的区间。
枚举判断当前区间的时候，我们可以先进行二分上一行得到的区间的情况，将范围缩小逼近当前的这个小区间。
将每一个可行的区间加到我们的答案里面
*/


#include<bits/stdc++.h>

using namespace std;
typedef long long ll;


const int N=100010;

const int inf=1e9+7;

vector<int> a[N];

struct node{
    int l,r;
    node(int l=0,int r=0):l(l),r(r){}
};

vector<node> ok;

bool check(node a,int l,int r){
    if(a.l<=l) return a.r>=l;
    else if(a.l<=r) return 1;
    return 0;
}

int calc(int st,int ed){
    int l=0,r=ok.size()-1,ans=ok.size()-1;
    while(l<=r){  // 二分区间都恰好[st,ed]附近 
        int mid=(l+r)>>1;
        if(ok[mid].l<=st) l=mid+1;
        else r=mid-1,ans=r;
    }
    int res=inf,tmp=st;
    for(int i=ans-5;i<=ans+5;i++){ // 保证结果在这个区间附近 
        if(i<0||i>=ok.size()) continue;  // 出了边界的情况 
        if(check(ok[i],st,ed)){  // 判断是否有交集 
            tmp=max(tmp,ok[i].l);
            res=min(res,tmp);
        }
    }
    
    return res==inf?-1:res;
}

void solve(){
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    // 初始化 
    for(int i=1;i<=n;i++){
        a[i].clear();
    } 
    
    for(int i=1;i<=k;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        a[x].push_back(y);
    }
    
    for(int i=1;i<=n;i++){
        a[i].push_back(m+1);
        sort(a[i].begin(),a[i].end());
    }
    
    ok.clear();
    
    ok.push_back(node(1,a[1][0]-1));  // 第一行能够到达的极限,一定只有一个区间 
    ll ans=ok[0].r-ok[0].l+1,st=1;  // 当前的左端点 
    for(int i=2;i<=n;i++){  // 从第二行开始进行枚举 
        vector<node> cur;
        st=1;
        for(int j=0;j<a[i].size();j++){  // 枚举当前行的每段区间 
            int ed=a[i][j];  // 枚举当前的右端点 
            if(st>=ed){
                st=ed+1;continue;
            }
            int st2=calc(st,ed-1); // 判断这段区间 
            if(st2==-1){  // 如果这段区间被堵死了，那么可以直接跳过 
                st=ed+1;
                continue;
            }
            
            // 记录这段可行的区间 
            cur.push_back(node(st2,ed-1));
            ans+=ed-st2; // 累加到答案 
            st=ed+1; // 更新左端点 
        }
        ok=cur;
    }
    
    printf("%lld\n",ans);
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}