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
	long long a[10001],n,v,i,j,f[100001];
	
	cin>>n>>v;
	for(i=1;i<=n;i++)
	{
		scanf("%ld",&a[i]);
	}
	for(i=0;i<100001;i++)f[i]=0;
	f[0]=1;
	for(i=1;i<=v;i++)
	{
		for(j=a[i];j<=n;j++)
		{
			f[j]+=f[j-a[i]];
		}
	}
	cout<<f[n];
	
	return 0;
}
