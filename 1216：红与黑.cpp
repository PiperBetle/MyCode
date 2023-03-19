#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int n,x1,x2,y1,y2,nx,ny,m,flag,sum;
char a[1001][1001]={0};
void dfs(int x,int y)
{
	int i,j,k;
	for(i=0;i<4;i++)
	{
		nx=x+dx[i];
		ny=y+dy[i];
		if((nx>=1)&&(ny>=1)&&(nx<=n)&&(ny<=m)&&(a[nx][ny]=='.'))
		{
			a[nx][ny]='#';
			sum++;
			dfs(nx,ny);
//			a[nx][ny]='.';
		}
//		nx=x;
//		ny=y;
	}
	return;
}
int main()
{
	int i,j,k,t,x,y;

	for(;;)
	{
		sum=1;
		cin>>n>>m;
		if((n==0)&&(m==0))break;
		for(j=1;j<=n;j++)
		{
			for(k=1;k<=m;k++)
			{
				cin>>a[j][k];
				if(a[j][k]=='@')
				{
					x=j;
					y=k;
					a[j][k]='#';
				}
			}
		}
		dfs(x,y);
		cout<<sum<<endl;
	}

	return 0;
}

