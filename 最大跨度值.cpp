#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int i,n,max=0,min=999999999,t;
	
	cin>>n;
	cin>>t;
	max=min=t;
	for(i=2;i<=n;i++)
	{
		cin>>t;
		if(t>max)max=t;
		if(t<min)min=t;
	}
	cout<<max-min;
	
	return 0;
} 
