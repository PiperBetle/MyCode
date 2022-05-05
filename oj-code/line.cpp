#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int i,j,k,b,c,flag=0,n,m;
	string str;
	int a[1000];
	long long s,ans;
	
	cin>>n>>m;
	cin>>a[i];
	for(i=2;i<=n;i++)
	{
		cin>>a[i];
		a[i-1]=abs(a[i]-a[i-1]);
	}
	s=0;
	for(i=2;i<=m;i++)s+=a[i];
	ans=s;
	for(i=m;i<n;i++)
	{
		s+=a[i]-a[i-m+1];
		ans=min(s,ans);
	}
	cout<<ans;
	
	return 0;
} 
