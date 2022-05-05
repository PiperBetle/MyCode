#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<ctime>
//#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
#include<map>
using namespace std;
int n,m,a[6][6];
int dx[4]={1,-1,0,0},
	dy[4]={0,0,1,-1};
int x1,x2,y1,y2,sum=0;
void dfs(int x,int y)
{
	int i,nx,ny;
	for(i=0;i<4;i++)
	{
		nx=x+dx[i];
		ny=y+dy[i];
		if((nx>=1)&&(ny>=1)&&(nx<=n)&&(ny<=m)&&(a[nx][ny]==0))
		{
			a[nx][ny]=1;
			if((nx==x2)&&(ny==y2))sum++;
			else dfs(nx,ny);
			a[nx][ny]=0;
		}
	}
}
int main()
{
	int i,j,k,t,tt;
	
	scanf("%d%d%d",&n,&m,&i);
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	while(i--)
	{
		scanf("%d%d",&t,&tt);
		a[t][tt]=1;
	}
	a[x1][y1]=1;
	dfs(x1,y1);
	printf("%d",sum);
	
    return 0;
}
