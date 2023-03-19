#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define INF 1061109567
using namespace std;
int f[2007][2007];
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t,ans=1;
	int u,v;
	
	memset(f,0x3f,sizeof f);
	for(i=0;i<2007;i++)f[i][i]=0;
	
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		cin>>u>>v>>t;
		f[u][v]=min(f[u][v],-t);
	}
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(f[i][k]!=INF&&f[k][j]!=INF)
                    f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
    if(f[1][n]==INF)cout<<-1;
    else cout<<-f[1][n];
	
	return 0;
}
