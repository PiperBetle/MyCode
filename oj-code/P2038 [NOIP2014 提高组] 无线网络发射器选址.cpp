#include<iostream>
#include<cstring>
#include<cstdio>
#include<iomanip>
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
#define int long long
using namespace std;
int a[1007][1007],sum[1007][1007];
signed main()
{
//	freopen("wireless.in","r",stdin);
//	freopen("wireless.out","w",stdout);
	int i,j,k=0;
	int n,m,t;
	int x,y,ans;
	int maxn=-1,d;
	
	cin>>d>>n;
	for(i=1;i<=n;i++)
	{
		cin>>x>>y>>t;
		a[x+1][y+1]+=t;
	}
	
	sum[1][1]=a[1][1];
	for(i=1;i<=129;i++)
		sum[1][i]=sum[1][i-1]+a[1][i];
	for(i=1;i<=129;i++)
		sum[i][1]=sum[i-1][1]+a[i][1];
	for(i=1;i<=129;i++)
		for(j=1;j<=129;j++)
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
	
	for(i=1;i<=129;i++)
		for(j=1;j<=129;j++)
		{
			int x1=max(1,i-d);
			int y1=max(1,j-d);
			int x2=min(129,i+d);
			int y2=min(129,j+d);
			maxn=max(maxn,sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1]);
		}
	for(i=1;i<=129;i++)
		for(j=1;j<=129;j++)
		{
			int x1=max(1,i-d);
			int y1=max(1,j-d);
			int x2=min(129,i+d);
			int y2=min(129,j+d);
			if(sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1]==maxn)
				k++;
		}
	
	cout<<k<<' '<<maxn;
	
    return 0;
}
