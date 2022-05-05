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
char a[21][21];
int minn,n,m,x1,y1;
int dx[4]={0,0,1,-1},
	dy[4]={1,-1,0,0};
void dfs(int x,int y,int foot)
{
	int i,j,k,nx,ny;
	for(i=0;i<4;i++)
	{
		nx=x+dx[i];
		ny=y+dy[i];
		if((a[nx][ny]!='#')&&(nx>=1)&&(ny>=1)&&(nx<=n)&&(ny<=m))
		{
			if(a[nx][ny]=='*')
			{
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
	
	for(;;)
	{
		cin>>n>>m;
		if((n==0)&&(m==0))break;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				cin>>c;
				minn=999999;
				if(c=='@')
				{
					x1=i;
					y1=j;
					a[i][j]='.';
				}
				else
				{
					a[i][j]=c;
				}
			}
		}
		dfs(x1,y1,1);
		cout<<((minn==999999)?-1:minn)<<endl;
	}

	return 0;
}
