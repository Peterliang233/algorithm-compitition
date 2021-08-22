/*
构造一个序列，使得这个序列满足所有的输入的x，y，即第以y位置结尾的递增的序列有x个。
我们可以按照题目的条件维护一个栈，然后将题目有限制的进行标记，同时记录下这个位置
的个数，然后，我们从1遍历到n，如果有限制，我们对限制进行分析，分析比较当前这个位置的个数和
题目限制的个数的差距进行处理，如果不足，那么肯定直接退出，否则恰好相等那么就直接补上，如果多了的话，
我们直接在那个位置补上就行了，同时更新此时栈的大小
*/

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N=1000010;

bool vis[1000010];
ll cnt[1000010];
ll st[1000010],a[1000010],b[1000010];
ll top=0;

int main(){
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=k;i++){
        int p,x;
        cin>>p>>x;
        vis[p]=true;
        cnt[p]=x;
    }
    
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            a[i]=i*N;
            st[++top]=a[i];
            cnt[i]=top;
        }
        else{
            if(cnt[i]>top+1){
                puts("-1");
                return 0;
            }else if(cnt[i]==top+1){
                a[i]=i*N;
                st[++top]=a[i];
            }else{
                st[cnt[i]]--;
                top=cnt[i];
                a[i]=st[top];
            }
        }
    }
    
    for(int i=1;i<=n;i++){
        b[i]=a[i];
    }
    
    sort(b+1,b+1+n);
    
    for(int i=1;i<=n;i++){
        cout<<lower_bound(b+1, b+1+n, a[i])-b<<" ";
    }
    return 0;
}