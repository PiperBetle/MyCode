#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#include<queue>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
struct qw
{
	int u,v,t;
	friend bool operator<(const qw a,const qw b)
	{   
		return a.t<b.t;
	}
};
qw a[100007];
int f[307];
int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k=0;
	int n,m,maxn=-2e9;
	
	cin>>n>>m;
	for(i=1;i<=m;i++)
		cin>>a[i].u>>a[i].v>>a[i].t;
	for(i=0;i<307;i++)f[i]=i;
	sort(a+1,a+1+m);
	for(i=1;i<=m;i++)
	{
		int fx=find(a[i].u);
		int fy=find(a[i].v);
		maxn=max(maxn,a[i].t);
		if(fx!=fy)
		{
			f[fx]=fy;
			k++;
		}
		if(k==n-1)break;
	}
	cout<<n-1<<" "<<maxn;
	
	return 0;
}
