/*
我们可以发现答案一定是最大的那个时间或者是所有时间的平均时间，
我们上面两种的最大的值即可。重点是进行合理的分配，最优的分配是
从小到大进行分配。
*/


#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

struct node{
    ll t;
    int idx;
}Node[100010];

bool cmp(node a,node b){
    return a.t<b.t;
}

struct pan{
    ll k,l,r;
}Pan;

vector<pan> res[100010];

ll tt[100010];

int main(){
    ll n,m;
    scanf("%lld %lld",&n,&m);

    ll mx=0;

    ll sum=0;

    for(int i=1;i<=n;i++){
        scanf("%lld",&Node[i].t);
        mx=max(mx,Node[i].t);
        sum+=Node[i].t;
        Node[i].idx=i;
    }

    ll ave=sum/m;
    
    if(sum%m) ave++;

    ll ans=max(ave,mx);

    sort(Node+1,Node+1+n,cmp);

    ll now=1;

    for(int i=1;i<=n;i++){
       // cout<<"now:"<<now<<endl;
        if(Node[i].t+tt[now]<=ans){
            Pan={now,tt[now],tt[now]+Node[i].t};
            res[Node[i].idx].push_back(Pan);
            tt[now]+=Node[i].t;
            if(tt[now]==ans) now++;
            continue;
        }

        if(Node[i].t+tt[now]>ans){
            Pan={now,tt[now],ans};
            res[Node[i].idx].push_back(Pan);
            ll tmp=Node[i].t+tt[now]-ans;
            now++;
            Pan={now,0,tmp};
            tt[now]=tmp;
            res[Node[i].idx].push_back(Pan);
        }
    }


    for(int i=1;i<=n;i++){
        printf("%d ",res[i].size());
        if(res[i].size()==1){
            printf("%lld %lld %lld\n",res[i][0].k,res[i][0].l,res[i][0].r);
        }else{
            printf("%lld %lld %lld %lld %lld %lld\n",res[i][1].k,res[i][1].l,res[i][1].r,
            res[i][0].k,res[i][0].l,res[i][0].r);
        }
    }
    return 0;
}