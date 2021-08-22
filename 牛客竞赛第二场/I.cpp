/*
有两个人同时在一个二维点阵上面行走，方向都是呈镜像的，如果遇到障碍物就不能走，
问最后能否同时到达某个位置。这个是多状态的BFS，其实和普通的BFS没啥两样。就是状态的记录要更多。
最后寻找路径就逆着走就行了。
*/
#include<bits/stdc++.h> 

using namespace std;

char s[22][22],c[22][22];

int vis[22][22][22][22];  // 记录这个状态的位置走的步数 

vector<char> ans;

// 按照字典序进行走，注意两个位置的左右方向是相反的，上下方向是相同的 
int dirl[4][2]={1,0,0,-1,0,1,-1,0};
int dirr[4][2]={1,0,0,1,0,-1,-1,0};

char tag[]="DLRU";

char as[22][22][22][22];  // 用来记录这个状态的这个位置走的方向 

pair<pair<int,int>,pair<int,int> > lst[22][22][22][22];  // 记录这个状态前一个状态 

void check1(int &x,int &y,int i){
	int u=x+dirl[i][0];
	int v=y+dirl[i][1];
	// 如果这个新的位置不合法，那么就取原来的位置 
	if(u<1||u>20||v<1||v>20||s[u][v]=='#'){
		u=x,v=y;
	}
	x=u;
	y=v;
}

void check2(int &x,int &y,int i){
	int u=x+dirr[i][0];
	int v=y+dirr[i][1];
	// 如果这个新的位置不合法，则不动 
	if(u<1||u>20||v<1||v>20||c[u][v]=='#'){
		u=x,v=y;
	}
	x=u,y=v;
}


void bfs(){
	queue<pair<pair<int,int>,pair<int,int>> > q;
	q.push({{20,20},{20,1}});
	memset(vis,-1,sizeof(vis));
	as[20][20][20][1]='0';
	vis[20][20][20][1]=0;
	while(!q.empty()){
		int x1=q.front().first.first,y1=q.front().first.second;
		int x2=q.front().second.first,y2=q.front().second.second;
		
		q.pop();
		
		// 四个方向 
		for(int i=0;i<4;i++){
			int x3=x1,y3=y1,x4=x2,y4=y2;
			
			check1(x3,y3,i);
			check2(x4,y4,i);
			
			// 如果这个位置走过
			if(vis[x3][y3][x4][y4]!=-1)  continue;
			
			 
			vis[x3][y3][x4][y4]=vis[x1][y1][x2][y2]+1;
			
			as[x3][y3][x4][y4]=tag[i];
			
			lst[x3][y3][x4][y4]={{x1,y1},{x2,y2}};
			q.push({{x3,y3},{x4,y4}});
			if(x3==1&&y3==20&&x4==1&&y4==1){
				return;
			}
		}
	}
}

int main(){
	for(int i=1;i<=20;i++){
		for(int j=1;j<=41;j++){
			if(j<21) cin>>s[i][j];
			else if(j>21) cin>>c[i][j-21];
		}
	}
	
	bfs();
	
	int xa=1,ya=20,xb=1,yb=1;
	
	cout<<vis[1][20][1][1]<<endl;
	
	while(1){
		ans.push_back(as[xa][ya][xb][yb]);
		s[xa][ya]=c[xb][yb]='A';
		
		int u=lst[xa][ya][xb][yb].first.first;
		int v=lst[xa][ya][xb][yb].first.second;
		int w=lst[xa][ya][xb][yb].second.first;
		int t=lst[xa][ya][xb][yb].second.second;
		
		xa=u,ya=v;
		xb=w,yb=t;
		if(vis[xa][ya][xb][yb]==0){
			s[xa][ya]=c[xb][yb]='A';
			break;
		}
	}
	
	reverse(ans.begin(),ans.end());
	
	for(auto x:ans){
		cout<<x;
	}
	cout<<endl;
	
	for(int i=1;i<=20;i++){
		for(int j=1;j<=20;j++){
			cout<<s[i][j];
		}
		cout<<" ";
		for(int j=1;j<=20;j++){
			cout<<c[i][j];
		}
		cout<<endl;
	}
	return 0;
}