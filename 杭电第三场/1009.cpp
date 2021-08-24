/*
一个nxn的矩阵，可以向下和向右移动，每次移动在每个地方aij和bij,最后需要我们最大化走过的suma*sumb
*/

#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<pair<int,int>> V;
int n;
int a[120][120],b[120][120];
V f[110][110];
pii q[1000010];

int m=0;
void Exect(const pii &t){
    while(m&&t.second>=q[m].second) m--;
    if(!m||t.first>q[m].first) q[++m]=t;
}
void Merge(const V &A,const V &B,V &C){
    m=0;
    int ca=A.size(),cb=B.size(),cc=C.size();
    int i=0,j=0;
    while(i<ca&&j<cb){
        if(A[i].first<B[j].first){
            Exect(A[i++]);
        }else{
            Exect(B[j++]);
        }
    }
    while(i<ca) Exect(A[i++]);
    while(j<cb) Exect(B[j++]);
    C.resize(m);
    for(int i=0;i<m;i++){
        C[i]=q[i+1];
    }
}
int main(){
    int Case;
    cin>>Case;
    while(Case--){
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin>>a[i][j];
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin>>b[i][j];
            }
        }
        f[1][1].resize(n);
        f[1][1][0]=make_pair(a[1][1],b[1][1]);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==1&&j==1) continue;
                else if(i==1) f[i][j]=f[i][j-1];
                else if(j==1) f[i][j]=f[i-1][j];
                else Merge(f[i-1][j],f[i][j-1],f[i][j]);
                for(int k=0;k<f[i][j].size();k++){
                    f[i][j][k].first+=a[i][j];
                    f[i][j][k].second+=b[i][j];
                }
            }
        }
        ll ans=0;
        for(int i=0;i<f[n][n].size();i++){
            ans=max(ans,(ll)f[n][n][i].first*f[n][n][i].second);
        }
        cout<<ans<<endl;
    }
    return 0;
}

