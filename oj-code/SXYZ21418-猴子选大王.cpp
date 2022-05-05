#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
int f[10000007];
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	int i,j,k;
	int n,m,T;
	
	scanf("%lld%lld",&n,&m);
	f[1]=1;
	for(i=2;i<=n;i++)
	{
		f[i]=m+f[i-1];
		while(f[i]>i)
			f[i]-=i;
	}
	printf("%lld\n",f[n]);
	
	return 0;
}