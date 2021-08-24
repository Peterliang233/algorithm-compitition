/*
一个模拟题，根据题目的意思进行模拟就可，注意细节
*/
#include<bits/stdc++.h> 

using namespace std;

int X[]={0,0,1,-1};
int Y[]={1,-1,0,0};

int x,y,d;
struct node{
    int x,y;
}Node;

void solve(){
    scanf("%d %d %d",&x,&y,&d);
    int n;
    scanf("%d",&n);
    string ans="";
    for(int i=1;i<=n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        while(1){
            if(u==x&&y==v) break;
            if(d==0){
                if(y<v){
                    ans+="f";
                    y++;
                }else if(y==v){
                    if(x>u){
                        ans+="u";
                        d=3;
                    }else{
                        ans+="c";
                        d=1;
                    }
                }else{
                    if(u<x){
                        ans+="u";
                        d=3;
                    }else if(u>x){
                        ans+="c";
                        d=1;
                    }else if(u==x){
                        ans+="cc";
                        d=2;
                    }
                }
            }else if(d==1){
                if(u>x){
                    ans+="f";
                    x++;
                }else if(u==x){
                    if(y>v){
                        ans+="c";
                        d=2;
                    }else{
                        ans+="u";
                        d=0;
                    }
                }else{
                    if(y<v){
                        ans+="u";
                        d=0;
                    }else if(y>v){
                        ans+="c";
                        d=2;
                    }else{
                        ans+="cc";
                        d=3;
                    }
                }
            }else if(d==2){
                if(v<y){
                    ans+="f";
                    y--;
                }else if(y==v){
                    if(x>u){
                        ans+="c";
                        d=3;
                    }else{
                        ans+="u";
                        d=1;
                    }
                }else{
                    if(x>u){
                        ans+="c";
                        d=3;
                    }else if(x<u){
                        ans+="u";
                        d=1;
                    }else{
                        ans+="cc";
                        d=0;
                    }
                }
            }else{
                if(u<x){
                    ans+="f";
                    x--;
                }else if(u==x){
                    if(y>v){
                        ans+="u";
                        d=2;
                    }else{
                        ans+="c";
                        d=0;
                    }
                }else{
                    if(y>v){
                        ans+="u";
                        d=2;
                    }else if(y<v){
                        ans+="c";
                        d=0;
                    }else{
                        ans+="cc";
                        d=1;
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
} 