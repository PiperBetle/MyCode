#include<iostream>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
int f[307][307];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k,n,u,v,t;
	cin>>n;
	for(i=1;i<=n;i++)for(j=1;j<=n;j++)cin>>f[i][j];
	cin>>k;
	while(k--)
	{
		cin>>u>>v>>t;
		if(f[u][v]<=t)goto calc;
		f[u][v]=f[v][u]=t;
		for(i=1;i<=n;i++)for(j=1;j<=n;j++)
			f[j][i]=f[i][j]=std::min({f[i][j],f[i][u]+f[u][j],f[i][v]+f[v][j]});
		calc:long long ans=0;
		for(i=1;i<n;i++)for(j=i+1;j<=n;j++)ans+=f[i][j];
		cout<<ans<<' ';
	}
	return 0;
}