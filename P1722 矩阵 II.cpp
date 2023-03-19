#include<iostream>
#include<cstdio>
#define MOD 100
using namespace std;
int main()
{
	int a[10001],n;
	int i,j,k;

	scanf("%d",&n);
	a[0]=1;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<i;j++)
		{
			a[i]=(a[i]+a[j]*a[i-1-j])%MOD;
		}
	}
	printf("%d",a[n]);

	return 0;
}
