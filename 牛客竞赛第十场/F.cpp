/*
我们需要把这个模型搬到树上，根据括号序列，我们可以建一棵树，然后就是对于树上每个结点，
它的子节点要求分配不同的数字。所以我们需要自定义堆。堆的元素是结构体。
我们要让num更大的放到堆顶上面。维护堆顶是颜色数字最多的那个。一直分配下去就行了
*/

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=1e6+10;

char s[N];

int ans[N],c[N],f[N];

int head[N<<1],ver[N<<1],nxt[N<<1],tot;

int mp[N];

struct node{
	int val;
	int num;
	
	friend bool operator <(node p,node q){
		return p.num<q.num;
	}
}a[N],Node;


void add(int x,int y){
	ver[++tot]=y;
	nxt[tot]=head[x];
	head[x]=tot;
}

queue<int> q;
priority_queue<node> pq;
vector<int> v;
bool flag=true;
void bfs(){
	
	q.push(0);
	
	while(!q.empty()){
		int x=q.front();
		q.pop();
		v.clear();
		for(int i=head[x];i;i=nxt[i]){
			int y=ver[i];
			v.push_back(y);
			q.push(y);
		}
		
		
		int len=v.size();
		
		
		// 不能放
		int k=pq.size();
		if(k<len){
			puts("NO");
			flag=false;
			return;
		}
		
		for(int i=0;i<len;i++){
			a[i]=pq.top();
			pq.pop();
			ans[v[i]]=a[i].val;
			a[i].num--;
		}
		
		for(int i=0;i<len;i++){
			if(a[i].num){
				pq.push(a[i]);
			}
		}
	}
}

int main(){
	int n;
	scanf("%d",&n);
	getchar();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	
	int now=0;
	int cnt=0;
	int m=n+n;
	for(int i=1;i<=m;i++){
		if(s[i]=='('){
			++cnt;
			//cout<<cnt<<" "<<now<<endl;
			add(now,cnt);
			f[cnt]=now;
			now=cnt;
		}else{
			now=f[now];
		}
	}
	
	int pos=0;
	for(int i=1;i<=n;i++){
		if(mp[c[i]]==0){
			mp[c[i]]=++pos;
			a[pos].val=c[i];
		}
		
		a[mp[c[i]]].num++;
	}
	
	for(int i=1;i<=pos;i++){
		pq.push(a[i]);
	}
	
	
	bfs();
	
	if(flag){
		puts("YES");
		for(int i=1;i<=cnt;i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}