#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define int long long
using namespace std;
signed main()
{
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T;
	int x1,x2,y1,y2;
	int t1,t2;
	
	cin>>x1>>y1>>x2>>y2;
	cout<<"y=";
	t1=y1-y2;
	t2=x1-x2;
	if(t1*t2<0)
	{
		cout<<"-";
		if(t1<0)t1=-t1;
		if(t2<0)t2=-t2;
	}
	
	return 0;
}
