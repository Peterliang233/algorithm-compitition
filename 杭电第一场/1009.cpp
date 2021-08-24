/*
把一个图分成k部分，对于相同部分的结点，至少有一条两点之间的路径小于等于D，
对于不同部分的结点，不能有任意的路径之间的最大价值小于等于D
利用最小生成树的克鲁斯卡尔算法进行求解，我们从小的边权开始进行枚举，这样就确保了我们枚举的一定是
当前已知的边的最大的
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int fa[maxn];
int get(int x){
    if(x==fa[x]) return fa[x];
    return fa[x]=get(fa[x]);
}
struct node{
    int x,y,z;
}Node[maxn];
bool operator < (node a,node b){
    return a.z<b.z;
}
int main(){
//    freopen("test.in","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        for(int i=1;i<=m;i++){
            scanf("%d%d%d",&Node[i].x,&Node[i].y,&Node[i].z);
        }
        sort(Node+1,Node+1+n);
        int now=n;
        for(int i=1;i<=n;i++){
            fa[i]=i;
        }
        int ans=0;
        for(int i=1;i<=m;i++){
            if(Node[i].z!=Node[i-1].z){
                if(now==k){
                    break;                    
                }
            }
            int x=get(Node[i].x),y=get(Node[i].y);
            if(x==y) continue;
            fa[x]=y;
            now--;
            ans=Node[i].z;
        }
        if(now!=k) ans=-1;
        printf("%d\n",ans);
    }
    return 0;
}

