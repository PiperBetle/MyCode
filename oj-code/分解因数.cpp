#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
using namespace std;
int chai(int a,int sm)
{
	if(a==1)return 1;
	int k=0;
	for(int i=sm;i<=a;i++)
	{
		if(a%i==0)
		{
			k=k+chai(a/i,i);
		}
	}
	return k;
}
int main()
{
	int i,j,n,t;
	
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<chai(n,2)<<endl;
	}
	
	return 0;
}
