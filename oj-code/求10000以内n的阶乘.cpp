#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<ctime>
#include<cmath>
using namespace std;
int main()
{
	int n,i,j,x,m,len=1,a[100001];
	
	cin>>n;
	a[1]=1;
	for(i=1;i<=n;i++)
	{
		x=0;
		for(j=1;j<=len;j++)
		{
			a[j]=a[j]*i+x;
			x=a[j]/10;
			a[j]=a[j]%10;
			if(x>0&&j>=len)len++; 
		}
	}
	for(i=len;i>=1;i--)cout<<a[i];
	
	return 0;
}
