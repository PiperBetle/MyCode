#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int n,b[9],m,flag,sum;
char a[11][11]={0};
void dfs(int x,int y)
{
	if(y==m)
	{
		sum++;
		return;
	}
	int i,j,k;
	for(i=x;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if((a[i][j]=='#')&&(b[j]==1))
			{
				b[j]=0;
				dfs(i+1,y+1);
				b[j]=1;
			}
		}
	}
	return;
}
int main()
{
	int i,j,k,t,x,y;

	for(;;)
	{
		for(i=0;i<=10;i++)b[i]=1;
		sum=0;
		cin>>n>>m;
		if((n==-1)&&(m==-1))break;
		for(j=1;j<=n;j++)
		{
			for(k=1;k<=n;k++)
			{
				cin>>a[j][k];
			}
		}
		dfs(1,0);
		cout<<sum<<endl;
	}

	return 0;
}

