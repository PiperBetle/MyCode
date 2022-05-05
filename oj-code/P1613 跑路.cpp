#include<iostream>
#include<cstring>
#include<cstdio>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
bool b[107][107][107];
int f[107][107];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k,p,q;
	int n,m,t;
	int u,v,x,y;
	
	memset(f,0x3f,sizeof f);
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		cin>>u>>v;
		f[u][v]=b[u][v][0]=1;
	}
	for(p=1;p<=64;p++)
		for(k=1;k<=n;k++)
			for(i=1;i<=n;i++)
				for(j=1;j<=n;j++)
					if(b[i][k][p-1]&&b[k][j][p-1])
						b[i][j][p]=f[i][j]=1;
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				f[i][j]=min(f[i][k]+f[k][j],f[i][j]);
	cout<<f[1][n];
	
    return 0;
}
