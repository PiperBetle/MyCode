#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int a[101][101],i,j,k,l,t,n,m,ans=0,sum;
	
	cin>>n;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if((i!=j)&&(a[i][j]==1))ans++;
		}
	}
	if(ans<=(n*10))cout<<"Yes";
	else cout<<"No";
	
	return 0;
}
