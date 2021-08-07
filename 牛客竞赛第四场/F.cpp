/*
根据边和点的和的奇偶性判断
*/
#include<bits/stdc++.h> 
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
    }
	int ans=n+m;
	if(ans&1) puts("Alice");
	else puts("Bob");
	return 0;
}