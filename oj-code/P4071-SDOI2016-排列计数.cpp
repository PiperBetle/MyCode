#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<cstdio>
#include<algorithm>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
#define MOD 1000000007
using namespace std;
int inv[1000007],fac[1000007],d[1000007];
inline int qp(int n,int p,int k)
{
	int t=1;
	if(p==0)
		return 1;
	for(;p;p>>=1,n=n*n%k)
		if(p&1)
			t=t*n%k;
	return t;
}
int lucas(int n,int m,int p)
{
	// if(n<m)
	// 	return 0;
	// if(n<p)
		return fac[n]*inv[m]%p*inv[n-m]%p;
	// return lucas(n%p,m%p,p)*lucas(n/p,m/p,p)%p;
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);w
	int i,j,k;
	int n,m,T;

	d[1]=0;
	fac[0]=fac[1]=inv[0]=inv[1]=d[2]=1;
	for(i=3;i<=1000000;i++)
		d[i]=(i-1)*(d[i-1]+d[i-2])%MOD;
	for(i=2;i<=1000000;i++)
		fac[i]=fac[i-1]*i%MOD;
	inv[1000000]=qp(fac[1000000],MOD-2,MOD);
	for(i=999999;i>=2;i--)
		inv[i]=inv[i+1]*(i+1)%MOD;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld%lld",&n,&m);
		if(n==m)
			puts("1");
		else
			printf("%lld\n",lucas(n,m,MOD)*d[n-m]%MOD);
	}

	return 0;
}