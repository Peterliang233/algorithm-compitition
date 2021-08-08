/*
第一行分配两个1和两个0交替出现的，然后后面的每一行与上一行这个位置的数字相反就行了
*/
#include<iostream>
#include<cstring>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int,double> pid;

const int inf=0x3f3f3f3f;
const double eps=1e-8;

const int N=1010;

int n,m;
int ans[N][N];

int main(){
	scanf("%d%d",&n,&m);
	int cnt=0;
	for(int i=1;i<=n;i+=2){
		cnt++;
		if(cnt&1){
			for(int j=1;j<=m;j++){
				if(j&1)	ans[i][j]=0;
				else	ans[i][j]=1;
			}	
		}
		else{
			for(int j=1;j<=m;j++){
				if(j&1)	ans[i][j]=1;
				else	ans[i][j]=0;
			}	
		}
	}
	cnt=0;
	for(int i=2;i<=n;i+=2){
		cnt++;
		if(cnt&1){
			for(int j=1;j<=m;j++){
				if(j&1)	ans[i][j]=0;
				else	ans[i][j]=1;
			}	
		}
		else{
			for(int j=1;j<=m;j++){
				if(j&1)	ans[i][j]=1;
				else	ans[i][j]=0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)	printf("%d",ans[i][j]);
		puts("");
	}
}