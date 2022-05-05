#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
double a[10001][2];
int cost[10001];
int main()
{
	int n,i;
	
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",cost+i);
	a[1][0]=100;
	a[1][1]=cost[1];
	for(i=2;i<=n;i++)
	{
		a[i][0]=max(a[i-1][0],(a[i-1][1]*100/cost[i]));
		a[i][1]=max(a[i-1][1],(a[i-1][0]*cost[i]/100));
	}
	printf("%.2f",max(a[n][0],a[n][1]*100/cost[n]));
	
	return 0;
}
