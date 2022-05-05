#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
#include<map>
using namespace std;
int main()
{
	int a[1001]={0},i,j,k,n;
	
	cin>>n;
	if(n==1)cout<<1;
	else
	{
		for(i=1;;i++)
		{
			a[i]=n;
			if(n%2==0)n/=2;
			else n=3*n+1;
			if(n==1)
			{
	   			i++;
				a[i]=1;
				j=i;
				break;
			}
		}
		for(;j>=1;j--)printf("%d ",a[j]);
	}

	return 0;
}
