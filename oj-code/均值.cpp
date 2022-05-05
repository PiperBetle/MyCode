#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	double t,ans=0;
	int i,n;
	
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>t;
		ans+=t;
	}
	cout<<fixed<<setprecision(4)<<ans/(double)n;
	
	return 0;
} 
