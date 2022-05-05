#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<ctime>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
using namespace std;
int dx[4]={0,-1,0,1},
	dy[4]={-1,0,1,0};
int x1,x2,y1,y2;
int a[21][21]={0},len=0,n,m;
int ans[101][2]={0},flag=1;
void pr()
{
	int i;
	if(flag==0)cout<<endl;
	else flag=0;
	cout<<"("<<ans[0][0]<<","<<ans[0][1]<<")";
	for(i=1;i<=len;i++)cout<<"->("<<ans[i][0]<<","<<ans[i][1]<<")";
}
void dfs(int x,int y)
{
	int i,nx,ny;
	for(i=0;i<4;i++)
	{
		nx=x+dx[i];
		ny=y+dy[i];
		if((1<=nx)&&(1<=ny)&&(nx<=n)&&(ny<=m)&&(a[nx][ny]==1))
		{
			len++;
			ans[len][0]=nx;
			ans[len][1]=ny;
			a[nx][ny]=0;
			if((nx==x2)&&(ny==y2))
			{
				pr();
			}
			else
			{
				dfs(nx,ny);
			}
			a[nx][ny]=1;
			len--;
		}
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	int i,j,k;
	
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
	}
	cin>>x1>>y1>>x2>>y2;
	ans[0][0]=x1;
	ans[0][1]=y1;
	if(a[x1][y1]==0)
	{
		cout<<-1;
		return 0;
	}
	else a[x1][y1]=0;
	dfs(x1,y1);
	if(flag==1)cout<<-1;
	
    return 0;
}
