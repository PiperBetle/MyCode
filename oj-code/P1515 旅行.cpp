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
{
	int a[10001]={0,0,990,1010,1970,2030,2940,3060,3930,4060,4970,5030,5990,6010,7000};
	int n,i,j,k,m,t,ans[10001]={1},minm,maxm;
	
	scanf("%d%d%d",&minm,&maxm,&n);
	n+=14;
	for(i=15;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
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
//	for(i=1;i<=n;i++)cout<<a[i]<<" ";
	for(i=1;i<=n;i++)
	{
		for(j=i-1;j>=0;j--)
		{
			if(((a[i]-a[j])>=minm)&&((a[i]-a[j])<=maxm))
			{
				ans[i]+=ans[j];
			}
		}
	}
	cout<<ans[n];
	
	return 0;
}
