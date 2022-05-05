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
	
	for(i=100;i<=999;i++)
	{
		a=i/100;
		b=i%10;
		if(a==b)if(su(i))cout<<i<<endl;
	}
	
	return 0;
}
