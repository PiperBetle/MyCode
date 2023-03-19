#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define int __int128
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
inline void exgcd(int a,int b,int &x,int &y)
{
	if(b==0){x=1;y=0;return;}
	exgcd(b,a%b,y,x);
	y-=(a/b)*x;
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,T;
	int ai,bi,ans,M;
	int x,y;
	long long t1,t2,t3;
	
	scanf("%lld%lld%lld",&t1,&t2,&t3);
	n=t1;M=t2;ans=t3;
	for(i=2;i<=n;i++)
	{
		scanf("%lld%lld",&t1,&t2);
		bi=t1;ai=t2;
		int B=((ai-ans)%bi+bi)%bi;
		exgcd(M,bi,x,y);
		int GcD=M*x+bi*y;
		x=x*B/GcD%bi;
		ans+=M*x;
		M*=bi/GcD;
		ans=(ans+M)%M;
	}
	t3=ans;
	printf("%lld\n",t3);
	
	return 0;
}