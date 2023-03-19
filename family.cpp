#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char a[101][201];
int dx[4]={0,0,-1,1},
	dy[4]={-1,1,0,0};
int len[101],n;
void dfs(int x,int y)
{
	int i,j,k,nx,ny;
	for(i=0;i<4;i++)
	{
		nx=x+dx[i];
		ny=y+dy[i];
		if(('a'<=a[nx][ny])&&(a[nx][ny]<='z')&&(nx>=0)&&(nx<len[ny])&&(ny>=0)&&(ny<n))
		{
			a[nx][ny]='*';
			dfs(nx,ny);
		}
		nx=x;
		ny=y;
	}
	return;
}
int main()
{
	int i,j,k,ans=0;
	
	cin>>n;
	for(i=0;i<=n-1;i++)
	{
		scanf("%s",a[i]);
		len[i]=strlen(a[i]);
		for(j=0;j<len[i];j++)if((a[i][j]==' ')&&(a[i][j]==0)&&(a[i][j]=='~'))a[i][j]='*';
	}
	for(i=0;i<=n-1;i++)
	{
		for(j=0;j<len[i];j++)
		{
			if(('a'<=a[i][j])&&(a[i][j]<='z'))
			{
				dfs(i,j);
				ans++;
			}
		}
	}
	cout<<ans;
	
	return 0;
}
