#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int a[107][107],f[107][107][107];
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;
	int ans=0;
	
	cin>>n>>m>>k;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			cin>>a[i][j];
	f[1][0][1]=f[0][1][1]=1;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			for(t=0;t<k;t++)
			s	if((f[i-1][j][t])||(f[i][j-1][t]))
					f[i][j][t*a[i][j]%k]=1;
	for(i=0;i<k;i++)
		if(f[n][m][i])
			ans++;
	cout<<ans<<"\n";
	for(i=0;i<k;i++)
		if(f[n][m][i])
			cout<<i<<" ";
	
	return 0;
}
