#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int exgcd(int a,int b,int &x,int &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return a;
	}
	int t=exgcd(b,a%b,y,x);
	y-=(a/b)*x;
	return t;
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;
	int p,x,y;
	
	cin>>n>>p;
	for(i=1;i<=n;i++)
	{
		exgcd(i,p,x,y);
		cout<<((x%p)+p)%p<<endl;
	}
	
	return 0;
}

