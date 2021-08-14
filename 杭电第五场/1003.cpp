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

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int,double> pid;

const int inf=0x3f3f3f3f;
const double eps=1e-8;

int T;
ll n,k;

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%lld%lld",&n,&k);
        if(n<=k+1)    puts("Yes");
        else    puts("No");
    }
}