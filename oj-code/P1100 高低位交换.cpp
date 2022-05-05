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
	long long a[1001],n,i,j,k,t,ans;
	
	cin>>n;
	i=n%65536;
	n/=65536;
	cout<<i*65536+n;
	
	return 0;
}
