#include<iostream>
using namespace std;

int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
bool visited[100000001];
char a[101][101];

bool isin(int x,int y,int n,int m)
{
	if(0<=x&&x<n&&0<=y&&y<m)
		return 1;
		return 0;
}

bool dfs(int x,int y,int n,int m)//yÒýÓÃ 
{
	if(a[x][y]=='T')
	{
		return 1;
	} 
	int xx,yy;
	for(int i=0;i<4;i++)
	{
		xx=x+dir[i][0];
		yy=y+dir[i][1];
		if(!isin(xx,yy,n,m))continue;
		if(a[xx][yy]='.')
		{
			a[xx][yy]='*';
			if(dfs(xx,yy,n,m))return 1;
			a[xx][yy]='.';
		}
		else if(a[xx][yy]=='T')return 1;
	}
		
	return 0;
}

int main()
{
	int i,j,x;
	int n,m;
	int tx,ty,sx,sy
	
	cin>>n>>m;
//	if(dfs(10,x))
//	{
//		cout<<x<<endl;
//		cout<<"OK"<<endl;
//	}
//	else cout<<"not find"<<endl;
	for(i=1;i<=n;i++)
	{
		cin>>map[i];
		for(j=1;j<=m;j++)
		{
			if(a[i][j]=='S')
			{
				sx=i;
				sy=j;
			}
			else if(a[i][j]=='T')
			{
				tx=i;
				ty=j;
			}
		}
	}
		
	
	return 0;
} 
