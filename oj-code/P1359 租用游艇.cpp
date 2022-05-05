#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
using namespace std;
int a[1007][1007],dis[1007][1007];
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T;
	int x,y,t;
	
	cin>>n;
	for(i=0;i<1007;i++)for(j=0;j<1007;j++)a[i][j]=1e9;
	for(i=1;i<=n;i++)for(j=i;j<=n;j++)
		if(i==j)a[i][j]=0;
		else cin>>a[i][j];
	for(k=1;k<=n;k++)for(i=1;i<=n;i++)for(j=1;j<=n;j++)
		a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
	cout<<a[1][n];
	
	return 0;
}
