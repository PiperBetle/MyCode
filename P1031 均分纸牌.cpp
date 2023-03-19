#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
using namespace std;
int main()
{
	int n,a[10001],i,j,k,t,m,sum=0,ans=0;
	
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	sum/=n;
	for(i=1;i<=n-1;i++)
	{
		a[i+1]=a[i+1]+a[i]-sum;
		if(a[i]!=sum)ans++;
		a[i]=sum;
	}
	cout<<ans;
	
	return 0;
}
