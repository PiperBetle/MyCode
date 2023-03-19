#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[17];
void qw(int n)
{
	if(n==0)
	{
		printf("0");
		return;
	}
	if(n==2)
	{
		printf("2");
		return;
	}
	int i,j,k;
	for(;;)
	{
		for(i=16;a[i]>n;i--);
		if(i==1)
		{
			printf("2");
		}
		else
		{
			printf("2(");
			qw(i);
			printf(")");
		}
		if(n==a[i])return;
		else
		{
			printf("+");
			n-=a[i];
		}
	}
}
int main()
{
	int n,i;
	
	scanf("%d",&n);
	a[0]=1;
	for(i=1;i<=16;i++)
	{
		a[i]=a[i-1]+a[i-1];
	}
	qw(n);
	
	return 0;
}
