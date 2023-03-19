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
int a[101];
int n,k,ans=0;
bool prime(int n)
{
	if(n<2)return 0;
	int i;
	for(i=2;i*i<=n;i++)
		if(n%i==0)return 0;
	return 1;
}
void dfs(int sum,int num,int begin)
{
	if(num>k)return;
	if(num==k)
	{
		if(prime(sum))ans++;
//		cout<<sum<<endl;
		return;
	}
	int i;
	for(i=begin;i<=n;i++)
	{
		dfs(sum+a[i],num+1,i+1);
//		dfs(sum,num,i+1);
	}
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i;
	
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
	{
		scanf("%d",a+i);
	}
	dfs(0,0,1);
	printf("%d",ans);
	
	return 0;
}
