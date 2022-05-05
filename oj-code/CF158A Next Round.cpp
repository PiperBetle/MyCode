#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
using namespace std;
int a[1001];
int main()
{
	int i,j,k;
	int n,T;
	int ans=0,len;
	
	cin>>n>>k;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=1;i<=k;i++)
	{
		if(a[i]>0)ans++;
		else
		{
			cout<<ans;
			return 0;
		}
	}
	for(i=k+1;i<=n;i++)
	{
		if(a[i]==a[k])ans++;
		else
		{
			cout<<ans;
			return 0;
		}
	}
	cout<<ans;
	
	return 0;
}
