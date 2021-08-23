/*
一个扫描线的题目，我们需要先把矩形移到一个dxd的区间里面，然后
我们找到这个区间的只需要找到这个区间没有被覆盖的点就行了，注意这里的矩形
可能会被切割为四块，需要进行处理，然后就是一个扫描线的题目了，求区间并，然后进行查询。
*/


#include<bits/stdc++.h>


using namespace std;

const int N=500010;

int ql,qr;


struct node{
	int l,r,x;
};

vector<node> v[N];

struct p{
	int s,len;
}q[N];


void add(int x1,int x2,int y1,int y2){
	v[x1].push_back({y1,y2,1});
	v[x2+1].push_back({y1,y2,-1});
}

void pushup(int i,int l,int r){
	if(q[i].s){
		q[i].len=r-l+1;
	}else if(l==r){
		q[i].len=0;
	}else{
		q[i].len=q[i<<1].len+q[i<<1|1].len;
	}
}


void change(int p,int l,int r,int xx){
	if(ql<=l&&qr>=r){
		q[p].s+=xx;  // 打个懒标记 
		pushup(p,l,r);
		return;
	}
	
	int mid=(l+r)>>1;
	if(ql<=mid){
		change(p<<1,l,mid,xx);
	}
	if(qr>mid){
		change(p<<1|1,mid+1,r,xx);
	}
	pushup(p,l,r);
}


void get(int p,int l,int r){
	if(q[p].len==0){
		printf("%d\n",l);
		return;
	}
	
	int mid=(l+r)>>1;
	if(q[p<<1].len<mid-l+1){
		get(p<<1,l,mid);
	}
	else{
		get(p<<1|1,mid+1,r);
	}
}


int main(){
	
	int n,d;
	scanf("%d %d",&n,&d);
	for(int i=1;i<=n;i++){
		int x1,y1,x2,y2;
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		x2--,y2--;
		if(x2-x1+1>=d){
			x1=0,x2=d-1;
		}
		
		
		if(y2-y1+1>=d){
			y1=0,y2=d-1;
		}
		
		
		x1=(x1%d+d)%d;
		x2=(x2%d+d)%d;
		y1=(y1%d+d)%d;
		y2=(y2%d+d)%d;
		
		
		if(x1<=x2){
			if(y1>y2){
				add(x1,x2,y1,d-1);
				add(x1,x2,0,y2);
			}else{
				add(x1,x2,y1,y2);
			}
		}else{
			if(y1>y2){
				add(x1,d-1,y1,d-1);
				add(x1,d-1,0,y2);
				add(0,x2,y1,d-1);
				add(0,x2,0,y2);
			}else{
				add(x1,d-1,y1,y2);
				add(0,x2,y1,y2);
			}
		}
	}
	
	
	for(int i=0;i<d;i++){ // 扫描每一条纵坐标轴 
		for(int j=0;j<v[i].size();j++){
			ql=v[i][j].l;
			qr=v[i][j].r;
			// 找到这个横坐标轴对应的所有的线然后放入线段树进行维护 
			change(1,0,d-1,v[i][j].x);
		}
		if(q[1].len<d){  // 如果这个线段树的所有的和长度加起来小于d 
			printf("YES\n%d ",i);
			get(1,0,d-1);
			return 0;
		}
	}
	
	puts("NO");
	return 0;
}