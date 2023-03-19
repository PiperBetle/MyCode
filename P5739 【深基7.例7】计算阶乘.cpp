#include<iostream>
#include<iomanip>
#include<string>
#include<cstdio>
using namespace std;
long long qw(long long n)
{
	if(n==1)return 1;
	return n*qw(n-1);
}
int main()
{
	long long n;
	
	cin>>n;
	cout<<qw(n);

	return 0;
}
