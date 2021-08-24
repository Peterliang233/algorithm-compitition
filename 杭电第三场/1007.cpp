/*
一个简单的模拟题，根据题目模拟即可
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int r[100010],g[100010],b[100010];
char color[6],op[100010];
int sumr[100010],sumg[100010],sumb[100010];
int n,q;
int pre[100010];
int deal(char x,char y){
//    cout<<x<<" "<<y<<endl;
    int res=0;
    if(y>='0'&&y<='9') res+=(y-'0');
    else res=(y-'A'+10);
    if(x>='0'&&x<='9') res+=(x-'0')*16;
    else res+=(x-'A'+10)*16;
    //cout<<res<<endl;
    return res;
    //cout<<x<<" "<<y<<" "<<res<<endl; 
}
string Hex(int x){
    string res="";
    while(x){
        int tmp=x%16;
        if(tmp<10) res+=(tmp+'0');
        else res+=(tmp-10+'A');
        x/=16;
    }
    reverse(res.begin(),res.end());
    while(res.size()<2){
        res="0"+res;
    }
    return res;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&q);
        int now=0;
        for(int i=1;i<=n;i++){
            scanf("%d %s",&op[i],color);
            //printf("%s\n",color);
            if(op[i]==1) now=i;
            pre[i]=now;
            r[i]=deal(color[0],color[1]);
            g[i]=deal(color[2],color[3]);
            b[i]=deal(color[4],color[5]);
            if(op[i]==1){
                sumr[i]=sumr[i-1];
                sumg[i]=sumg[i-1];
                sumb[i]=sumb[i-1];
            }else{
                sumr[i]=sumr[i-1]+r[i];
                sumg[i]=sumg[i-1]+g[i];
                sumb[i]=sumb[i-1]+b[i];
            }
        }
        while(q--){
            int L,R;
            scanf("%d%d",&L,&R);
            int pos=pre[R];
            int rr=0,gg=0,bb=0;
            if(pos<L){
                rr+=(sumr[R]-sumr[L-1]);
                gg+=(sumg[R]-sumg[L-1]);
                bb+=(sumb[R]-sumb[L-1]);
            }else{
                rr+=(sumr[R]-sumr[pos]);
                gg+=(sumg[R]-sumg[pos]);
                bb+=(sumb[R]-sumb[pos]);
                rr+=r[pos];
                gg+=g[pos];
                bb+=b[pos];
            }
            rr=min(rr,255);
            gg=min(gg,255);
            bb=min(bb,255);
        //    cout<<rr<<" "<<gg<<" "<<bb<<endl;
            printf("%02X%02X%02X\n",rr,gg,bb);
        }
    } 
    return 0;
}

