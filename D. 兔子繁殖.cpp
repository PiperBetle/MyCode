#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int a[1000001];
int main()
{
	int n,m,p;
	int i,t;
	
	cin>>n;
	if(n<=3)
	{
		cout<<1;
		return 0;
	}
	a[4]=1;
	a[5]=2;
	for(i=6;i<=n;i++)a[i]=a[i-1]+a[i-2];
	cout<<a[n];
	
	return 0;
}
