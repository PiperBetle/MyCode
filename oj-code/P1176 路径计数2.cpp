#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
#include<map>
#include<list>
using namespace std;
int a[1001][1001]={0};
int b[1001][1001]={0};
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	int n,m;
	int x,y;
	int i,j,k;
	
	scanf("%d%d",&n,&m);
	while(m--)
	{
		scanf("%d%d",&x,&y);
		b[x][y]=1;
	}
	a[0][1]=1;
//	for(i=1;i<=n;i++)
//	{
//		for(j=1;j<=n;j++)
//		{
//			cout<<b[i][j]<<" ";
//		}
//		puts("");
//	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			a[i][j]=(a[i-1][j]+a[i][j-1])%100003;
			if(b[i][j]==1)a[i][j]=0;
		}
	}
//	for(i=1;i<=n;i++)
//	{
//		for(j=1;j<=n;j++)
//		{
//			cout<<a[i][j]<<" ";
//		}
//		puts("");
//	}
	printf("%d",a[n][n]);
	
	return 0;
}
