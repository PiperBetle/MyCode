#include<iostream>
using namespace std;
int main()
{
	int i,j;
	int a[200];
	int t,n,tt,ttt;
	
	a[1]=a[2]=1;
	cin>>t;
	
	while(t--)
	{
		cin>>n;
		for(i=3;i<=n;i++)a[i]=(a[i-1]+a[i-2])%1000;
		cout<<a[n]<<endl;
	} 
	
	return 0;
} 
