#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int f[1007][1007],a[1007][1007];
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;
	
	cin>>n>>m;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			cin>>a[i][j];
			a[i][j]+=max(max(a[i-1][j-1],a[i-1][j]),a[i-1][j+1]);
		}
	cout<<max(max(a[n][m/2],a[n][m/2+1]),a[n][m/2+2]);
	
	return 0;
}

