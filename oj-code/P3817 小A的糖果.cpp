#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
long long a[100007];
int main()
{
	long long i,j,k;
	long long n=0,m,sum=0;
	
	cin>>n>>m;
	a[0]=0;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]+a[i-1]>m)
		{
			sum+=a[i]+a[i-1]-m;
			a[i]=m-a[i-1];
		}
	}
	cout<<sum;
	
	return 0;
}
