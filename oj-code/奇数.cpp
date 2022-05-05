#include<iostream>
using namespace std;
int main()
{
	int i,j,k=1,t;
	int a[501],n;
	
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>t;
		if(t%2==1)
		{
			a[k]=t;
			k++;
		}
	}
	n=k;
	for(i=1;i<=n-1;i++)
		for(j=1;j<=n-i;j++) 
			if (a[j]>a[j+1]) 
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
	cout<<a[1];
	for(i=2;i<=n;i++)cout<<' '<<a[i];
	
	return 0;
} 
