#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
#define abs(a) ((a)<0?-(a):(a))
#define MOD 1000000007
using namespace std;
int a,b,x,y,c,ansx,ansy;
void exgcd(int a,int b,int&x,int&y)
{
	if(!b){x=1,y=0;return;}
	exgcd(b,a%b,y,x);
	y-=a/b*x;
}
void check(int x)
{
	int tx=x;
	x=abs(x);
	int y=abs((c-a*tx)/b);
	if(ansx+ansy>x+y||(ansx+ansy==x+y&&ansx*a+ansy*b>x*a+y*b))
		ansx=x,ansy=y;
	y=abs((-c+a*tx)/b);
	if(ansx+ansy>x+y||(ansx+ansy==x+y&&ansx*a+ansy*b>x*a+y*b))
		ansx=x,ansy=y;
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,T;

	while(cin>>a>>b>>c)
	{
		if(a==0&&b==0&&c==0)
			return 0;
		exgcd(a,b,x,y);
		int g=a*x+b*y;
		if(c%g)
		{
			puts("-1");
			continue;
		}
		a/=g;b/=g;c/=g;
		x*=c;y*=c;
		int t1x=(x%b+b)%b,t2y=(y%a+a)%a;
		int t1y=(c-a*t1x)/b,t2x=(c-b*t2y)/a;
		ansx=abs(t1x);ansy=abs(t1y);
		check(t1x-b);check(t1x);check(t2x);check(t2x+b);
		if(ansx<=0&&ansy<=0)
			puts("-1");
		else
			printf("%lld %lld\n",ansx,ansy);
	}

	return 0;
}