#include<iostream>
using namespace std;
int main()
{
	int i,j=0,n,temp;
	int a[501],b[501];
	
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=1;i<=n;i++)
	{
		if(a[i]%2==1)
		{
			j++;
			b[j]=a[i];
		}
	}
	n=j;
	for(i=1;i<=n-1;i++)
	{
		for(j=1;j<=n-i;j++) 
		{
			if(b[j]>b[j+1]) 
			{
				temp=b[j];
				b[j]=b[j+1];
				b[j+1]=temp;
			}
		} 
	}
	cout<<b[1];
	for(i=2;i<=n;i++)cout<<","<<b[i];
	
	return 0;
} 
