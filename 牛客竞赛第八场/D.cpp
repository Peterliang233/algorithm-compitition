/*
将加法和或运算可以转化为与运算，然后枚举第一个数字，
判断每一位的放置的数字的情况即可
*/
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=100010;

ll a[N],b[N],c[N];

int main(){
    int n;
    cin>>n;
    for(int i=2;i<=n;i++){
        cin>>b[i];
    }
    for(int i=2;i<=n;i++){
        cin>>c[i];
        a[i]=c[i]-b[i];
    }
    
    ll ans=1;
    
    for(int i=0;i<32;i++){
        int bit0=1,bit1=1;
        for(int j=2;j<=n;j++){
            int nowbit0=0,nowbit1=0;
            int x=(b[j]>>i)&1;
            int y=(a[j]>>i)&1;
            if(!x&&!y){  // | 0 ,& 0,这时这个位置一定是0，看限制条件可以为0吗？
                nowbit0=bit0;
            }
            if(x&&!y){
                nowbit0=bit1,nowbit1=bit0;
            }
            if(x&&y){
                nowbit1=bit1;
            }
            bit0=nowbit0,bit1=nowbit1;
        }
        ans*=bit1+bit0;
    }
    cout<<ans<<endl;
    return 0;
}