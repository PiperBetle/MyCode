#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
using namespace std;
int main()
{//
	unsigned long long n,a[100][100],i,j;
	
	cin>>n;
	for(i=0;i<100;i++)
	{
		for(j=0;j<100;j++)
		{
			a[i][j]=0;
		}
	}
	for(i=0;i<=99;i++)
	{
		a[i][1]=1;
		a[i][i]=1;
	}
	for(i=1;i<=n+1;i++)
	{
		for(j=1;j<=i+1;j++)
		{
			if(a[i][j]==0)
			{
				a[i][j]=a[i-1][j]+a[i-1][j-1];
			}
		}
	}
	cout<<"(a+b)^"<<n<<"=";
	for(i=n;i>=1;i--)
	{
		if(a[n+1][i+1]!=1)printf("%llu",a[n+1][i+1]);
		if(i!=0)
		{
			putchar('a');
			if(i!=1)printf("^%llu",i);
		}
		if(n-i!=0)
		{
			putchar('b');
			if((n-i)!=1)printf("^%llu",(n-i));
		}
		putchar('+');
	}
	cout<<"b";
	if(n!=1)cout<<"^"<<n;
	
	return 0;
}
