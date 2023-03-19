#include<iostream>
using namespace std;

bool jiaru(int a[],int n,int len)
{
	for(int i=1;i<=len;i++)
	{
		if(a[i]==n)return 0;
	}
	return 1;
}

int main()
{
	int i,j,t;
	int n,m;
	int a[101];
	
	cin>>n;
	m=0;
	for(i=1;i<=n;i++)
	{
		cin>>t;
		if(jiaru(a,t,m))
		{
			a[m]=t; 
			m++;
		} 
	}
	for(i=1;i<=n-1;i++)
	{
		for(j=1;j<=n-i;j++) 
		{
			if (a[j]>a[j+1]) 
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		} 
	}
	cout<<m<<endl;
	for(i=1;i<=m;i++)
	{
		a[i]=a[i+1];
	}
	for(i=1;i<=m;i++)
	{
		cout<<a[i]<<" ";
	}
	
	
	return 0;
} 
