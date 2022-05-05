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
	long long a[10086],i,n;
	
	a[1]=2;
	a[2]=3;
	cin>>n;
	for(i=3;i<=n;i++)a[i]=a[i-1]+a[i-2];
	cout<<a[n];
	
	return 0;
}
