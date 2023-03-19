#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	long long a[10001],n,i,j;
	const long long MOD=100000007;
	
	a[0]=1;
	a[1]=1;
	cin>>n;
	
	for(i=2;i<=n;i++)
	{
		for(j=0;j<=i-1;j++)
		{
			a[i]=(a[j]*a[i-j-1]%MOD+a[i])%MOD;
		}
	}
	cout<<a[n];

	return 0;
}
