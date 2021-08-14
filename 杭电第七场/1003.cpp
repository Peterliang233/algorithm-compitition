/*这个没啥，就是先列数公式直接计算即可，另外就是
杭电不能使用long double。也不说，坑人啊
*/
#include<bits/stdc++.h> 

using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int k;
           scanf("%d",&k);
        double rtx,rty,lx,ly,rx,ry;
        scanf("%lf %lf %lf %lf %lf %lf",&rtx,&rty,&lx,&ly,&rx,&ry);
        
        
        double ans=fabs(lx-rtx)*fabs(ly-rty);
        k-=2;
        double h=abs(rty-ly)/2.0;
        double len=fabs(rx-lx);
        double tmp=(4*k-3)*len;
        double tmp1=pow(2.00000,-1.0*k);
        tmp1*=3.0;
        tmp1=tmp1*len;
        tmp+=tmp1;
        ans+=tmp*h;
        printf("%.3lf\n",ans);
    }
    return 0;
}