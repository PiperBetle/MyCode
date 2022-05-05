#include<iostream>
#include<cstring>
#include<cstdio>
char a[250][250];
using namespace std;
int main()
{
	int i,j,k,n,t,m,ans=0;
	
	cin>>n;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			cin>>a[i][j];
	cin>>m;
	for(k=1;k<=m-1;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(a[i][j]=='@')
				{
					if(a[i-1][j]=='.')a[i-1][j]='&';
					if(a[i+1][j]=='.')a[i+1][j]='&';
					if(a[i][j-1]=='.')a[i][j-1]='&';
					if(a[i][j+1]=='.')a[i][j+1]='&';
				}
			}
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(a[i][j]=='&')
				{
					a[i][j]='@';
				}
			}
		}
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(a[i][j]=='@')ans++;
	cout<<ans;
	
	return 0;
}
