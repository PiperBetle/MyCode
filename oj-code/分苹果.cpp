#include<iostream>
using namespace std;
int main()
{
	int n,i,ans=0;
	
	cin>>n;
	for(i=1;i<=n;i++)
	{
		ans+=i;
	}
	cout<<ans;
	
	return 0;
}
