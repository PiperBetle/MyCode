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
using namespace std;
int n,m;
int dx[12]={-2,2,0,0,-1,-1,-1,0,0,1,1,1},
	dy[12]={0,0,-2,2,-1,0,1,-1,1,-1,0,1};
char a[101][101];
void dfs(int x,int y)
{
	int i,nx,ny;
	for(i=0;i<12;i++)
	{
		nx=x+dx[i];
		ny=y+dy[i];
		if((1<=nx)&&(1<=ny)&&(nx<=n)&&(ny<=m)&&(a[nx][ny]=='#'))
		{
			a[nx][ny]='-';
			dfs(nx,ny);
		}
	}
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k,ans=0,ii,jj;
	
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
	}
//	for(i=1;i<=n;i++)
//	{
//		for(j=1;j<=m;j++)
//		{
//			cout<<a[i][j];
//		}
//		puts("");
//	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(a[i][j]=='#')
			{
				ans++;
				a[i][j]='-';
				dfs(i,j);
//				for(ii=1;ii<=n;ii++)
//				{
//					for(jj=1;jj<=m;jj++)
//					{
//						cout<<a[ii][jj];
//					}
//					puts("");
//				}
			}
		}
	}
	printf("%d",ans);
	
	return 0;
}
