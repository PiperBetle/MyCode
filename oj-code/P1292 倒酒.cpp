#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int exgcd(long long a,long long b,long long &x,long long &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return a;
	}
	else
	{
		int t=exgcd(b,a%b,y,x);
		y-=(a/b)*x;
		return t;
	}
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	long long a,b,x,y;
	
	cin>>a>>b;
	k=exgcd(a,b,x,y);
	a=-a;
	x=-x;
	while(x<0||y<0)
	{
		if(x<0)
			x+=b/k;
		else
			y-=a/k;
	}
	cout<<k<<"\n"<<x<<' '<<y;
	
	return 0;
}

