/*
根据题目的意思进行模拟，在一个双端队列里面执行左端放入数字，右端放入数字，删除数字和查询上中位数四种操作。
我们可以利用两个双端队列进行模拟，如果使左边进数字，那么就放到左边的前头，如果是右边放数字，那么就放到右边
的后头，同时我们维护右边的要么与左边相等，要么比左边多1，这样的话最后查询的时候只要查询右队列的队首就可。
我们每次操作的时候进行维护，首先，如果左队列大小大于右队列，那么就执行左边队尾出队到右边队首。反之就是右边队首
出到左边的队尾。
*/
#include<bits/stdc++.h> 

using namespace std;
const int N=1e7+10;
char s[10];
int vis[N];
deque<int> lq,rq;
int lnum,rnum;
void solve(){
	while(lnum>rnum){
		while(vis[lq.back()]==0){
			lq.pop_back();
		}
		rq.push_front(lq.back());
		lq.pop_back();
		vis[rq.front()]=2;
		rnum++;
		lnum--;
	}
	while(rnum>lnum+1){
		while(vis[rq.front()]==0){
			rq.pop_front();
		}
		lq.push_back(rq.front());
		rq.pop_front();
		vis[lq.back()]=1;
		rnum--;
		lnum++;
	}
}
int main(){
	int q;
	scanf("%d",&q);
	getchar();
	int cnt=0; 
	while(q--){
		scanf("%s",s);
		if(*s=='L'){
			lq.push_front(++cnt);
			vis[cnt]=1;
			lnum++;
			solve();
		}else if(*s=='R'){
			rq.push_back(++cnt);
			vis[cnt]=2;
			rnum++;
			solve();
		}else if(*s=='Q'){
			while(vis[rq.front()]==0){
				rq.pop_front();
			}
			if(rq.size()==0) printf("0\n");
			else printf("%d\n",rq.front());
		}else if(*s=='G'){
			int x;
			scanf("%d",&x);
			if(vis[x]==1) lnum--;
			else if(vis[x]==2) rnum--;
			vis[x]=0;
			solve();
		}
	}
	return 0;
}