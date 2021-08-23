/*
给定一棵树，每个结点的权值在一个区间范围内。现在给出这棵树的所有的边的权值的异或结果，需要我们找到有多少种
符合条件的树的结点的权值情况。
我们发现，固定了一个结点的权值，那么其他结点的权值情况都是可以确定的，所以我们利用在字典树上进行操作的方法进行求解。同时利用字典树的递归写法，结合前缀和进行维护
*/

#include<bits/stdc++.h> 

using namespace std;
typedef long long ll;
const int maxn=1e6+7;
const int mod=1e9+7;

int n,val[maxn];
int head[maxn],num;

vector<pair<int,int> > vec[3];

struct node{
	int l,r;
}q[maxn];

struct Node{
	int v,w,next;
}e[maxn];

void add(int u,int v,int w){
	e[num].v=v;
	e[num].w=w;
	e[num].next=head[u];
	head[u]=num++;
}

void dfs(int u,int pre,int w){
	val[u]=val[pre]^w;
	for(int i=head[u];i!=-1;i=e[i].next){
		int to=e[i].v;
		int w=e[i].w;
		if(to==pre) continue;
		dfs(to,u,w);
	}
}

void dfs1(int id,int pos,int val,int r,int now){
	if(pos==-1){
		vec[id].push_back({now,now});
		return;
	}
	
	int x=(val>>pos)&1;
	int y=(r>>pos&1);
	if(y==1){
		if(x==1){
			vec[id].push_back({now+(1<<pos),now+(1<<(pos+1))-1});
			dfs1(id,pos-1,val,r,now);
		}else{
			vec[id].push_back({now,now+(1<<pos)-1});
			dfs1(id,pos-1,val,r,now+(1<<pos));
		}
	}else{
		if(x==1){
			dfs1(id,pos-1,val,r,now+(1<<pos));
		}else{
			dfs1(id,pos-1,val,r,now);
		}
	}
}


int solve(){
	vector<pair<int,int> > res;
	for(auto x:vec[1]){
		res.push_back({x.first,1});
		res.push_back({x.second+1,-1});
	}
	
	for(auto x:vec[0]){
		res.push_back({x.first,-1});
		res.push_back({x.second+1,1});
	}
	
	sort(res.begin(),res.end());
	
	int dep=0,ans=0;
	for(int i=0;i<res.size();i++){
		dep+=res[i].second;
		if(dep==n){
			if(i+1<res.size()) ans+=res[i+1].first-res[i].first;
		}
	}
	
	return ans;
}

int main(){
	scanf("%d",&n);
	memset(head,-1,sizeof(head));
	
	for(int i=1;i<=n;i++){
		scanf("%d %d",&q[i].l,&q[i].r);
	}
	
	for(int i=1,u,v,w;i<n;i++){
		scanf("%d %d %d",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	
	
	// 假设0号结点的数字为0 
	dfs(1,0,0);
	
	for(int i=1;i<=n;i++){
		if(q[i].l>0) dfs1(0,29,val[i],q[i].l-1,0);
		dfs1(1,29,val[i],q[i].r,0);
	}
	
	printf("%d\n",solve());
	
	return 0;
}