#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
#define MOD 1000000007
using namespace std;
int c[2007][2007],ans[2007][2007];
inline int qp(int n,int p,int k)
{
	if(p==0)return 1;
	int t=1;
	for(;p;p>>=1,n=n*n%k)
		if(p&1)
			t=t*n%k;
	return t;
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,T;
	int ans;
	
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld%lld",&n,&m);
		ans=0;
		while(m--)
		{
			scanf("%lld%lld%lld",&k,&k,&k);
			ans|=k;
		}
		ans=ans*qp(2,n-1,MOD)%MOD;
		printf("%lld\n",ans);
	}
	
	return 0;
}