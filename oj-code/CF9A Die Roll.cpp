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
	
	cin>>n>>m;
	int pd=(6-max(n,m));
	if(pd==2)cout<<"1/6";
	if(pd==3)cout<<"1/3";
	if(pd==4)cout<<"1/2";
	if(pd==5)cout<<"2/3";
	if(pd==6)cout<<"5/6";
	if(pd==7)cout<<"1/1";
	
	return 0;
}
