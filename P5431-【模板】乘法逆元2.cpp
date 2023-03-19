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
int a[5000007],sum[5000007];//后缀积
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
	int n=read(),m,t=1;
	int p=read(),x,y,ans=0;
	
	k=read();
	for(i=1;i<=n;i++)
		a[i]=read();
	sum[n+1]=1;
	for(i=n;i>=1;i--)
		sum[i]=sum[i+1]*a[i]%p;
	exgcd(sum[1],p,x,y);
	x=(x%p+p)%p;
	for(i=1;i<=n;i++)
	{
		t=t*k%p;
		ans=(ans+x*sum[i+1]%p*t%p)%p;
		x=x*a[i]%p;
	}
	printf("%lld\n",ans);
	
	return 0;
}