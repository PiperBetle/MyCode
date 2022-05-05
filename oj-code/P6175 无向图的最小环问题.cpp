#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int a[207][207],dis[207][207];
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,ans=4e8;
	int u,v,t;
	
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			a[i][j]=dis[i][j]=4e8;
		a[i][i]=dis[i][i]=0;
	}
	for(i=1;i<=m;i++)
	{
		cin>>u>>v>>t;
		a[u][v]=min(a[u][v],t);
		a[v][u]=min(a[v][u],t);
		dis[u][v]=min(dis[u][v],t);
		dis[v][u]=min(dis[v][u],t);
	}
	for(k=1;k<=n;k++)
	{
		for(i=1;i<k;i++)for(j=i+1;j<k;j++)
			ans=min(ans,dis[i][j]+a[i][k]+a[k][j]);
		for(i=1;i<=n;i++)for(j=1;j<=n;j++)
		{
			dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			dis[j][i]=dis[i][j];
		}
	}
	if(ans==4e8)cout<<"No solution.";
	else cout<<ans;
	
	return 0;
}
