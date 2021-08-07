/*
与逆序对有关，可以使用归并排序或者树状数组进行求解
*/
#include<iostream>
#define ll long long

using namespace std;

const int N=200010;

int q[N],tmp[N];
int n;


ll merge_sort(int l,int r){
    if(l>=r)    return 0;
    int mid=(l+r)>>1;
    ll res=merge_sort(l,mid)+merge_sort(mid+1,r);
    
    int k=0,i=l,j=mid+1;
    while(i<=mid&&j<=r){
        if(q[i]<=q[j])  tmp[k++]=q[i++];
        else{
            tmp[k++]=q[j++];
            res+=(mid-i+1);
        }
    }
    while(i<=mid)   tmp[k++]=q[i++];
    while(j<=r)     tmp[k++]=q[j++];
    for(int i=l,j=0;i<=r;i++,j++)   q[i]=tmp[j];
    return res;
}

int vis[N];

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
    	scanf("%d",&q[i]);
    	if(vis[q[i]+1])	q[i]++;
    	vis[q[i]]=1;
	}
    printf("%lld",merge_sort(0,n-1));
}