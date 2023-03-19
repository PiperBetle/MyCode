#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<ctime>
#include<cmath>
using namespace std;
int a[20001];
bool isprime(int n)
{
	if(a[n]==1)return 1;
	if(a[n]==-1)return 0;
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			a[n]=-1;
			return 0;
		}
	}
	a[n]=1;
	return 1;
}
int main()
{
	int i,j,k,n,m;
	
	scanf("%d",&n);
	if(isprime(n-4)==1)
	{
		printf("2 2 %d",n-4);
		return 0;
	}
	for(i=3;;i+=2)
	{
		for(j=i;;j+=2)
		{
			k=n-i-j;
			if((isprime(i)==1)&&(isprime(j)==1)&&(isprime(k)==1))
			{
				printf("%d %d %d",i,j,k);
				return 0;
			}
		}
	}
	
	return 0;
}
