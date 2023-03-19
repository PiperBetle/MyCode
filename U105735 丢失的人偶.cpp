#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
#define tt 1024*1024
using namespace std;
bool a[tt+1];
int main()
{
	int i,j,k,t;
	
	cin>>k;
	t=pow(2,k);
	for(i=1;i<=tt;i++)a[i]=0;
	for(i=1;i<=t-1;i++)
	{
		cin>>j;
		a[j]=1;
	}
	for(i=1;i<=t;i++)
	{
		if(a[i]==0)
		{
			cout<<i;
			break;
		}
	}
	
	return 0;
}
