#include<iostream>
using namespace std;
int su(int n)
{
	int i;
	for(i=2;i*i<=n;i++)
	{
		if(n%i==0)return 0;
	}
	return 1;
}
int main()
{
	int n,i,a,b;
	
	cin>>n;
	a=0;
	for(i=2;i<=n;i++)
	{
		if(su(i))a++;
	}
	cout<<a;
	
	return 0;
}
