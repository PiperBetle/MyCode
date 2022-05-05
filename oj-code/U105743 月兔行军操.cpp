#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
using namespace std;
int main()
{
	long long len,n,i,j,a[100001],ml,sum;
	
	
	cin>>ml;
	while(ml--)
	{
		len=sum=0;
		for(i=0;i<=100000;i++)a[i]=0;
		cin>>n;
		while(n)
		{
			len++;
			a[len]=n%2;
			n/=2;
		}
		for(i=1;i<=len;i++)
		{
			sum=sum+(a[i]==0?0:pow(3,i-1));
		}
		cout<<sum<<endl;
	}
	
	return 0;
}
