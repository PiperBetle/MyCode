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
#include<list>
using namespace std;
int main()
{
	int i,j,k;
	int n,m,t,max1=-1,max2=-1,maxp1,maxp2;
	
	scanf("%d",&n);
	for(i=1;i<=(1<<(n-1));i++)
	{
		scanf("%d",&t);
		if(t>max1)
		{
			max1=t;
			maxp1=i;
		}
	}
	for(i=(1<<(n-1))+1;i<=(1<<n);i++)
	{
		scanf("%d",&t);
		if(t>max2)
		{
			max2=t;
			maxp2=i;
		}
	}
	if(max1>max2)printf("%d",maxp2);
	else printf("%d",maxp1);
	
	return 0;
}
