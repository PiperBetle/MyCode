#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define MAXN 1000007
using namespace std;
struct kru
{
	long long u,v;
	double t;
}a[MAXN];
long long f[MAXN];
long long n=0,m=0,T=0,t=0,l=0,sum=0,i,j,k,_1,_2;
double ans=0;
long long cmp(kru x,kru y)
{
	return x.t<y.t;
}
long long find(long long x)
{
    if(f[x]==x)return x;
    else return f[x]=find(f[x]);
}
int main()
{
    long long x[MAXN],y[MAXN];
	for(i=0;i<MAXN;i++)f[i]=i;
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)scanf("%lld%lld",&x[i],&y[i]);
	for(i=1;i<=n-1;i++)
	    for(j=i+1;j<=n;j++)
	    {
	        l++;
			a[l].u=i;
			a[l].v=j;
			a[l].t=(double)(sqrt(((double)(x[i]-x[j]))*((double)(x[i]-x[j]))+((double)(y[i]-y[j]))*((double)(y[i]-y[j]))));
	    }
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld",&_1,&_2);
		l++;
		a[l].u=_1;
		a[l].v=_2;
		a[l].t=0.0;
	}
	sort(a+1,a+1+l,cmp);
	for(i=1;i<=l;i++)
	{
		long long _x=find(a[i].u);
		long long _y=find(a[i].v);
		if(_x==_y)continue;
		sum++;
		ans+=a[i].t;
		f[_x]=_y;
		if(sum==n-1)break;
	}
	printf("%.2lf",ans);
	
	return 0;
}
