#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
int a[1007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,T;

	scanf("%d",&n);
	cout<<(int)(n*log10(2)+1)<<'\n';

	a[0]=1;
	for(i=1;i<=n/10;i++)
	{
		for(j=0;j<=100;j++)
			a[j]<<=10;
		for(j=0;j<=100;j++)
			if(a[j]>100000)
			{
				a[j+1]+=a[j]/100000;
				a[j]%=100000;
			}
	}
	for(i=1;i<=n%10;i++)
	{
		for(j=0;j<=100;j++)
			a[j]<<=1;
		for(j=0;j<=100;j++)
			if(a[j]>100000)
			{
				a[j+1]+=a[j]/100000;
				a[j]%=100000;
			}
	}
	a[0]--;
	for(i=99;i>=0;i--)
	{
		printf("%05d",a[i]);
		if(i%10==0)
			putchar('\n');
	}
	
	return 0;
}