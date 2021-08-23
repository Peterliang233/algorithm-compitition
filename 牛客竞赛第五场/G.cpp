/*
给定a,b,c，需要找到x和y使得(a+x)*(b+y)=c,同时使c尽可能小。
这里要知道的性质是(a+x)和(y+b)至少其中一个需要拥有c的所有的某一个质因数的所有个数。
比如对于某一个质因数p，它的个数为num[p],那么max(num[A],num[B])=num[p].
*/

#include<bits/stdc++.h>
#define ll long long
#define N 200
#define FOR(i,n,m) for(int i=n;i<=m;i++)
#define For(i,n,m) for(int i=n;i>=m;i--)
using namespace std;
int n;
int p[N],q[N];
__int128 f[N][N],s[N];
__int128 a,b,ans;
inline void read(__int128 &X)
{
	X = 0;
	int w=0; char ch=0;
	while(!isdigit(ch)) {w|=ch=='-';ch=getchar();}
	while(isdigit(ch)) X=(X<<3)+(X<<1)+(ch^48),ch=getchar();
	if (w) X = -X;
}
inline void print(__int128 x)
{
    if(x<0)
	{
        putchar('-');
        x=-x;
    }
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
//这个函数应该是同时找(x+a)和(y+b),维护最小值
void dfs(int k,__int128 A,__int128 B)
{
	if((A-a)+(B-b)>ans)return;
    if(A*s[k]<a||B*s[k]<b)return;//剪枝 A和B肯定要比原来的更大
	if(k>n)
	{
		if(A<a||B<b)return;
		ans=min(ans,A-a+B-b);//记录x+y的最小值
		return;
	}
	FOR(i,0,q[k]-1)
	{
		dfs(k+1,A*f[k][q[k]],B*f[k][i]);
		dfs(k+1,A*f[k][i],B*f[k][q[k]]);//A或B必须有一项是p[i]^q[i]的倍数，否则A和B的最小公倍数不可能是c
	}
	dfs(k+1,A*f[k][q[k]],B*f[k][q[k]]);
}
int main()
{
	cin>>n;
	FOR(i,1,n)
		std::cin>>p[i]>>q[i];
	read(a);read(b);
	FOR(i,1,n)
	{
		f[i][0]=1;
		FOR(j,1,q[i])
			f[i][j]=f[i][j-1]*p[i];//存储p[i]的不同次方的值
	}
	s[n+1]=1;
	For(i,n,1)
		s[i]=s[i+1]*f[i][q[i]];
	ans=(__int128)1e30;
	dfs(1,1,1);
	print(ans);
	return 0;
}
