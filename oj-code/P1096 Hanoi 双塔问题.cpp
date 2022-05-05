#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	
	int a[1001]={0},n,i,j,len;
	
	cin>>n;
	a[1]=2;
	len=1;
	for(i=2;i<=n;i++)
	{
		for(j=1;j<=len;j++)
		{
			a[j]=a[j]+a[j];
		}
		a[1]+=2;
		for(j=1;j<=len;j++)
		{
			a[j+1]=a[j+1]+a[j]/10;
			a[j]%=10;
		}
		if(a[len+1]>=1)len++;
	}
	for(i=len;i>=1;i--)cout<<a[i];

	return 0;
}
