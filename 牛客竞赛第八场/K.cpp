/*
只有两种走法，一种是向一个格子的对角线走，另一种是往短的一边走，
这两种走的方法可以交替进行行，所以枚举左右走的步数（不会很多），取
最优的结果即可
*/
#include<bits/stdc++.h> 

using namespace std;
typedef long long ll;


int main(){
	int t;
	cin>>t;
	while(t--){
		double w,d;
		cin>>w>>d;
		double d1=min(w,d);
		double d2=sqrt(w*w+d*d);
		double pi=acos(-1);
		ll ans=4;
		for(int i=0;i<30;i++){
			double sum=i*d1;
            if(sum>pi) continue;
			double tmp=pi-sum;
			ll num=i*2+(int)(tmp/d2)*3;
			ans=max(ans,4+num);
		}
		for(int i=0;i<30;i++){
			double sum=i*d2;
            if(sum>pi) continue;
			double tmp=pi-sum;
			ll num=i*3+(int)(tmp/d1)*2;
			ans=max(ans,num+4);
		}
		cout<<ans<<endl;
	}
	return 0;
}