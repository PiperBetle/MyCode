#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<cstdio>
#include<algorithm>
#define int __int128
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
#define MOD 1000003
using namespace std;
int lowbit(int x)
{
	return x&(-x);
}
int qp(int a,int p,int k)
{
	if(p==0)
		return 1;
	int t=1;
	for(;p;p>>=1,t=t*t%k)
		if(p&1)
			t=a*t%k;
	return t;
}
int f(int x)
{
	if(lowbit(x)==x)
		return qp(3,log(x)/log(2),MOD);
	return (f(qp(2,log2(x),MOD))+2*f(x-qp(2,log2(x),MOD))%MOD)%MOD;
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,t;
	
	scanf("%lld",&n);
	printf("%lld\n",((1+n)*n*qp(2,MOD-2,MOD)-f(n))%MOD);
	
	return 0;
}