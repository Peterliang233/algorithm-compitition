/*
本来是一个DP，但是需要使用bitset进行优化，这里发现后面的数都是连续的，所以没有必要枚举到那么后面，
直接枚举到36000左右即可结束。最后的数字一定是n*(n-1)/2
*/
#include<bitset>
#include<stdio.h>
#include<vector>
#include<iostream>
#include<map>
using namespace std;


const int N=705;

const int M=N*(N-1)/2;

vector<bitset<36000> > dp(N);

//--------------------------------------------------------------
namespace fastIO {
    #define BUF_SIZE 100000
    //fread -> read
    bool IOerror = 0;
    inline char nc() {
        static char buf[BUF_SIZE], *p1 = buf + BUF_SIZE, *pend = buf + BUF_SIZE;
        if(p1 == pend) {
            p1 = buf;
            pend = buf + fread(buf, 1, BUF_SIZE, stdin);
            if(pend == p1) {
                IOerror = 1;
                return -1;
            }
        }
        return *p1++;
    }
    inline bool blank(char ch) {
        return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
    }
    inline void read(int &x) {
        char ch;
        while(blank(ch = nc()));
        if(IOerror) return;
        for(x = ch - '0'; (ch = nc()) >= '0' && ch <= '9'; x = x * 10 + ch - '0');
    }
    #undef BUF_SIZE
};
 
using namespace fastIO;
//-----------------------------------------------------------
int i,j;

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    for(i=0;i<N;++i){
        dp[i].set(0);
    }
    for(i=2;i<N;++i){
        for(j=1;j<i;++j){
            dp[i]|=(dp[j]<<((i-j)*j));
            // dp[i]=dp[i]|(dp[j]<<((i-j)*j)); 
        }
    }
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int m=n*(n-1)/2;
        for(i=0;i<=min(35000,m);++i){
            if(dp[n][i]){
                if(i){
                    cout<<" ";
                }
                cout<<i;
            }
        }
        if(m>35000){
        	for(i=35001;i<=m;i++){
        		cout<<" "<<i;
        	}
        }
        cout<<endl;
    }
    return 0;
}