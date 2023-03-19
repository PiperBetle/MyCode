#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int a[1001]={0},i,t,n,m;
	
	cin>>m>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&t);
		a[t]++;
	}
	for(i=1;i<=m;i++)
	{
		while(a[i]--)
		{
			printf("%d ",i);
		}
	}
	
	return 0;
}
