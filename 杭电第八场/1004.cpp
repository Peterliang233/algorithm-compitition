/*
线段树，分别按照高位和低位进行维护，线段树维护三个值，
区间二进制下的1的个数，区间的最高位对应的十进制，区间除最高位外的和
*/
#include<bits/stdc++.h> 

using namespace std;
typedef long long ll;
const int mod = 998244353;
const int N=100010;

int a[N];
ll P[N<<2];

struct node{
    int l,r;
    ll tag;  // 这个区间的最高位需要乘多少次2 
    ll num1; // 这个数字存在多少个1
    ll up;    // 存储最高位的数 
    ll down;  // 存储除最高位的数 
}Node[N<<2];


void pushup(int p){
    Node[p].down=(Node[p<<1].down+Node[p<<1|1].down)%mod;
    Node[p].up=(Node[p<<1].up+Node[p<<1|1].up)%mod;
    Node[p].num1=(Node[p<<1].num1+Node[p<<1|1].num1);
}


void pushdown(int p){
    if(Node[p].tag)    {
        Node[p<<1].up=(Node[p<<1].up*P[Node[p].tag]%mod)%mod;
        Node[p<<1|1].up=(Node[p<<1|1].up*P[Node[p].tag]%mod)%mod;
        Node[p<<1].tag+=Node[p].tag;
        Node[p<<1|1].tag+=Node[p].tag;
        Node[p].tag=0;
    }
}


void build(int p,int l,int r){
    Node[p].l=l,Node[p].r=r;
    if(l==r){
        Node[p].tag=0;
        Node[p].down=a[l];
        for(int i=0;i<=30;i++){
            if((a[l]>>i)&1){
                Node[p].num1++;
                Node[p].up=1<<i;
            }
        }
        Node[p].down=Node[p].down-Node[p].up;
        return;
    }
    
    int mid=(l+r)>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    
    pushup(p);
}

// 区间所有的数都减去最低位的1 
void change1(int p,int l,int r){
    if(Node[p].num1==0) return;
    if(Node[p].l==Node[p].r){
        Node[p].num1--;
        Node[p].down-=(Node[p].down&(-Node[p].down));
        if(Node[p].num1==0){
            Node[p].down=0;
            Node[p].up=0;
        }
        return;
    }
    
    pushdown(p);
    int mid=(Node[p].l+Node[p].r)>>1;
    if(l<=mid) change1(p<<1,l,r);
    if(r>mid) change1(p<<1|1,l,r);
    pushup(p);
}


// 区间的所有的数的最高位同时乘上1 
void change2(int p,int l,int r){
    if(Node[p].l>=l&&Node[p].r<=r){
        Node[p].tag++;
        Node[p].up=Node[p].up*2ll%mod;
        return;
    }
    
    pushdown(p);
    
    int mid=(Node[p].l+Node[p].r)>>1;
    
    if(l<=mid) change2(p<<1,l,r);
    if(r>mid) change2(p<<1|1,l,r);
    pushup(p);
}


ll ask(int p,int l,int r){
    if(Node[p].l>=l&&Node[p].r<=r){
        return (Node[p].up+Node[p].down)%mod;
    }
    int mid=(Node[p].l+Node[p].r)>>1;
    
    pushdown(p);
    
    ll res=0;
    if(l<=mid) res+=ask(p<<1,l,r);
    if(r>mid) res+=ask(p<<1|1,l,r);
    return res;
}


void init(){
    P[0]=1;
    for(int i=1;i<=200000;i++){
        P[i]=P[i-1]*2%mod;
    }
}

int main(){
    init();
    int t;
    scanf("%d",&t);
    while(t--){
        memset(Node,0,sizeof(Node));
        int n;
        scanf("%d",&n);
        
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        
        
        build(1,1,n);
        int q;
        scanf("%d",&q);
        
        while(q--){
            int op,l,r;
            
            scanf("%d %d %d",&op,&l,&r);
            
            
            if(op==1){
                // 执行区间查询操作 
                printf("%lld\n",ask(1,l,r)%mod);
            }else if(op==2){
                // 执行减法操作 
                change1(1,l,r);
            }else{
                // 执行加法操作 
                change2(1,l,r);
            }
        }
    }
    return 0;
}