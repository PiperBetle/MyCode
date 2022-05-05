#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int a[5007];
int main()
{
	int i,j,k;
	int n=0,m,t,s;
	
	cin>>j>>s;
	cin>>t>>m;
	m+=t;
	for(i=1;i<=j;i++)
	{
		cin>>t;
		if(t>m)cin>>t;
		else
		{
			n++;
			cin>>a[n];
		}
	}
	sort(a+1,a+1+n);
//	for(i=1;i<=n;i++)cout<<a[i]<<' ';
	for(i=1;i<=n;i++)
	{
		s-=a[i];
		if(s<0)
		{
			cout<<i-1;
			return 0;
		}
	}
	cout<<n;
	
	return 0;
}
