#include<iostream>
#include<cstring>
#include<cstdio>
int a[1000001];
void pell(int n)
{
	a[n]=(2*a[n-1]+a[n-2])%32767;
}
using namespace std;
int main()
{
	int i,j,n,t;
	
	cin>>n;
	a[1]=1;
	a[2]=2;
	for(i=1;i<=n;i++)
	{
		cin>>t;
		for(j=3;j<=t;j++)
		{
			pell(j);
		}
		cout<<a[t]<<endl;
	}
	
	return 0;
}
