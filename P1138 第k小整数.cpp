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
int a[30001]={0};
int main()
{
	int i,j,k,n,m,t;
	
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&t);
		a[t]=1;
	}
	for(i=1;i<=30000;i++)
	{
		if(a[i]>=1)
		{
			k--;
			if(k==0)
			{
				printf("%d",i);
				return 0;
			}
		}
	}
	printf("NO RESULT");
	
    return 0;
}
