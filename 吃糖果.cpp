#include<iostream>
using namespace std;
int main()
{
	int i,j,n;
	int a[21]; 
	
	cin>>n;
	a[1]=1;
	a[2]=2;
	for(i=3;i<=n;i++)
	{
		a[i]=a[i-1]+a[i-2];
	}
	cout<<a[n];
	
	
	return 0;
} 
