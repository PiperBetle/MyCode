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
	long long a[10001],i,j,k,br;
	
	a[1]=a[2]=1;
	cin>>k;
	for(i=3;;i++)
	{
		a[i]=a[i-1]+a[i-2];
		if(a[i]>k)
		{
			cout<<a[i-1]<<" "<<a[i-2];
			break;
		}
	}

	return 0;
}
