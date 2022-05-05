#include<iostream>
using namespace std;
long long a[50001];
int main()
{
	long long i,j,k,n,m,t,ans=0,mobi;

	cin>>n>>m;
	for(i=1;i<=m;i++)cin>>a[i];
	mobi=a[1];
	ans=1;
	for(i=2;i<=m;i++)
	{
		if(a[i]==mobi)
		{
			ans++;
		}
		else
		{
			if(ans>=1)
			{
				ans--;
			}
			else
			{
				ans=1;
				mobi=a[i];
			}
		}
	}
	if(ans>=1)cout<<mobi;
	else cout<<-1;
	
	return 0;
}
