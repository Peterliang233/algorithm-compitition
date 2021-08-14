#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N =1e6+10,M =2*N;
string a[32];
signed main() {
    int T;
    cin>>T;
    for(int C=1;C<=T;C++){
        getchar();
        for(int i=1;i<=30;i++){
            getline(cin,a[i]);
        }
        int tt=0;
        printf("Case #%d:\n",C);
        for(int j=0;j<100;j++){
            int flag=0;
            for(int i=1;i<=30;i++){
                if(a[i][j]=='#'){
                    flag=1;
                    break;
                }
            }
            if(flag){
                int f=j;
                for(f=j;f<100;f++){
                    int flag1=0;
                    for(int k=1;k<=30;k++){
                        if(a[k][f]=='#'){
                            flag1=1;
                        }
                    }
                    if(!flag1&&!tt){
                        int cnt=0;
                        for(int kk=f-1;kk<=f+10;kk++){                    
                            for(int k=1;k<=30;k++){
                            if(a[k][kk]=='#'){
                                        cnt++;
                                        break;
                                }
                            }
                        }
                        if(cnt==3){
                            f=f+10;
                            f++;
                        }else{
                            cnt=0;
                            for(int kk=f-1;kk<=f+5;kk++){                    
                                for(int k=1;k<=30;k++){
                                if(a[k][kk]=='#'){
                                            cnt++;
                                            break;
                                    }
                                }
                            }
                            if(cnt==6){
                                f=f+5;
                                f++;
                            }
                        }
                    }
                    if(!flag1){
                        break;
                    }
                }
                f--;
                printf("%d %d\n",j+1,f+1);
                tt=1;
                j=f;
            }
        }
    }
    return 0;
}

