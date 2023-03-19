#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
using namespace std;
int a[107],dis[107][107];
int main()
{
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,left,right,ans=2e9,sum=0;
	
	for(i=0;i<107;i++)for(j=0;j<107;j++)dis[i][j]=1e5;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		dis[i][i]=0;
		cin>>a[i]>>left>>right;
		if(left)dis[i][left]=dis[left][i]=1;
		if(right)dis[i][right]=dis[right][i]=1;
	}
	for(k=1;k<=n;k++)for(i=1;i<=n;i++)for(j=1;j<=n;j++)
		dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for(i=1;i<=n;i++)
	{
		sum=0;
		for(j=1;j<=n;j++)
			sum+=dis[i][j]*a[j];
		ans=min(ans,sum);
	}
	cout<<ans;
	
	return 0;
}
