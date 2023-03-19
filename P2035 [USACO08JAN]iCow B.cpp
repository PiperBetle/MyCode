#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int a[1001],b[1001],i,j,n,t,sum=0,maxn,maxnp,qw;
	
	for(i=0;i<=1000;i++)a[i]=b[i]=0;
	cin>>n>>t;
	for(i=1;i<=n;i++)cin>>a[i];
	for(;;)
	{
		maxn=-1;
		for(j=1;j<=n;j++)
		{
			if((b[j]==0)&&(a[j]>maxn))
			{
				maxnp=j;
				maxn=a[j];
			}
		}
		cout<<maxnp<<endl;
		sum++;
		if(sum>=t)break;
		for(j=1;j<=n;j++)
		{
			if(j!=maxnp)
			{
				a[j]=a[j]+maxn/(n-1);
			}
		}
		qw=maxn%(n-1);
		j=1;
		while(qw)
		{
			if(j!=maxnp)
			{
				qw--;
				a[j]++;
			}
			j++;
		}
		a[maxnp]=0;
	}
	
	return 0;
}

