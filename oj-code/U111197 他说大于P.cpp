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
	int a[101],b[101],tt[101],la,lb,lt;
	long long i,j,k,n,m,t,c[101];
	
	c[60]=1;
	for(i=59;i>=1;i--)
	{
		c[i]=2*c[i+1];
	}
	cin>>n;
	lt=0;
	for(i=1;n==0;i++)
	{
		lt++;
		c[i]=n%2;
		n=n/2;
	}
	for(i=60;i>=60-lt;i--)
	{
		a[i]=
	}

	return 0;
}
