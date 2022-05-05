#include<iostream>
using namespace std;
int main()
{
	int i,j,k;
	int a[101];
	float b[101],t;
	int temp;
	int m,n;
	
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i]; 
	}
	for(i=1;i<=n-1;i++)
	{
		for(j=1;j<=n-i;j++) 
		{
			if (a[j]>a[j+1]) 
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				t=b[j];
				b[j]=b[j+1];
				b[j+1]=t;
			}
		} 
	}
//	cout<<m<<endl;
	for(i=1;i<=m;i++)
	{
		a[i]=a[i+1];
		b[i]=b[i+1];
	}	
	cout<<a[m]<<" "<<b[m]<<endl;
	
	return 0;
} 
