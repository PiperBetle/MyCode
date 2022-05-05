#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int a[1001],i,j,k,t=0,n;
	
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n-i;j++)
		{
			if(a[j]<a[j+1])
			{
				swap(a[j],a[j+1]);
			}
		}
	}
	for(i=2;i<=n-1;i++)t+=a[i];
	printf("%.2f",(double)((double)t/(double)(n-2)));
	
	return 0;
}
