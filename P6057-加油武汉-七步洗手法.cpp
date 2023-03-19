#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
int a[1000007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k=0;
	int n,m,T;
	int u,v,ans=0;
	
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		cin>>u>>v;
		a[u]++;
		a[v]++;
	}
	ans=n*(n-1)*(n-2)/6;
	for(i=1;i<=n;i++)
		k+=a[i]*(n-a[i]-1);
	ans-=(k>>1);
	cout<<ans<<'\n';
	
	return 0;
}