#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int a[101]={0},c[50001]={0};
	int i,j,k,n,m,t=0,x,y,z;
	
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(i=1;i<=n-1;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			for(k=1;k<=n;k++)
			{
				if((a[i]+a[j]==a[k])&&(c[a[i]+a[j]]==0))
				{
					c[a[i]+a[j]]=1;
				}
			}
		}
	}
	for(i=1;i<=50000;i++)t+=c[i];
	cout<<t;
	
	return 0;
}
