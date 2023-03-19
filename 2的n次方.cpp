#include<iostream>
using namespace std;
int a[150]; 
int main()
{
	int i,j,n,len;
	
	cin>>n;
	for(i=1;i<=n;i++)a[i]=0;
	a[1]=1;
	for(j=1;j<=n;j++)
	{
		for(i=n;i>=1;i--)
		{
			a[i]*=2;
			a[i+1]=a[i+1]+a[i]/10;
			a[i]%=10;
		}
	}
	
	for(i=n;;i--)
	{
		if(a[i]!=0)
		{
			len=i;
			break;
		}
	}
	for(i=len;i>=1;i--)cout<<a[i];
	
	return 0;
}
