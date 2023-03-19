#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int a[100007];
int main()
{
	int i,j,k;
	int n,m;
	int end,ans=0;
	
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)scanf("%d",a+i);
	sort(a+1,a+1+n);
	for(i=1;i<=n;i++)
	{
		if(a[i]>=0)break;
		m--;
		if(m<0)break;
		ans-=a[i];
	}
	cout<<ans;
	
	return 0;
}
