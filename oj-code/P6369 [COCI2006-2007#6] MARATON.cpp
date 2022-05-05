#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	char a[101][101];
	int	n,i,j,flag=0;
	
	cin>>n;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
		getchar();
	}
	for(i=2;i<=n-1;i++)
	{
		for(j=2;j<=n-1;j++)
		{
			if((a[i-1][j-1]==a[i][j])&&(a[i][j]==a[i+1][j+1])&&(a[i][j]!='.'))
			{
				flag=1;
				cout<<a[i][j];
				return 0;
			}
			if((a[i-1][j+1]==a[i][j])&&(a[i][j]==a[i+1][j-1])&&(a[i][j]!='.'))
			{
				flag=1;
				cout<<a[i][j];
				return 0;
			}
			if((a[i][j-1]==a[i][j])&&(a[i][j]==a[i][j+1])&&(a[i][j]!='.'))
			{
				flag=1;
				cout<<a[i][j];
				return 0;
			}
			if((a[i-1][j]==a[i][j])&&(a[i][j]==a[i+1][j])&&(a[i][j]!='.'))
			{
				flag=1;
				cout<<a[i][j];
				return 0;
			}
			if((a[i-1][j-1]==a[i-1][j])&&(a[i-1][j]==a[i-1][j+1])&&(a[i-1][j-1]!='.'))
			{
				flag=1;
				cout<<a[i-1][j-1];
				return 0;
			}
			if((a[i+1][j-1]==a[i+1][j])&&(a[i+1][j]==a[i+1][j+1])&&(a[i+1][j+1]!='.'))
			{
				flag=1;
				cout<<a[i+1][j+1];
				return 0;
			}
			if((a[i-1][j-1]==a[i][j-1])&&(a[i][j-1]==a[i+1][j-1])&&(a[i-1][j-1]!='.'))
			{
				flag=1;
				cout<<a[i-1][j-1];
				return 0;
			}
			if((a[i-1][j+1]==a[i][j+1])&&(a[i][j+1]==a[i+1][j+1])&&(a[i+1][j+1]!='.'))
			{
				flag=1;
				cout<<a[i+1][j+1];
				return 0;
			}
		}
	}
	if(flag==0)cout<<"ongoing";
	
	return 0;
}
