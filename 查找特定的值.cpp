#include<iostream>
using namespace std;
int a[10001];
int main()
{
	int ans,n,find,i;
	
	ans=-1;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	cin>>find;
	for(i=1;i<=n;i++)
	{
		if(find==a[i])
		{
			ans=i;
			break;
		}
	}
	cout<<ans;
	
	return 0;
}
