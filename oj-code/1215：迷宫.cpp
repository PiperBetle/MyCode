#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int n,x1,x2,y1,y2,nx,ny,m,flag;
char a[1001][1001]={0};
void dfs(int x,int y)
{
	int i,j,k;
	for(i=0;i<4;i++)
	{
		nx=x+dx[i];
		ny=y+dy[i];
		if((nx>=0)&&(ny>=0)&&(nx<n)&&(ny<n)&&(a[nx][ny]=='.'))
		{
			a[nx][ny]='#';
			if((nx==x2)&&(ny==y2))
			{
				cout<<"YES"<<endl;
				flag=1;
				break;
			}
			else
			{
				dfs(nx,ny);
			}
		}
	}
	return;
}
int main()
{
	int i,j,k;
	cin>>m;

	for(i=1;i<=m;i++)
	{
		cin>>n;
		for(j=0;j<=n-1;j++)
		{
			scanf("%s",a[j]);
		}
		cin>>x1>>y1>>x2>>y2;
		if((a[x1][y1]=='#')||(a[x2][y2]=='#'))
		{
			cout<<"NO"<<endl;
			continue;
		}
		else
		{
			flag=0;
			dfs(x1,y1);
		}
		if(flag==0)cout<<"NO"<<endl;
	}

	return 0;
}

