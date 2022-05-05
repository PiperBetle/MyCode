#include<iostream>
using namespace std;
int main()
{
	int i,j,n,m,s=0,temp,t,ans,flag=0;

	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>temp;
		s+=temp;
		if(t<=temp&&!flag)
		{
			ans=i;
			flag=1;
		}
	}
	cout<<ans;
	
	return 0;
} 
