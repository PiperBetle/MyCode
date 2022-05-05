#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
using namespace std;
int f[100007];
int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
struct road
{
	int u,v,t;
}a[100007];
bool cmp(road x,road y)
{
	return x.t<y.t;
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T;
	int s,t,ans=-1;

	for(i=0;i<100007;i++)
		f[i]=i;
	cin>>n>>m>>s>>t;
	for(i=1;i<=m;i++)
		cin>>a[i].u>>a[i].v>>a[i].t;
	sort(a+1,a+1+m,cmp);
	for(i=1;i<=m;i++)
	{
		int fx=find(a[i].u),fy=find(a[i].v);
		if(f[fx]!=fy)
			f[fx]=fy;
		if(find(s)==find(t))
		{
			cout<<a[i].t;
			return 0;
		}
	}

	return 0;
}