#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<ctime>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
#include<map>
using namespace std;
char a[51][51];
int minn=9999999,n,m,x1,y1;
int dx[4]={0,0,1,-1},
	dy[4]={1,-1,0,0};
void dfs(int x,int y,int foot)
{
	int i,nx,ny;
	for(i=0;i<4;i++)
	{
		nx=x+dx[i];
		ny=y+dy[i];
		if((nx>=1)&&(ny>=1)&&(nx<=n)&&(ny<=m)&&(a[nx][ny]=='.'))
		{
			if((nx==n)&&(ny==m))
			{
				foot++;
				minn=min(minn,foot);
				return;
			}
			else
			{
				a[nx][ny]='#';
				dfs(nx,ny,foot+1);
				a[nx][ny]='.';
			}
		}
	}
}
int main()
{
	int i,j,k;
	char c;
	
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
	}
	dfs(1,1,1);
	cout<<minn;

	return 0;
}
