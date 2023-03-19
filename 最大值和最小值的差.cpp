#include<iostream>
using namespace std;
int main()
{
	int max,min,t,i,n;
	
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
