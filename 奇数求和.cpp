#include<iostream>
using namespace std;
int main()
{
	int a,b,ans;
	
	cin>>a>>b;
	for(int i=a;i<=b;i++)
	{
		if(i%2==1)ans+=i;
	}
	cout<<ans;
	
	return 0;
}
