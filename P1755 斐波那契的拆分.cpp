
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
#include<list>
using namespace std;
int main()
{
	long long i,j,k;
	long long a[101],b[101],len,t,n;
	
	a[0]=0;
	a[1]=1;
	for(i=2;i<=60;i++)a[i]=a[i-1]+a[i-2];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		printf("%lld=",n);
		memset(b,0,sizeof(b));
		len=0;
		for(i=55;i>=1;i--)
		{
			if(n-a[i]>=0)
			{
				n-=a[i];
				len++;
				b[len]=a[i];
				if(n==0)break;
			}
		}
		printf("%lld",b[len]);
		for(i=len-1;i>=1;i--)printf("+%lld",b[i]);
		puts("");
	}
	
	return 0;
}
