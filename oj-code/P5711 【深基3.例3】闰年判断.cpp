#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int i,j,k;
	int n,m,t;
	
	cin>>n;
	if(n%400==0)
	{
		cout<<1;
		return 0;
	}
	if(n%100==0)
	{
		cout<<0;
		return 0;
	}
	if(n%4==0)
	{
		cout<<1;
		return 0;
	}
	cout<<0;

	return 0;
}
