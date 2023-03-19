#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
int dis[1007];
int a[1007][1007];
int f[1007][1007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,t;
	
	memset(f,0x3f,sizeof f);
	cin>>n>>m;
	dis[1]=0;
	for(i=2;i<=n;i++)
	{
		cin>>dis[i];
		dis[i]+=dis[i-1];
	}
	for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++)
			a[i][j]=a[i][j-1]+dis[j]-dis[(i+j)>>1];
	for(i=1;i<=n;i++)
		f[i][1]=a[1][i];
	for(i=2;i<=n;i++)
		for(j=2;j<=i&&j<=m;j++)
			for(k=j-1;k<i;k++)
			   f[i][j]=min(f[i][j],f[k][j-1]+a[k+1][i]);
	cout<<f[n][m]<<endl;

	return 0;
}