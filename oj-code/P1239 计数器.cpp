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
	int n,m,i,j,k,a[11]={0};
	
	scanf("%d%d",&n,&m);
	for(i=n;i<=m;i++)
	{
		j=i;
		while(j)
		{
			a[j%10]++;
			j/=10;
		}
	}
	printf("%d",a[2]);
	
	return 0;
}
