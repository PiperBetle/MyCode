#include<iostream>
#include<cstdio>
using namespace std;
bool a[10001][10001];
int main()
{
	int i,j,k,l,m,n,t,x,y,ans=0;
	
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		a[x][y]=1;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(a[i][j]&&a[j][i]&&(i!=j))
			{
				a[i][j]=a[j][i]=0;
				ans++;
			}
		}
	}
	cout<<ans;
	
	return 0;
}
