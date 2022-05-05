#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
using namespace std;
int a[1007];
int main()
{
	int x,y,t,p=1;
	int i,j,k,n;
	
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>t;
		if(t==p)
		{
			p++;
			a[i]=i+2000;
		}
	}
	cout<<p-1<<endl;
	for(i=1;p!=0;i++)
	{
		if(a[i]!=0)
		{
			--p;
			cout<<a[i]<<" ";
		}
	}
	
	return 0;
}
