#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define abs(a) ((a)>0?(a):(-a))
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
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,T;
	int a,b,c,x,y;
	int x1,x2,y1,y2;
	
	for(;;)
	{
		a=read(),b=read(),c=read();
		//ax+by=c
		if(a==0&&b==0&&c==0)
			return 0;
		exgcd(a,b,x,y);
		int gcdab=a*x+b*y;
		if(c%gcdab)
		{
			puts("-1");
			continue;
		}
		a/=gcdab;b/=gcdab;c/=gcdab;
		x1=(x*c%b+b)%b;
		y1=abs((c-a*x1)/b);
		y2=(y*c%a+a)%a;
		x2=abs((c-b*y2)/a);
		if(x1*a+y1*b<x2*a+y2*b)
			printf("%lld %lld\n",x1,y1);
		else 
			printf("%lld %lld\n",x2,y2);
	}
	
	return 0;
}