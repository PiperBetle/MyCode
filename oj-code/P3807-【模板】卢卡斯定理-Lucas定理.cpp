#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
int fac[100007],inv[100007];
inline int qp(int n,int p,int k)
{
	int t=1;
	if(p==0)return 1;
	for(;p;p>>=1,n=n*n%k)
		if(p&1)
			t=t*n%k;
	return t;
}
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
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T;
	int t,p;

	cin>>T;
	while(T--)
	{
		cin>>n>>m>>p;
		fac[1]=inv[1]=fac[0]=inv[0]=1;
		for(i=2;i<=100000;i++)
		{
			t=i;
			while(t%p==0)
				t/=p;
			fac[i]=fac[i-1]*t%p;
		}
		inv[100000]=qp(fac[100000],p-2,p);
		for(i=99999;i>=2;i--)
		{
			t=i+1;
			while(t%p==0)
				t/=p;
			inv[i]=inv[i+1]*t%p;
		}
		cout<<lucas(n+m,m,p)<<'\n';
	}
	
	return 0;
}