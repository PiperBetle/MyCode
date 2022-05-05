#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
long long f[1000007];
long long find(long long x)
{
	return f[x]==x?x:f[x]=find(f[x]);
}
struct road
{
	long long u,v,t;
}a[1000007];
bool cmp(road _x,road _y)
{
	return _x.t<_y.t;
}
int main()
{
//	freopen("kruskal.in","r",stdin);
//	freopen("kruskal.out","w",stdout);
	std::ios::sync_with_stdio(false);
	long long i,j,k=0;
	long long n,m,q,T;
	long long x,y,ans=0;
	
	cin>>n>>m;
	for(i=0;i<1000007;i++)f[i]=i;
	k=0;ans=0;
	for(i=1;i<=m;i++)
		cin>>a[i].u>>a[i].v>>a[i].t;
	sort(a+1,a+1+m,cmp);
	for(i=1;i<=m;i++)
	{
		long long fx=find(a[i].u);
		long long fy=find(a[i].v);
		if(fx!=fy)
		{
			ans+=a[i].t;
			f[fx]=fy;
			k++;
		}
		if(k==n-1)
		{
			cout<<ans;
			break;
		}
	}
	
	return 0;
}
