/*
大模拟，给你n张牌，每张牌的数字为1-13。需要你构造长度为n的一个序列，要求这个序列的存在分数形式，这个序列的数字只能是1-13，同时可以得到输入要求的点数m。
首先，由于题目要求按照字典序输出所有的答案，所以我们枚举这个序列的所有的情况，对于某一个序列，我们利用DFS判断这个序列是否和法。怎么判断呢？我们发现，这个序列的运算符号最多就只有四种，那么我们就枚举哪四种就行了
*/

#include<bits/stdc++.h>
using namespace std;
const double eps=1e-8;
int n,m;
double a[4];
bool vis[4];
bool has,tag;

struct node{
	int a[4];
};

vector<node> v;

void DFS(int d,bool flag){
	if(d==n){
		if(fabs(a[0]-m)<eps){
			has=true;
			if(!flag) tag=true; // 没有出现分数的形式
			return; 
		}
	}
	
	for(int i=0;i<n;i++){
		// 如果存在小数形式，那么说明是存在分数的形式 
		if(fabs(floor(a[i])-a[i])>eps){
			flag=true;
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(vis[i]||vis[j]) continue;
			double x=a[i],y=a[j];
			vis[j]=true;
			a[i]=x+y;DFS(d+1,flag);
			a[i]=x-y;DFS(d+1,flag);
			a[i]=y-x;DFS(d+1,flag);
			a[i]=x*y;DFS(d+1,flag);
			if(fabs(y)>eps){
				a[i]=x/y;
				DFS(d+1,flag);
			}
			if(fabs(x)>eps){
				a[i]=y/x;
				DFS(d+1,flag);
			}
			a[i]=x,a[j]=y;
			vis[j]=false;
		}
	}
}

void dfs(int d,int lst){
	if(d==n){
		has=tag=false;
		DFS(1,false);
		if(has&&!tag){
			v.push_back({(int)a[0],(int)a[1],(int)a[2],(int)a[3]});
		}
		return;
	}
	
	for(int i=lst;i<=13;i++){
		a[d]=i;
		dfs(d+1,i);
	}
}
int main(){
	cin>>n>>m;
	dfs(0,1);
	printf("%d\n",v.size());
	for(auto x:v){
		cout<<x.a[0]<<" "<<x.a[1]<<" "<<x.a[2]<<" "<<x.a[3]<<endl;
	}
	return 0;
}