#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int dx[4]={1,2,-1,-2},
	dy[4]={2,1,2,1};
int n,m,sum=0;
void dfs(int x,int y)
{
	int i,nx,ny;
	for(i=0;i<4;i++)
	{
		nx=x+dx[i];
		ny=y+dy[i];
//		cout<<nx<<" "<<ny<<" "<<n<<" "<<m<<endl;
		if((nx>=0)&&(ny>=0)&&(nx<=n)&&(ny<=m))
		{
			if((nx==n)&&(ny==m))
				sum++;
			else dfs(nx,ny);
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	dfs(0,0);
	printf("%d",sum);
	
	return 0;
}
