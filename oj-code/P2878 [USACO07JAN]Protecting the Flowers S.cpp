#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct cow
{
	long long t,d;
}a[1000001];
long long sum[1000001];
int cmp(cow x,cow y)
{
    return x.t*y.d<x.d*y.t;
}
int main()
{
	long long i,j,k;
	long long n,m,ans=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&a[i].t,&a[i].d);
//		a[i].t<<=1;
	}
	sort(a+1,a+1+n,cmp);
	for(i=1;i<=n;i++)sum[i]=sum[i-1]+a[i].d;
	for(i=1;i<=n;i++)
	{
		
		ans+=a[i].t*(sum[n]-sum[i]);
	}
	ans<<=1;
	cout<<ans;
	
	return 0;
}
