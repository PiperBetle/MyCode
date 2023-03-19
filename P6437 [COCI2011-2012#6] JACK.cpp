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
	int a[101],i,j,k,n,m,minn;
	
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)scanf("%d",a+i);
	for(i=1;i<=n-2;i++)
	{
		for(j=i+1;j<=n-1;j++)
		{
			for(k=j+1;k<=n;k++)
			{
				a[0]=a[i]+a[j]+a[k];
				if((a[0]<=m)&&(a[0]>minn))minn=a[0];
			}
		}
	}
	printf("%d",minn);
	
    return 0;
}
