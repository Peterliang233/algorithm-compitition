/*
这个题目是找到一个seed，要求任意一个数字对这个seed取模之后的数都不是一样的，
那么我们就可以根据同余做法知道这个seed不能是任意两个数字的差值，所以我们要找到一个
seed，这个seed不能是任意两个数字的差值，但是我们发现，我们不能直接利用循环求出任意两个
数字之间的差值，但是我们可以利用FFT加速在O(nlogn)的时间复杂度下得到，为什么要用FFT呢？
假如存在两个数字5和3，那么在一个多项式里面x^5的系数为1，在另一个多项式里面x^(-3)的系数为1，
那么，这两个多项式相乘可以得到x^2,所以2就不能是我们要选择的seed，其余的同理。
*/

#include<bits/stdc++.h>
using namespace std;
const int N=3000050;
const double PI=acos(-1.0);
const int avg=500000;
int vis[500050];

int lim=1,rev[N];
struct cp
{
    double x,y;
    cp(double u=0,double v=0){x=u,y=v;}
    friend cp operator +(const cp &u,const cp &v){return cp(u.x+v.x,u.y+v.y);}
    friend cp operator -(const cp &u,const cp &v){return cp(u.x-v.x,u.y-v.y);}
    friend cp operator *(const cp &u,const cp &v){return cp(u.x*v.x-u.y*v.y,u.x*v.y+u.y*v.x);}
}f[N],g[N];

void FFT(cp *a,int tp)
{
    for(int i=0;i<lim;i++)
        if(i<rev[i])
            swap(a[i],a[rev[i]]);
    for(int md=1;md<lim;md<<=1)
    {
        cp rt=cp(cos(PI/md),tp*sin(PI/md));
        for(int stp=md<<1,pos=0;pos<lim;pos+=stp)
        {
            cp w=cp(1,0);
            for(int i=0;i<md;i++,w=w*rt)
            {
                cp x=a[pos+i],y=w*a[pos+md+i];
                a[pos+i]=x+y;
                a[pos+md+i]=x-y;
            }
        }
    }
}

void initFFT(int n)
{
    int lg=0;
    while(lim<=n)
        lg++,lim<<=1;
    for(int i=0;i<lim;i++)
        rev[i]=(rev[i>>1]>>1)|((i&1)<<(lg-1));
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int d;
        scanf("%d",&d);
        //记录d和-d
        f[avg+d].x+=1;
        g[avg-d].x+=1;
    }
    
    //根据乘法的值域预处理FFT蝴蝶变换，加快FFT速度
    initFFT(avg*4);
    
    //正常FFT流程
    FFT(f,1),FFT(g,1);
    for(int i=0;i<lim;i++)
        f[i]=f[i]*g[i];
    FFT(f,-1);
    
    //记录是否存在差值为i的情况（i+avg*2即多项式乘法内的结果下标）
    for(int i=1;i<=500001;i++)
        vis[i]=(int)round(f[i+avg*2].x/lim);
    
    //枚举seed，判断可行性
    for(int i=n;i<=500001;i++)
    {
        if(vis[i]>0)
            continue;
        for(int j=i+i;j<=500000;j+=i)
        {
            //如果存在差值j（i的倍数），则i不可行
            if(vis[j])
            {
                vis[i]=1;
                break;
            }
        }
        //i可行，作为模数输出即可
        if(vis[i]==0)
        {
            cout<<i<<'\n';
            return 0;
        }
    }
    
    return 0;
}