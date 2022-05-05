#include<iostream>
using namespace std;
int main()
{
	int n,ans=0;
	char c;
	
	cin>>n>>c;
	if(n<=1000)ans=8;
	else 
	{
		ans=8+((n-1000)/500)*4+4;
		if(n%500==0)ans-=4;
	}
	if(c=='y')ans+=5;
	cout<<ans;
	
	return 0;
}
