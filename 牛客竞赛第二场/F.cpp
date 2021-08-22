/*
数学几何题目，根据题目要求可以得到是两个圆，所以就是求两个球的相交部分的面积
*/

#include <bits/stdc++.h>
#define INF 99999999
#define LINF LLONG_MAX 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX_N=1;
const double pi = acos(-1);

int T;
double x[5],y[5],z[5];
double k1,k2;

void solve(double x1,double y1,double z1,double r1,double x2,double y2,double z2,double r2){
    double ans=0;
    //球心距离 
    double dis=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2));
    //相离或相切 
    if(dis>=r1+r2){
        ans=0;
    }
    //内含或内切 
    else if (dis+r1<=r2){
        ans=(4.00/3.00)*pi*r1*r1*r1;
    }
    else if(dis+r2<=r1){
        ans=(4.00/3.00)*pi*r2*r2*r2;
    }
    //相交 
    else{
        //计算cos1 
        double cal=(r1*r1+dis*dis-r2*r2)/(2.00*dis*r1);
        //计算h1 
        double h=r1*(1-cal);
    	//计算球缺1体积 
        ans+=(1.00/3.00)*pi*(3.00*r1-h)*h*h;
        //计算cos2 
        cal=(r2*r2+dis*dis-r1*r1)/(2.00*dis*r2);
        //计算h2 
        h=r2*(1.00-cal);
        //计算球缺2体积 
        ans+=(1.00/3.00)*pi*(3.00*r2-h)*h*h;
    }
    printf("%.3f\n",ans);
}

int main(){
	cin>>T;
	while(T--){
		for(int i=0;i<4;i++)
			cin>>x[i]>>y[i]>>z[i];
		cin>>k1>>k2;
		//计算球1的球心坐标和半径 
		double xishu1=k1*k1-1;
		double c1x,c1y,c1z,c1r,t;
		c1x=(k1*k1*x[1]-x[0])/xishu1;
		c1y=(k1*k1*y[1]-y[0])/xishu1;
		c1z=(k1*k1*z[1]-z[0])/xishu1;
		t=k1*k1*((x[1]*x[1])+(y[1]*y[1])+(z[1]*z[1]))-x[0]*x[0]-y[0]*y[0]-z[0]*z[0];
		t/=xishu1;
		c1r=sqrt(c1x*c1x+c1y*c1y+c1z*c1z-t);
		//计算球2的球心坐标和半径 
		double xishu2=k2*k2-1;
		double c2x,c2y,c2z,c2r;
		c2x=(k2*k2*x[3]-x[2])/xishu2;
		c2y=(k2*k2*y[3]-y[2])/xishu2;
		c2z=(k2*k2*z[3]-z[2])/xishu2;
		t=k2*k2*((x[3]*x[3])+(y[3]*y[3])+(z[3]*z[3]))-x[2]*x[2]-y[2]*y[2]-z[2]*z[2];
		t/=xishu2;
		c2r=sqrt(c2x*c2x+c2y*c2y+c2z*c2z-t);
		//计算两个球相交部分体积 
		solve(c1x,c1y,c1z,c1r,c2x,c2y,c2z,c2r);
	}
	return 0;
}

/*
样例
1
1 0 0
3 0 0
2 0 0
4 0 0
3 3
输出
0.262
*/