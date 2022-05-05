#include<iostream>
using namespace std;
int main()
{
	int a,b,i,n,ans=0,j,t;
	
	cin>>n;
	for(i=1;i<=n;i++)
	{
		t=1;
		for(j=1;j<=i;j++)
		{
			t=j*t;
		}
		ans+=t;
	}
	cout<<ans;
	
	return 0;
}
