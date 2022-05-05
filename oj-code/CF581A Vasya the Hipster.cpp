#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
#include<map>
#include<list>
using namespace std;
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;
	
	cin>>y>>w;
	maxs=max(y,w);
	pd=6-maxs;
	if(pd+1==1)cout<<"1/6";
	if(pd+1==2)cout<<"1/3";
	if(pd+1==3)cout<<"1/2";
	if(pd+1==4)cout<<"2/3";
	if(pd+1==5)cout<<"5/6";
	if(pd+1==6)cout<<"1/1";
	
	return 0;
}
