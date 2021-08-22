/*
现在给出一个nxm的点阵，需要我们从这个点阵里面每次选择两个点进行连线，但是要求不能成环。需要判断可以操作多少次？
这个其实就是给我们nm个点，需要我们找出有可以连多少个边，根据最小生成树的知识，可以知道需要连n*m-1次，判断一下奇偶行了
*/

#include<bits/stdc++.h>

using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int ans=n*(m-1)+(n-1);
    if(ans&1){
        puts("YES");
    }else{
        puts("NO");
    }
    return 0;
}