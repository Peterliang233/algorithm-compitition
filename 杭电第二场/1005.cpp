/*
找打初始的序列的前面有多少个连续的字符，然后最后的答案就是2^(x-1)
*/
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

const int N=100010;
const int mod=1000000007;

int t,n;
char s[N];

int main(){
    scanf("%d",&t);
    while(t--){
        char head,lst;
        scanf("%d%s",&n,s);
        LL ans=1;
        for(int i=0;i<n;i++){
            if(i==0)    head=lst=s[i];
            else{
                if(s[i]>head){
                    lst=s[i];
                    continue;
                }
                else if(s[i]<head){
                    head=s[i];
                    continue;
                }
                else{
                    if(lst>s[i]){
                        head=s[i];
                        continue;
                    }
                    else if(lst<s[i]){
                        lst=s[i];
                        continue;
                    }
                    else{
                        ans=ans*2%mod;
                    }
                }
            }
        }
        printf("%lld\n",ans);
    }
}