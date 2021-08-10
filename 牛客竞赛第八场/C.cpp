/*
选出三个点，这三个点的和为n，同时要满足三个点是递增的，
枚举两个点，找到第三个点
*/


#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    scanf("%d",&n);


    int sum=n*(n-1)/2;

    int tmp=(sum-n)/3+1;
    printf("%d\n",tmp);

    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int z=n-i-j;
            if(z<=0) z+=n;
            if(z>j) printf("%d %d %d\n",i,j,z);
        }
    }
    return 0;
}