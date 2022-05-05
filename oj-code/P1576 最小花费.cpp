#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<iomanip>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
long double a[2007][2007],dis[2007];
int f[2007];
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	
	int i,j,k;
	int u,v,n,m;
	double t;
	
	scanf("%d%d",&n,&m);
//	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%lf",&u,&v,&t);
//		cin>>u>>v>>t;
		a[u][v]=(100.00000000-t)/100.00000000;
		a[v][u]=a[u][v];
	}
	scanf("%d%d",&u,&v);
	for(i=1;i<=n;i++)dis[i]=a[u][i];
	dis[u]=f[u]=1;
	for(i=1;i<=n-1;i++)
	{
		double minn=0.00000000;
		for(j=1;j<=n;j++)
			if((!f[j])&&(dis[j]>minn))
			{
				k=j;
				minn=dis[j];
			}
		f[k]=1;
		if(k==v)break;
		for(j=1;j<=n;j++)
			if(!f[j])dis[j]=max(dis[j],dis[k]*a[k][j]);
	}
	printf("%0.8lf",(double)((double)(100.00000000)/(double)(dis[v])));
//	cout<<fixed<<setprecision(8)<<100.00000000/dis[v];
	
	return 0;
}
