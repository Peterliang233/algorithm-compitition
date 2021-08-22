/*
给你一个数组，要求对这个数组进行排列，使得我们最后得到的数组
的数字和它的下标的差值卡根号取和之后的差值最小，允许有误差。
做法有点玄学，涨知识了
*/

#include<bits/stdc++.h>

using namespace std;
const int N=1010;
double a[N];

double calc(double x,double y){
    return sqrt(abs(x-y));
}

void solve(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lf",&a[i]);
    }
    
    int times=3;
    while(times--){
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(calc(i,a[i])+calc(j,a[j])>calc(j,a[i])+calc(i,a[j])){
                    swap(a[i],a[j]);
                }
            }
        }
    }
    
    for(int i=0;i<n;i++){
        printf("%.0lf ",a[i]);
    }
    puts("");
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}