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
int main()
{
	long long i,j,k,n,flag=0;
	long long a[101],m=pow(2,31);
	
	a[1]=a[2]=1;
	scanf("%lld",&n);
	if((n==1)||(n==2))
	{
		printf("1=1");
		return 0;
	}
	for(i=3;i<=n;i++)a[i]=(a[i-1]+a[i-2])%m;
	n=a[n];
	printf("%lld=",n);
	for(i=2;;i++)
	{
		if(n%i==0)
		{
			if(flag)printf("*");
			printf("%d",i);
			flag=1;
			n/=i;
			i--;
			if(n==1)return 0;
		}
	}
	
	return 0;
}
