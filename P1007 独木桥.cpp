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
	int a[10001],b[10001],l,n,i,j,k,t;
	
	cin>>l>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&t);
		a[i]=min(t,l-t+1);
		b[i]=max(t,l-t+1);
	}
	for(i=1;i<=n-1;i++)
	{
		for(j=1;j<=n-i;j++)
		{
			if(a[j]<a[j+1])
			{
				swap(a[j],a[j+1]);
			}
		}
	}
	for(i=1;i<=n-1;i++)
	{
		for(j=1;j<=n-i;j++)
		{
			if(b[j]<b[j+1])
			{
				swap(b[j],b[j+1]);
			}
		}
	}
	cout<<a[1]<<" "<<b[1];
	
	return 0;
}
