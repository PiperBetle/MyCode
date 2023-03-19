#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	long long n,m,a[100001],i;

	cin>>n;
	a[0]=0;
	a[1]=a[2]=1;
	for(i=3;i<=n;i++)a[i]=a[i-1]+a[i-2];
	cout<<a[n]<<".00";
	
	return 0;
}
