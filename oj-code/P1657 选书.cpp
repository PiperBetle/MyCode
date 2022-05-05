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
int a[21],b[21],x[21],y[21],n,sum=0;
void dfs(int now)
{
	if(now==n+1)
	{
		sum++;
		return;
	}
	if(b[x[now]]==0)
	{
		b[x[now]]=1;
		dfs(now+1);
		b[x[now]]=0;
	}
	if(b[y[now]]==0)
	{
		b[y[now]]=1;
		dfs(now+1);
		b[y[now]]=0;
	}
}
int main()
{
	int i;
	
	scanf("%d",&n);
	if(n==0)
	{
		printf("0");
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",x+i,y+i);
	}
	dfs(1);
	cout<<sum;
	
    return 0;
}
