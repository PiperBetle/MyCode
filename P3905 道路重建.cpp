#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
using namespace std;
int a[107][107],dis[107][107];
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T;
	int x,y,t;
	
	for(i=0;i<107;i++)for(j=0;j<107;j++)a[i][j]=1e9;
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		cin>>x>>y>>t;
		dis[x][y]=dis[y][x]=t;
		a[x][y]=a[y][x]=0;
	}
	cin>>t;
	for(i=1;i<=t;i++)
	{
		cin>>x>>y;
		a[x][y]=a[y][x]=dis[x][y];
	}
	for(k=1;k<=n;k++)for(i=1;i<=n;i++)for(j=1;j<=n;j++)
	{
		a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
	}
	cin>>x>>y;
	cout<<min(a[x][y],a[y][x])<<endl;
	
	return 0;
}
