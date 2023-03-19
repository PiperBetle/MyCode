#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
int f[107][107];//传i次球到j
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,T;

	scanf("%lld%lld",&m,&n);
	f[0][1]=1;
	for(i=1;i<=n;i++)
		for(j=1,f[i-1][0]=f[i-1][m],f[i-1][m+1]=f[i-1][1];j<=m;j++)
			f[i][j]=f[i-1][j-1]+f[i-1][j+1];
	printf("%lld",f[n][1]);
	
	return 0;
}