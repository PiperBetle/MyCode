#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
int f[100007],a[100007];
int b[100007],vis[100007];
int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T;
	int u,v;
	
	for(i=0;i<100007;i++)
		f[i]=i;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<=m;i++)
	{
		cin>>u>>v;
		int fx=find(u),fy=find(v);
		if(fx!=fy)
		{
			f[fx]=fy;

		}
		else
		{
			puts("Impossible");
			return 0;
		}
	}
	
	return 0;
}