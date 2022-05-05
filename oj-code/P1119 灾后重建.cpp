#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define int long long
using std::cin;using std::cout;
int c[207],f[207][207],n,m,now=0;
inline void upd(int k){for(int i=0;i<n;i++)for(int j=0;j<n;j++)f[i][j]=std::min(f[i][j],f[i][k]+f[k][j]);}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int u,v,t;
	
	memset(f,0x3f,sizeof f);
	for(i=0;i<207;i++)f[i][i]=0;
	cin>>n>>m;
	for(i=0;i<n;i++)cin>>c[i];
	for(i=1;i<=m;i++)cin>>u>>v>>t,f[u][v]=f[v][u]=t;
	cin>>m;while(m--)
	{
		cin>>u>>v>>t;
		while(now<n&&c[now]<=t)upd(now++);
		if(c[u]>t||c[v]>t||f[u][v]==0x3f3f3f3f3f3f3f3f)cout<<"-1\n";
		else cout<<f[u][v]<<'\n';
	}
	
	return 0;
}