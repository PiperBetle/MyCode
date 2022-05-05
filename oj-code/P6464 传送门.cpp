#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
#define MAXN 5007
using namespace std;
int g[107][107],f[107][107];
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k,l,sum;
	int n,m,start;
	int u,v,t;
	
	cin>>n>>m;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(i==j)f[i][j]=0;
			else f[i][j]=1e9;
	for(i=1;i<=m;i++)
	{
		cin>>u>>v>>t;
		f[u][v]=f[v][u]=t;
	}
	for (k=1;k<=n;k++)
		for (i=1;i<=n;i++)
			for (j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	int ans=1e9;
	for(k=1;k<=n;k++)
		for(l=k+1;l<=n;l++)
		{
			for(i=1;i<=n;i++)
				for (j=1;j<=n;j++)
					g[i][j]=f[i][j];
			g[k][l]=g[l][k]=0;
			for (i=1;i<=n;i++)
				for (j=1;j<=n;j++)
					g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			for(i=1;i<=n;i++)
				for(j=1;j<=n;j++)
					g[i][j]=min(g[i][j],g[i][l]+g[l][j]);
			sum=0;
			for(i=1;i<=n;i++)
				for(j=i+1;j<=n;j++)
					sum+=g[i][j];
			ans=min(ans,sum);
		}
	cout<<ans;
	
	return 0;
}
