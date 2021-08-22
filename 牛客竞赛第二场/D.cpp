/*
大模拟，根据题目模拟即可
*/
#include<iostream>

using namespace std;

int t;
int a1,b1;
int a2,b2;

int main(){
	cin>>t;
	while(t--){
		cin>>a1>>b1>>a2>>b2;
		if(a1>b1)	swap(a1,b1);
		if(a2>b2)	swap(a2,b2);
		int tmp1=(a1+b1)%10;
		int tmp2=(a2+b2)%10;
		if(a1==2&&b1==8&&a2==2&&b2==8)	puts("tie");
		else if(a1==2&&b1==8)	puts("first");
		else if(a2==2&&b2==8)	puts("second");
		else if(a1==b1&&a2!=b2)	puts("first");
		else if(a1!=b1&&a2==b2)	puts("second");
		else if(a1==b1&&a2==b2){
			if(a1==a2)	puts("tie");
			else if(a1>a2)	puts("first");
			else puts("second");
		}	
		else if(a1!=b1&&a2!=b2&&tmp1!=tmp2){
			if(tmp1>tmp2)	puts("first");
			else	puts("second");
		}
		else if(a1!=b1&&a2!=b2&&tmp1==tmp2){
			if(b1==b2)	puts("tie");
			else if(b1>b2)	puts("first");
			else	puts("second");
		}
		else puts("tie");
	}
}