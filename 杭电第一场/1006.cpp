#include<bits/stdc++.h> 
using namespace std;
int a[5000010];
int trie[5000010][2];
int mx[5000010],tot;  // mx[i]表示某一个指针i的最右边出现的位置 
int main(){
    //freopen("test.in","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--){
        int n,k;
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
            a[i]=a[i-1]^x;
        }
        trie[1][0]=trie[1][1]=0;
        mx[1]=-1;
        tot=1;
        // 初始化最终的答案 
        int resl=-1,resr=n;
        for(int i=1;i<=n;i++) {
            int p=1; // 每次遍历的时候初始化trie树的指针
            int tmp=-1;
            // 从高位开始进行遍历 
            for(int j=29;j>=0;j--){
                int now=(a[i]>>j)&1;
                
                // 如果k的这个位置的二进制为0 ，那么我们就要想办法让我们
                // 异或下来的这个位置的数字为1 
                if(!((k>>j)&1)){
                    
                    // 如果存在这个指针
                    if(trie[p][now^1]){
                        // 我们找到满足条件的当前满足条件的指针最右边的位置 
                        tmp=max(tmp,mx[trie[p][now^1]]);
                    }
                    // 指针继续向下进行移动 
                    p=trie[p][now];
                }else{
                    // 如果k的二进制这个位置的数字为1，那么我们肯定是要找到能够使这个位置的异或下来为1的指针 
                    p=trie[p][now^1];
                }
                // 如果指针为空直接退出，也就是到了trie树的叶子结点，那么这个前缀和是在之前存在的，也就是之前出现过 
                if(!p) break;
            }
            
            // 如果指针使为空，那么说明存在满足条件的区间 
            if(p)  tmp=max(tmp,mx[p]);
            // 进行更新 
            if(tmp>=0&&i-tmp<resr-resl){
                resl=tmp;
                resr=i;
            }
            
            
            // 对当前位置的前缀和建trie，后面执行这个建树的操作不会影响当前的位置 
            p=1;  //从头结点开始进行遍历 
            for(int j=29;j>=0;j--){
                int now=(a[i]>>j)&1;
                if(!trie[p][now]){
                    // 如果这个指针不存在，那么就要我们新建一个 
                    trie[p][now]=++tot;
                    mx[tot]=-1;  // 将这个指针初始化为-1
                    // 然后将这个指针的左右指向0,表示空 
                    trie[tot][0]=trie[tot][1]=0;
                }
                
                // 移动指针 
                p=trie[p][now];
                
                // 更新这个结点出现的最靠近右边的位置 
                mx[p]=max(mx[p],i);
            }
        }
        if(resl>=0) printf("%d %d\n",resl+1,resr);
        else printf("-1\n");
    }
    return 0;
}