#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	
	int a[1001],i,n,j,k=0,x,la,ans[1001];
	for(i=1;i<=1000;i++)ans[i]=0;
	cin>>n;

	for(x=1;x<=n;x++)
	{
		for(i=1;i<=1000;i++)a[i]=0;
		k=0;a[1]=1;
		for(i=2;i<=x;i++)
		{
			for(j=1;j<=1000;j++)
			{
				a[j]=a[j]*i+k;
				k=a[j]/10;
				a[j]=a[j]%10;
			}
		}
		for(k=1;k<=1000;k++)
		{
			ans[k]+=a[k];
		}
	}

	k=0;
	for(j=1;j<=1000;j++)
	{
		ans[j]=ans[j]+k;
		k=ans[j]/10;
		ans[j]=ans[j]%10;
	}

	for(i=1000;;i--)
		if(ans[i]!=0)
		{
			la=i;
			break;
		}
	for(i=la;i>=1;i--)cout<<ans[i];

	return 0;
}
