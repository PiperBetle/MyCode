#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int f[5000007];
int find(int x)
{
	return f[x]==x?x:f[x]=find(f[x]);
}
struct road
{
	int u,v;
	double t;
}a[5000007];
int x[10007],y[10007];
bool cmp(road a,road b)
{
	return a.t<b.t;
}
int main()
{
//	freopen("meadow.in","r",stdin);
//	freopen("meadow.out","w",stdout);
//	std::ios::sync_with_stdio(false);
	int i,j,k=0;
	int n,m,q,T,sum=0,l=0;
	double ans=0;
	
	scanf("%d%d",&n,&m);
	for(i=0;i<=5000007;i++)f[i]=i;
	for(i=1;i<=n;i++)
		scanf("%d%d",x+i,y+i);
	for(i=1;i<n;i++)
		for(j=i+1;j<=n;j++)
		{
			l++;
			a[l].u=i;
			a[l].v=j;
			a[l].t=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
		}
	sort(a+1,a+1+l,cmp);
	sum=n;
	for(i=1;i<=l;i++)
	{
		if(sum==m)break;
		int fx=find(a[i].u);
		int fy=find(a[i].v);
		if(fx!=fy)
		{
			f[fx]=fy;
			sum--;
			ans=a[i].t;
		}
	}
	printf("%.2f",ans);
	
	return 0;
}
