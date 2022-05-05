#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	int a[1001],b[1001],n,m=1,i,j,k,t;
	
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	n--;
	for(i=1;i<=n;i++)b[i]=abs(a[i+1]-a[i]);
	for(i=1;i<=n-1;i++)
	{
		for(j=1;j<=n-i;j++)
		{
			if(b[j]>b[j+1])
			{
				swap(b[j],b[j+1]);
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		if(b[i]!=i)
		{
			m=0;
		}
	}
	if(m==1)cout<<"Jolly";
	else cout<<"Not jolly";
	
	return 0;
}
