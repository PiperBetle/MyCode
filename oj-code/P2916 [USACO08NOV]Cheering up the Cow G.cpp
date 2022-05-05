#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
struct qw
{
	int u,v,t;
};
qw e[100007];
int a[100007],f[100007];
bool cmp(qw a,qw b)
{
	return a.t<b.t;
}
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k=0,p,q;
	int n,m,t,ans=1e9;
	
	for(i=0;i<100007;i++)f[i]=i;
	cin>>n>>p; 
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		ans=min(t,a[i]);
	}
	for(i=1;i<=p;i++)
	{
		cin>>e[i].u>>e[i].v>>e[i].t;
		e[i].t=e[i].t+e[i].t+a[e[i].u]+a[e[i].v];
	}
	sort(e+1,e+1+p,cmp);
	for(i=1;k<n-1;i++)
	{
		int fx=find(e[i].u),fy=find(e[i].v);
		if(fx!=fy)
		{
			ans+=e[i].t;
			f[fx]=fy;
			k++;
		}
	}
	cout<<ans;
	
	return 0;
}
