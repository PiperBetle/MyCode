#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
void exgcd(int a,int b,int &x,int &y)
{
	if(b==0)
		x=1,y=0;
	else
		exgcd(b,a%b,y,x),y-=a/b*x;
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,T;
	int a,b,c;
	int l,x,y;

	scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&l);
	a=n-m;
	b=l;
	c=x-y;
	if(a<0)
	{
		a=-a;
		c=-c;
	}
	//(n-m)x+ly===(x-y)
	exgcd(a,b,x,y);
	T=a*x+b*y;//gcd(a,b)
	if(c%T)
		cout<<"Impossible\n";
	else
		printf("%lld\n",(c/T*x%(b/T)+b/T)%(b/T));
		// printf("%lld\n",(c/T*y%(a/T)+a/T)%(a/T));
	
	return 0;
}