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
int dx[8]={0,0,-1,1,-1,-1,1,1},
	dy[8]={-1,1,0,0,-1,1,-1,1};
int a[105][105];
int n,m;
void dfs(int x,int y)
{
	int i,j,k,nx,ny;
	a[x][y]=0;
	for(i=0;i<8;i++)
	{
		nx=x+dx[i];
		ny=y+dy[i];
		if((a[nx][ny]!=0)&&(nx>0)&&(ny>0)&&(nx<=n)&&(ny<=m))
		{
			dfs(nx,ny);
		}
	}
}
int main()
{
	int i,j,k,ans=0;
	char c;

	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			cin>>c;
			if(c=='W')a[i][j]=1;
			else a[i][j]=0;
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(a[i][j]!=0)
			{
				dfs(i,j);
				ans++;
			}
		}
	}
	cout<<ans;

	return 0;
}
