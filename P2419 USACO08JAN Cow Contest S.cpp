#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
int f[107][107];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,ans=0;
	int u,v,t;
	
	cin>>n>>m;
	for(i=1;i<=n;i++)f[i][i]=1;
	for(i=1;i<=m;i++)cin>>u>>v,f[u][v]=1;
	for(k=1;k<=n;k++)for(i=1;i<=n;i++)for(j=1;j<=n;j++)f[i][j]|=f[i][k]&&f[k][j];
	for(i=1;i<=n;i++)
	{
		int t=1;
		for(j=1;j<=n;j++)t&=f[i][j]|f[j][i];
		ans+=t;
	}
	cout<<ans;
	
	return 0;
}