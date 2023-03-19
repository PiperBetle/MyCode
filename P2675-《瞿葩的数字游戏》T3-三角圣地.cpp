#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
#define MOD 10007
using namespace std;
inline int qp(int n,int p,int k)
{
	int t=1;
	if(p==0)return 1;
	for(;p;p>>=1,n=n*n%k)
		if(p&1)
			t=t*n%k;
	return t;
}
int fac[1000007],inv[1000007],luc[1000007];
int lucas(int n,int m,int p)
{
	if(n<m)
		return 0;
	if(n<p)
		return fac[n]*inv[m]*inv[n-m]%p;
	return lucas(n%p,m%p,p)*lucas(n/p,m/p,p)%p;
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,t;
	int ans=0;
	
	scanf("%lld",&n);
	fac[0]=inv[0]=fac[1]=inv[1]=1;
	for(i=2;i<=1000000;i++)
	{
		t=i;
		while(t%MOD==0)
			t/=MOD;
		fac[i]=fac[i-1]*t%MOD;
	}
	inv[1000000]=qp(fac[1000000],MOD-2,MOD);
	for(i=999999;i>=2;i--)
	{
		t=i+1;
		while(t%MOD==0)
			t/=MOD;
		inv[i]=inv[i+1]*t%MOD;
	}
	for(i=1;i<=n;i++)
	{
		// if(i%2==0)
		if(!(i&1))
		{
			ans+=i*lucas(n-1,n-i/2,MOD)%MOD;
			ans=(ans%MOD+MOD)%MOD;
		}
		else
		{
			ans+=i*lucas(n-1,i/2,MOD)%MOD;
			ans=(ans%MOD+MOD)%MOD;
		}
	}
	printf("%lld\n",ans);
	
	return 0;
}