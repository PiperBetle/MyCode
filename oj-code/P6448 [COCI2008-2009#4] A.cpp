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
	int a[6],flag,i,j,k;
	
	for(i=1;i<=5;i++)scanf("%d",a+i);
	for(;;)
	{
		flag=0;
		for(i=1;i<=4;i++)
			if(a[i]!=i)flag=1;
		if(flag==0)return 0;
		for(i=1;i<=4;i++)
			if(a[i]>a[i+1])
			{
				swap(a[i],a[i+1]);
				printf("%d",a[1]);
				for(j=2;j<=5;j++)printf(" %d",a[j]);
				puts("");
			}
	}
	
    return 0;
}
