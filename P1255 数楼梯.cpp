#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[5001][5001]={0};
int main()
{
	int n,i,j;
	
	cin>>n;
	if(n!=0)
	{
		a[1][1]=1;
		a[2][1]=2;
		a[1][0]=1;
		a[2][0]=1;
		for(i=3;i<=n;i++)
		{
			a[i][0]=a[i-1][0]+1;
			for(j=1;j<=a[i][0];j++)
			{
				a[i][j]=a[i][j]+a[i-1][j]+a[i-2][j];
				a[i][j+1]=a[i][j+1]+a[i][j]/10;
				a[i][j]%=10;
			}
			if(a[i][a[i][0]+1]==0)
			{
				a[i][0]--;
			}
		}
		for(i=5000;i>=1;i--)
		{
			if(a[n][i]!=0)
			{
				j=i;
				break;
			}
		}
		for(;j>=1;j--)cout<<a[n][j];
	}
	else
	{
		cout<<0;
	}
	
	//a[n][a[n][0]]
	return 0;
}
