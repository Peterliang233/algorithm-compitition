/*
给你n个点，点和点之间两两存在连边，我们需要找到同色三角形的个数，也就是这个三角形的三条边的颜色都是一样的。
首先，我们来分析一下，n个点一共可以有m=n*(n-1)/2条边，然后，我们可以找到C(3,m)个三角形。所以接下来，我们需要
排除有多少个不符合条件的三角形。首先，我们找到一条边是黑色，那么现在假如我们找到了a条白边和b条黑边，所以，所以，现在异色三角形多了a个，如果找到的是一条黑边，异色三角形多了就是此时找到的白边的个数。这样的找法会出现重复，最后/2就行了
*/

#include<bits/stdc++.h>
namespace GenHelper
{
    unsigned z1,z2,z3,z4,b,u;
    unsigned get()
    {
        b=((z1<<6)^z1)>>13;
        z1=((z1&4294967294U)<<18)^b;
        b=((z2<<2)^z2)>>27;
        z2=((z2&4294967288U)<<2)^b;
        b=((z3<<13)^z3)>>21;
        z3=((z3&4294967280U)<<7)^b;
        b=((z4<<3)^z4)>>12;
        z4=((z4&4294967168U)<<13)^b;
        return (z1^z2^z3^z4);
    }
    bool read() {
      while (!u) u = get();
      bool res = u & 1;
      u >>= 1; return res;
    }
    void srand(int x)
    {
        z1=x;
        z2=(~x)^0x233333333U;
        z3=x^0x1234598766U;
        z4=(~x)+51;
      	u = 0;
    }
}
using namespace GenHelper;
using namespace std;
typedef long long ll;
bool edge[8005][8005];
set<int> st1[8010],st2[8010],s;
int num1[8010],num2[8010];
stack<pair<int,int> > stack1,stack2;
int main() {
  	ll n;
	int seed;
 	cin >> n >> seed;
  	srand(seed);
  	int num=0;
  	for (int i = 0; i < n; i++)
    	for (int j = i + 1; j < n; j++){
    		edge[j][i] = edge[i][j] = read();
		}
	ll ans=n*(n-1)*(n-2)/6;
	ll res=0;
	for(int i=0;i<n;i++){
		ll b=0,w=0;
		for(int j=0;j<n;j++){
			if(i==j) continue;
			if(edge[i][j]){
				res+=w;
				b++;
			}else{
				res+=b;w++;
			}
		}
	}
	ans-=res/2;
	cout<<ans<<endl;
 	return 0;
}