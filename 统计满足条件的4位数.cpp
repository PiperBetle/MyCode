#include<iostream>
using namespace std;
int main()
{
	int i,j,n,a,b,c,d,t,ans;
	
	cin>>t;
	ans=0;
	for(i=1;i<=t;i++)
	{
		cin>>n;
		d=n%10;
		c=(n%100)/10;
		b=(n%1000)/100;
		a=n/1000;
		if((d-a-b-c)>0)ans++;
	}
	cout<<ans;
	
	return 0;
} 
