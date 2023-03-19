#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
#include<map>
using namespace std;
int gcd(int x,int y)
{
	int r=x%y;
	while(r)
	{
		x=y;
		y=r;
		r=x%y;
	}
	return y;
}
int main()
{
	int a[11],c[11],b,i,j,k,m,n,t,len,minn=0;
	
	cin>>n;
	for(i=0;i<=10;i++)a[i]=c[i]=0;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=1;i<=n-1;i++)
	{
		for(j=1;j<=n-i;j++)
		{
			if(a[j]>a[j+1])
			{
				swap(a[j],a[j+1]);
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		if(c[i]==0)
		{
			minn++;
			for(j=n;j>=i+1;j--)
			{
				if((gcd(a[i],a[j])==1)&&(c[j]==0))
				{
					a[i]*=a[j];
					c[j]=1;
				}
			}
		}
	}
	cout<<minn;
	
	return 0;
}
