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
long long a[1001];
int bv(int n)
{
	if(n==1)return 0;
	for(int i=1;;i++)
	{
		if(a[i]>=n)
		{
			return i;
		}
	}
}
int main()
{
	long long x,y,z,t,i;
	
	a[1]=2;
	for(i=2;i<=50;i++)
	{
		a[i]=2*a[i-1];
	}
	
	cin>>t;
	while(t--)
	{
		cin>>x>>y>>z;
		cout<<x*y*z-1<<endl;
		cout<<bv(x)+bv(y)+bv(z)<<endl;
	}

	return 0;
}
