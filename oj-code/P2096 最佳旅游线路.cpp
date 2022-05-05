#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[20007];
int sum[20007];
int main()
{
	int i,j,k;
	int n,m,t,w,ans=2;
	
	scanf("%d%d",&n,&m);
//	m--;
	for(i=1;i<=m;i++)scanf("%d",a+i);
	for(i=2;i<=n;i++)for(j=1;j<=m;j++)
	{
		scanf("%d",&t);
		if(t>a[j])a[j]=t;
	}
	sum[0]=0;
	for(i=1;i<=m;i++)sum[i]=sum[i-1]+a[i];
	for(i=1;i<=m-1;i++)for(j=i+1;j<=m;j++)
		if(sum[j]-sum[i-1]>ans)ans=sum[j]-sum[i-1];
	cout<<ans;
	
	return 0;
}
