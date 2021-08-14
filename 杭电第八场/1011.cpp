/*
先暴力将文本串里面的长度为30以下的字符放到字典树上进行存储，同时相交部分
直接跳过。然后询问的时候就可以使用暴力统计了。
当然，这题也有ac自动机的算法，方法更加高效
*/

#include<bits/stdc++.h> 

using namespace std;
const int maxn=100010;

char s[100010],a[35];

struct Trie{
    int son[maxn*30][26],las[maxn*30],fla[maxn*30],r;
    void clear(){
        memset(son,0,sizeof(son));
        memset(las,0,sizeof(las));
        memset(fla,0,sizeof(fla));
        r=1;
    }
    
    int add(int thi,char x){
        if(son[thi][x]==0){
            r++;
            son[thi][x]=r;
        }
        return son[thi][x];
    }
}tre;



void solve(){
    scanf("%s",s);
    int len=strlen(s);
    tre.clear();
    
    
    // 枚举起点 
    for(int j=0;j<len;j++){
        int thi=1;
        
        // 枚举终点 
        for(int k=0;k<min(len-j,30);k++){
            thi=tre.add(thi,s[j+k]-'a');
            
            
            // 如果上一个这个字符的终点小于等于这个字符的起点 
            if(tre.las[thi]<=j){
                tre.las[thi]=j+k+1;
                tre.fla[thi]++;
            }
        }
    }
    
    int n;
    scanf("%d",&n);
    
    while(n--){
        scanf("%s",a);
        int thi=1;
        int len=strlen(a);
        for(int j=0;j<len;j++){
            thi=tre.add(thi,a[j]-'a');
        }
        
        printf("%d\n",tre.fla[thi]);
    }
}

int main(){
//    freopen("test.in","r",stdin);
//    freopen("test.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}