#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
	int a=0,b=0,x;
	cin>>x;
	
	if(x%2==0)a=1;
	if((4<x)&&(x<=12))b=1;
	if((a+b)==2)cout<<1;
	else cout<<0;
	if((a+b)>=1)cout<<" 1";
	else cout<<" 0";
	if((a+b)==1)cout<<" 1";
	else cout<<" 0";
	if((a+b)==0)cout<<" 1";
	else cout<<" 0";
	
	return 0;
}
