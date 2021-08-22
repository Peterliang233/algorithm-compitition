/*
一个几何题目，根据面积的相等可以得到我们要求的,
但是这个题目要注意夹不住球的情况和夹住刚好接触地面的情况，注意精度问题即可
*/
#include<bits/stdc++.h>

using namespace std;

int main(){
    double r,a,b,h;
    cin>>r>>a>>b>>h;
    
    double l=sqrt(h*h+(a-b)*(a-b)/4);
    
    double area=(a+b)*h/2.0;
    
    // 注意夹不住的情况
    if(2*r<=b){
        puts("Drop");
        return 0;
    }
    
    area-=l*r;
    
    area*=2.0;
    
    area-=a*h;
    
    double ans=area/(b-a);
    
    if(fabs(ans-r)<1e-8){
        puts("Drop");
    }else{
        puts("Stuck");
        printf("%.10lf\n",ans);
    }
    return 0;
}