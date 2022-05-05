#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<ctime>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
#include<map>
#define MAX 100000000
using namespace std;
short a[2*MAX+10];
int main()
{
	int n,m,i;
	
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&m);
		a[m+MAX]++;
	}
	scanf("%d",&m);
	for(i=2*MAX;;i--)
	{
		if(a[i]>0)
		{
			while(a[i]--)
			{
				if(m<=0)return 0;
				printf("%d\n",i-MAX);
				m--;
			}
		}
	}
	
	return 0;
}
