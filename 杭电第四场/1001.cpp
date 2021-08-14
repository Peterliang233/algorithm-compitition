/*
只要判断函数是否收敛就行了，仔细读题啊
*/
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve(){
  string s;
  cin>>s;
  int sum=0;
  for(auto x:s){
    if(x<='9'&&x>='0'){
      sum=sum*10+(x-'0');
    }else{
      if(sum!=0){
        puts("NO");
        return;
      }
    }
  }
  if(sum) puts("NO");
  else puts("YES");
}
int main(){
  //freopen("data.in","r",stdin);
  int t;
  scanf("%d",&t);
  while(t--){
    solve();
  }
  return 0;
}