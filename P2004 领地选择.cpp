#include<iostream>
#include<cstring>
#include<cstdio>
#include<iomanip>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
int a[1007][1007],sum[1007][1007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,ans=-99999999999999999;
	int x,y,c;
	
	cin>>n>>m>>c;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			cin>>a[i][j];
			sum[i][j]=a[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
		}
	for(i=1;i<=n-c+1;i++)
		for(j=1;j<=m-c+1;j++)
			if(sum[i+c-1][j+c-1]-sum[i-1][j+c-1]-sum[i+c-1][j-1]+sum[i-1][j-1]>ans)
			{
				ans=sum[i+c-1][j+c-1]-sum[i-1][j+c-1]-sum[i+c-1][j-1]+sum[i-1][j-1];
				x=i;
				y=j;
			}
	cout<<x<<' '<<y;
	
    return 0;
}
