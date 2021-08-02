/*
一个比较简单的题目，找出若干个区间的交集为给出的m个区间的并集
答案一定存在，就是每个区间的左端点和与这个区间相差m-1个区间的右端点
但是请注意环的情况，采用拆环在后面再拼接上去
*/


#include<bits/stdc++.h>

using namespace std;

struct node{
    int l,r;
}Node[2010];

bool cmp(node a,node b){
    return a.l<b.l;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++){
            scanf("%d %d",&Node[i].l,&Node[i].r);
        }
        
        sort(Node+1,Node+1+m,cmp);


        for(int i=1;i<=m;i++){
            Node[i+m]=Node[i];
        }
        

        printf("%d\n",m);

        for(int i=1;i<=m;i++){
            printf("%d %d\n",Node[i].l,Node[i+m-1].r);
        }
    }
    return 0;
}