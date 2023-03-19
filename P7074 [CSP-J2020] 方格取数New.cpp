#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define int long long
using namespace std;
int a[1007][1007],f[1007][1007][2];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;
	
	cin>>n>>m;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			cin>>a[i][j];
	memset(f,-0x3f,sizeof f);
	f[1][1][0]=a[1][1];
	for(i=1;i<=m;i++)
	{
		for(j=(i==1?2:1);j<=n;j++)
			f[j][i][0]=max(f[j][i-1][0],max(f[j][i-1][1],f[j-1][i][0]))+a[j][i];
		for(j=n;j>=1;j--)
			f[j][i][1]=max(f[j][i-1][0],max(f[j][i-1][1],f[j+1][i][1]))+a[j][i];
	}
	cout<<f[n][m][0];
	
	return 0;
}
