/*
给一个长度为m的数组b，需要判断是否存在一个1-n的排列，使得
将这个排列分为m个不同的集合，同时b[i]是第i段的中位数。
我们先来分析题目的意思，首先，我们将这个序列分为m段，我们先把中位数放进每一段里面，
然后剩下n-m个数字，所以我们需要将这n-m个数字分到这些段里面，同时不影响他们是中位数。
我们这m个数字可以将这个序列分为m+1段，然后对于这m+1段数字。
如果长度最长的段的数字的个数大于其他所有的段的个数，那么最后剩下的数字一定都在这个段里面，
然后，我们要将剩下的数字分到这些段里面，所以我们发现，如果比这一段小的中位数有x个，那么
只有x大于这段剩下的数字就一定存在解。
对于最长的段的数字小于其他所有的段的数字的个数，我们发现要么会恰好全部消掉，要么会剩下一个，那么剩下的，我们放到
最小段哪里就行了。
*/

#include<bits/stdc++.h>

using namespace std;

int b[100010];


bool vis[100010];

vector<pair<int,int> > v;

void solve(){
    v.clear();
    memset(vis,false,sizeof(vis));
    int n,m;
    scanf("%d %d",&n,&m);
    
    if(m==0){
        puts("0");
    } 
        
    for(int i=1;i<=m;i++){
        scanf("%d",&b[i]);
        vis[b[i]]=true;
    }
    if(m==n){
        puts("YES");
        return;
    }
    sort(b+1,b+1+m);
    
    
    int sum=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]) {
            sum++;
        }
    }
    
    vis[n+1]=true;
    int have=0,cnt=0;
    for(int i=1;i<=n+1;i++){
        if(vis[i]){
            if(have){
                v.push_back(make_pair(have,cnt));
            }
            have=0;
            cnt+=1;
        }else{
            have++;
        }
    }
    sort(v.begin(),v.end());
    if(v.back().first<=sum-v.back().first+v.back().second){
        puts("YES");
    }else{
        puts("NO");
    }
}

int main(){
//    freopen("test.in","r",stdin);
//    freopen("out.in","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}