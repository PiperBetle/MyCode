#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define int long long
using namespace std;
int f1[207][207][27],f2[207][207][27],a[2007],sum[2007];
signed main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k,p;
	int n,m;
	 
	cin>>n>>m;
	for(i=0;i<207;i++)
		for(j=0;j<207;j++)
			for(k=0;k<27;k++)
				f1[i][j][k]=1e8;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i+n]=a[i];
	}
	for(i=1;i<=n*2;i++)
		sum[i]=sum[i-1]+a[i];
	
	for(i=1;i<=n*2;i++)
		for(j=1;j<=n*2;j++)
			f1[i][j][1]=f2[i][j][1]=(sum[j]-sum[i-1]+1000000000000)%10;
			
	for(i=1;i<=n*2;i++)
		for(j=i+1;j<=n*2;j++)
			for(p=2;p<=m;p++)
				for(k=i;k<j;k++)
				{
					f1[i][j][p]=min(f1[i][j][p],f1[i][k][p-1]*f1[k+1][j][1]);
					f2[i][j][p]=max(f2[i][j][p],f2[i][k][p-1]*f2[k+1][j][1]);
				}
					
	int ans_min=1e15;
	int ans_max=-1e15;
	for(i=1;i<=n;i++)
	{
		ans_min=min(ans_min,f1[i][i+n-1][m]);
		ans_max=max(ans_max,f2[i][i+n-1][m]);
	}
	cout<<ans_min<<endl<<ans_max;
	
	return 0;
}
