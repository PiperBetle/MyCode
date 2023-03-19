#include<iostream>
#include<iomanip>
#include<string>
#include<cstdio>
using namespace std;
bool prime(int n)
{
	if(n<=1)return 0;
	int i;
	for(i=2;i*i<=n;i++)
	{
		if(n%i==0)return 0;
	}
	return 1;
}
int main()
{
	int t,n,flag=0;
	
	cin>>t;
	while(t--)
	{
		scanf("%d",&n);
		if(prime(n))
		{
			if(flag==1)
				cout<<' ';
			else
				flag=1;
			cout<<n;
		}
	}

	return 0;
}
