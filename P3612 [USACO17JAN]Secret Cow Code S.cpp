#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
using namespace std;
int main()
{
	string s;
	long long i,j,k;
	long long n,m,t,len;
	
	cin>>s>>n;
	len=s.length();
	while(len<n)
	{
		i=len;
		while(n>i)i<<=1;
		i>>=1;
		n-=i+1; 
		if(n==0)n=i;
	}
	cout<<s[n-1];
	
	return 0;
}
