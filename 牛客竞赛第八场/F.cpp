/*
给出n个机器人的走的起始点和终止点，机器人有三种，只能向右走的，只能向下走的，
和能向右和向下走的，需要我们判断这个机器人是否可以到达终点。对于第三种机器人，我们
需要利用离线的方法来求，我们可以利用DP进行状态的转移。这里的DP我们用bitset进行优化，
使得我们可以当前的位置的状态可以得到
*/

#include<bits/stdc++.h>

using namespace std;
int c[550][550];
int ans[500010];
int hang[505][505],lie[505][505];

struct node{
	int x2,y1,y2,idx;
};
bitset<505> vis[505];
vector<node> v[505],tmp[505];

int main(){
	memset(ans,0,sizeof(ans));
    int n,m;
    cin>>n>>m;
    getchar();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
        	char ch;
        	cin>>ch;
            c[i][j]=ch-'0';
            hang[i][j]=hang[i][j-1]+c[i][j];
            lie[i][j]=lie[i-1][j]+c[i][j];
        }
    }

    int q;
    cin>>q;
    for(int i=1;i<=q;i++){
        // t为1表示这个可以向下走，为2表示可以向右走，为3表示可以向下和向右走
        int t,x1,y1,x2,y2;
        cin>>t>>x1>>y1>>x2>>y2;
        
        
        if(t==1){
        	// 同一列并且中间全部都是0 
            if(y1==y2&&x1<=x2&&lie[x2][y2]-lie[x1-1][y1]==0) ans[i]=1;
        }else if(t==2){
        	// 同一行并且中间全部都是0 
            if(x1==x2&&y1<=y2&&hang[x2][y2]-hang[x1][y1-1]==0) ans[i]=1;
        }else{
            if(x1<=x2&&y1<=y2){
            	v[x1].push_back({x2,y1,y2,i});
			}
        }
    }
    
    // 枚举行 
    for(int i=1;i<=n;i++){
    	// 我们先看这一行需要到哪些位置，这些位置先记录在tmp里面 
    	for(auto o:v[i]){
    		tmp[o.x2].push_back(o);
		}
		// 先将所有的列清空
		for(int j=1;j<=m;j++) vis[j].reset();
		
		// 枚举列 
		for(int j=1;j<=m;j++){
			if(c[i][j]==1) vis[j].reset();
			else vis[j][j]=1,vis[j]|=vis[j-1];
		}
		
		// 现在枚举完了当前行的所有的列 
		// 枚举这一行下面的所有行 
		for(int j=i;j<=n;j++){
			for(int k=1;k<=m;k++){
				vis[k]|=vis[k-1]; // 这一列继承左边那列 
				if(c[j][k]==1) vis[k].reset();// 遇到障碍物 
			}
			// 枚举这一行哪些是需要到达的 
			for(auto o:tmp[j]){
				ans[o.idx]=vis[o.y2][o.y1];
			}
			tmp[j].clear();
		}
	}
    
    for(int i=1;i<=q;i++){
        cout<<(ans[i]?"yes":"no")<<endl;
    }
    return 0;
}