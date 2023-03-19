#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	long long a[10001],n,i;

	a[1]=1;
	cin>>n;

	for(i=2;i<=n;i++)
	{
		a[i]=(4*i-2)*a[i-1]/(i+1);
	}
	cout<<a[n];

	return 0;
}
