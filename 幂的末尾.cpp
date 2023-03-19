#include<iostream>
using namespace std;
int main()
{
	int ans,i,a,b;
	
	cin>>a>>b;
	ans=1;
	for(i=1;i<=b;i++)
	{
		ans=(ans*a)%1000;
	}
	if(ans<10)cout<<"00";
	else if(ans<100)cout<<"0";
	cout<<ans;
	
	return 0;
}
