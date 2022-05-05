#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<cstring>
#define int __int128
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
#define abs(a) (((a)>0)?(a):-(a))
using namespace std;
int pr[]={0,2,3,5,7,11,13,17,37};
inline int read()
{
	int x=0;char c;
	for(;!isdigit(c);c=getchar());
	for(;isdigit(c);c=getchar())
		x=(x<<1)+(x<<3)+(c^48);
	return x;
}
inline int qp(int n,int p,int k)
{
	int t=1;
	if(p==0)return 1;
	for(;p;p>>=1,n=n*n%k)
		if(p&1)
			t=t*n%k;
	return t;
}
bool miller_rabin(int n)
{
	if(n==1)
		return 0;
	int a,b,i,j,k;
	int x=0,y=n-1;
	while(!(y&1))
		x++,y>>=1;
	for(i=1;i<=8&&pr[i]<n;i++)
	{
		a=pr[i];
		b=qp(a,y,n);
		for(j=1;j<=x;j++)
		{
			k=b*b%n;
			if(k==1&&b!=1&&b!=n-1)
				return 0;
			b=k;
		}
		if(b!=1)
			return 0;
	}
	return 1;
}
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
int pollard_rho(int n)
{
	int i,j,c=rand()%(n-1)+1,L=1,cnt=1,pre=0;
	int x=c%n,y=(x*x+c)%n,g=gcd(abs(x-y),n);
	if(g>1)
		return g;
	while(x!=y)
	{
		for(i=0;i<L;i++)
		{
			x=(x*x+c)%n;
			y=(y*y+c)%n;
			y=(y*y+c)%n;
			pre=cnt*abs(x-y)%n;
			if(x==y||(!pre))
				break;
			cnt=pre;
		}
		g=gcd(cnt,n);
		if(g>1)
			return g;
		if(L<128)
			L<<=1;
	}
	return n;
}
int maxn;
void dfs(int n)
{
	if(n<=maxn||n<2)
		return;
	if(miller_rabin(n))
	{
		maxn=max(maxn,n);
		return;
	}
	int p=n;
	while(p>=n)
		p=pollard_rho(n);
	while(n%p==0)
		n/=p;
	dfs(n);dfs(p);
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,T;
	
	srand(time(NULL));
	T=read();
	while(T--)
	{
		n=read();
		maxn=1;
		dfs(n);
		if(maxn==n)
			puts("Prime");
		else
			printf("%lld\n",maxn);
	}
		
	return 0;
}