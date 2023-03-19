#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
int c[2007][2007],ans[2007][2007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,T;
	
	scanf("%lld%lld",&T,&k);
	c[0][0]=1;
	c[1][0]=c[1][1]=1;
	for(i=1;i<=2000;i++)
	{
		c[i][0]=1;
		for(j=1;j<=i;j++)
		{
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%k;
			if(c[i][j]==0)
				ans[i][j]=1;
			ans[i][j]=ans[i][j]+ans[i-1][j]+ans[i][j-1]-ans[i-1][j-1];
		}
		ans[i][i+1]=ans[i][i];
	}
	while(T--)
	{
		scanf("%lld%lld",&n,&m);
		if(m>n)
			m=n;
		printf("%lld\n",ans[n][m]);
	}
	
	return 0;
}