/*
对于每个i，我们按位进行拆分，然后相邻的，如果没有被分配颜色，那么分配不同的就行了
*/

#include<bits/stdc++.h>

using namespace std;
int a[1<<25];
int main(){
    memset(a,-1,sizeof(a));
    int n;
    cin>>n;
    string ans="";
    a[0]=0;
    for(int i=0;i<(1<<n);i++){
        int k=i;
        for(int j=0;j<=23;j++){
            int x=(k>>j)&1;
            if(x==0){
                int now=k+(1<<j);
                if(a[now]==-1){
                    a[now]=a[i]?0:1;
                }
            }else{
                int now=k-(1<<j);
                if(a[now]==-1){
                    a[now]=a[i]?0:1;
                }
            }
        }
    }
    for(int i=0;i<(1<<n);i++){
        cout<<a[i];
    }
    cout<<endl;
    return 0;
}