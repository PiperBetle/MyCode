#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
void exgcd(long long a,long long b,long long &x,long long &y)
{
	if(b==0)
	{
		x=1;
		y=0;
	}
	else
	{
		exgcd(b,a%b,y,x);
		y-=(a/b)*x;
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
	exgcd(a,b,x,y);
	cout<<(x%b+b)%b;
	
	return 0;
}

