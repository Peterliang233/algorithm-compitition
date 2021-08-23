/*
给一个棋盘，每个位置对应着一个花费，需要将这个棋盘进行染色，每个位置对应这个位置的花费，但是
有一个优惠就是如果在一个2x2的方阵里面，如果其余三个都染了色，那么剩余这个位置的染色的花费就是0.
求最小的所有的染色的花费。从这个分析里面我们可以提取出两个关键字，连通，最小花费，那么经过思考
可以想到是最小生成树的解法。也就是用克鲁斯卡尔算法进行求解。
*/

#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
const int N=5010*5010;
int ma[5010][5010];
int x[N];
int fa[N];
vector<pair<int,int> > v[100010];
int get(int x){
	if(x==fa[x]) return fa[x];
	return fa[x]=get(fa[x]);
}
int main(){
	int n,m,a,b,c,d,p;
	cin>>n>>m>>a>>b>>c>>d>>p;
	x[0]=a;
	for(int i=1;i<N;i++){
		x[i]=(ll)x[i-1]*x[i-1]%p*b%p+(ll)x[i-1]*c%p+d;
		x[i]%=p;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			ma[i][j]=x[m*(i-1)+j];  // 对这个点进行离散化
			v[ma[i][j]].push_back(make_pair(i,j));   // 将相同花费的放到一起
		}
	}
	for(int i=1;i<=n+m;i++){
		fa[i]=i;
	}
	ll ans=0; 
    // 我们先从小的花费开始
	for(int i=0;i<p;i++){
        // 枚举这个花费对应的所有点，同时向外进行拓展
		for(auto now:v[i]){
			int tmp1=now.first;
			int tmp2=now.second+n;
			int fx=get(tmp1),fy=get(tmp2);
			if(fx!=fy){
				ans+=i;
				fa[fx]=fy;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}