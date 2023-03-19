#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int a[101][101],i,j,k,n,m,t,flag;
	
	memset(a,0,sizeof(a));
	cin>>n>>m;
	for(k=1;k<=m;k++)
	{
		cin>>i>>j>>t;
		a[i][j]=t;
	}
	for(i=1;i<=n;i++)
	{
		cout<<i<<':';
		for(j=1;j<=n;j++)
		{
			if(a[i][j]!=0)
			{
				cout<<endl<<j<<' '<<a[i][j];
			}
		}
		cout<<endl;
	}
	
	return 0;
}
