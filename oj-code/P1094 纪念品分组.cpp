#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int cmp(int x,int y)
{
	return x>y;
}
int a[100007];
int main()
{
	int i,j,k;
	int n,w;
	int end,ans=0;
	
	scanf("%d%d",&w,&n);
	for(i=1;i<=n;i++)scanf("%d",a+i);
	sort(a+1,a+1+n,cmp);
//	for(i=1;i<=n;i++)cout<<a[i]<<" ";
	end=n;
	for(i=1;i<=n;i++)
	{
		if(end<i)break;
		if(i==end)
		{
			ans++;
			break;
		}
		if(a[i]+a[end]<=w)
		{
			ans++;
			end--;
		}
		else ans++;
	}
	cout<<ans;
	
	return 0;
}
