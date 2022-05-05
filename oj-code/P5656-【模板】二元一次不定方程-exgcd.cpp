#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
inline int read()
{
	int f=1,w=0;char c;
	for(;!isdigit(c);c=getchar())if(c=='-')f=-f;
	for(;isdigit(c);c=getchar()) w=(w<<1)+(w<<3)+(c^48);
	return w*f;
}
inline void exgcd(int a,int b,int &x,int &y)
{
	if(!b)x=1,y=0;
	else exgcd(b,a%b,y,x),y-=x*(a/b);
}
inline int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,T=read();
	int a,b,c,x,y;
	int xmin,xmax,ymin,ymax;
	
	while(T--)
	{
		a=read(),b=read(),c=read();
		int gcdab=gcd(a,b);
		if(c%gcdab)
		{
			puts("-1");
			continue;
		}
		a/=gcdab;b/=gcdab;c/=gcdab;
		exgcd(a,b,x,y);
		x*=c;y*=c;
		x=(x%b+b)%b;
		if(x==0)
			x=b;
		y=(c-a*x)/b;
		if(y>0)
		{
			xmin=x;ymax=y;
			y=(y%a+a)%a;
			if(y==0)
				y=a;
			x=(c-b*y)/a;
			xmax=x;ymin=y;
			printf("%lld %lld %lld %lld %lld\n",(xmax-xmin)/b+1,xmin,ymin,xmax,ymax);
		}
		else
			printf("%lld %lld\n",x,y%a+a);
	}
	
	return 0;
}