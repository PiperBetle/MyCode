#include<iostream>
using namespace std;
int main()
{
	int i,j=0,n,temp;
	int a[11],b[11],c[11];
	int lenb,lenc;
	
	n=10;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=1;i<=n;i++)
	{
		if(a[i]%2==1)
		{
			j++;
			b[j]=a[i];
		}
	}
	lenb=j;
	
	j=0;
	for(i=1;i<=n;i++)
	{
		if(a[i]%2==0)
		{
			j++;
			c[j]=a[i];
		}
	}
	lenc=j;
	
	for(i=1;i<=lenb-1;i++)
	{
		for(j=1;j<=lenb-i;j++) 
		{
			if(b[j]>b[j+1]) 
			{
				temp=b[j];
				b[j]=b[j+1];
				b[j+1]=temp;
			}
		} 
	}
	cout<<b[lenb];
	for(i=lenb-1;i>=1;i--)cout<<" "<<b[i];
	
	for(i=1;i<=lenc-1;i++)
	{
		for(j=1;j<=lenc-i;j++) 
		{
			if(c[j]>c[j+1]) 
			{
				temp=c[j];
				c[j]=c[j+1];
				c[j+1]=temp;
			}
		} 
	}
	for(i=1;i<=lenc;i++)cout<<" "<<c[i];
	
	return 0;
} 
