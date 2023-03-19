#include<iostream>
using namespace std;

int dir[8][2]={{-1,-2},{-2,-1},{-1,2},{-2,1},{1,-2},{2,-1},{1,2},{2,1}};
bool visited[100000001];
char a[101][101];

bool isin(int x,int y,int n)
{
	if(0<=x&&x<n&&0<=y&&y<n)
		return 1;
		return 0;
}

bool dfs(int x,int y,int n,int m,int num)//yÒýÓÃ 
{
	int xx,yy;
	if(m==num)return 1; 
	for(int i=0;i<4;i++)
	{
		xx=x+dir[i][0];
		yy=y+dir[i][1];
		if(!isin(xx,yy,n))continue;
		if(a[xx][yy]='.')
		{
			a[xx][yy]='a'+m;
			if(dfs(xx,yy,n,m+1,num))return 1;
			a[xx][yy]='.';
		}
	}
		
	return 0;
}

int main()
{
	int i,j;
	int n,m;
	int tx,ty,sx,sy,num;
	
	cin>>n;
//	if(dfs(10,x))
//	{
//		cout<<x<<endl;
//		cout<<"OK"<<endl;
//	}
//	else cout<<"not find"<<endl;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		for(j=1;j<=m;j++)
		{
			if(a[i][j]=='S')
			{
				sx=i;
				sy=j;
			}
			else if(a[i][j]=='.')
			{
				num++;
			}
		}
	}
	if(dfs(sx,sy,n,0,num))
	{
		for(i=0;i<n;i++)
		{
			cout<<a[i];
		}
	}
		
	
	return 0;
} 
