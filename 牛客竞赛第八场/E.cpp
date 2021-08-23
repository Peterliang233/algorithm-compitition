/*
判断一个闰年是否是质数，肯定输出no
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

#define lowbit(x) (x&-x)

using namespace std;

namespace ae86{
    const int bufl=1<<15;
    char buf[bufl],*s=buf,*t=buf;
    inline int fetch(){
        if(s==t){t=(s=buf)+fread(buf,1,bufl,stdin);if(s==t)return EOF;}
        return*s++;
    }
    inline int read(){
        int a=0,b=1,c=fetch();
        while(!isdigit(c))b^=c=='-',c=fetch();
        while(isdigit(c))a=a*10+c-48,c=fetch();
        return b?a:-a;
    }
}
using ae86::read;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int,double> pid;

const int inf=0x3f3f3f3f;
const ll INF=2e18;
const double eps=1e-8;
const int mod=1e9+7;

int T;
ll n;

int main(){
	cin>>T;
	while(T--){
		cin>>n;
		if(n%400==0||(n%4==0&&n%100!=0)){
			bool flag=true;
			for(ll i=2;i<=n/i;i++){
				if(n%i==0){
					flag=false;
					break;
				}
			}
			if(!flag)	puts("no");
			else	puts("yes");
		}
		else	puts("no");
	}
}