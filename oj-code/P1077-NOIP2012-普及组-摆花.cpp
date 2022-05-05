#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
int a[1007],f[1007][1007];
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T;
	
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>a[i];
	f[0][0]=1;
	for(i=1;i<=n;i++)
		for(j=0;j<=m;j++)
			for(k=0;k<=j&&k<=a[i];k++)
				f[i][j]=(f[i][j]+f[i-1][j-k])%1000007;
	cout<<f[n][m]<<'\n';
	
	return 0;
}