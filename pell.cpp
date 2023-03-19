#include<iostream>
using namespace std;
int a[1000000];
int main()
{
	int i,j;
	
	int t,n;
	
	a[2]=2;
	a[1]=1;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=2;i<=n;i++)a[i]=(2*a[i-1]+a[i-2])%32767;
		cout<<a[n]<<endl;
	} 

	
	return 0;
} 
