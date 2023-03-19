#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int a[2007][2007],f[2007][2007][2];
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;
	int ans=-1;
	
	cin>>n>>m;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			cin>>a[i][j];
			if(a[i][j]==0)
				f[i][j][0]=min(f[i-1][j][1],min(f[i][j-1][1],f[i-1][j-1][0]))+1;
			if(a[i][j]==1)
				f[i][j][1]=min(f[i-1][j][0],min(f[i][j-1][0],f[i-1][j-1][1]))+1;
			ans=max(max(f[i][j][0],f[i][j][1]),ans);
		}
	cout<<ans;
	
	return 0;
}
