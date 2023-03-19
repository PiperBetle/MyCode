#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#define int long long
using std::cin;using std::cout;
int f[200007];
struct edge{int u,v,t;bool operator<(const edge&n){return t<n.t;}}a[200007];
inline int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
inline bool merge(int x,int y){int fx=find(x),fy=find(y);if(fx!=fy)f[fx]=fy;return fx!=fy;}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k,n,m,ans=0;
	cin>>n>>m;
	for(i=1;i<=n;i++)f[i]=i;
	for(i=1;i<=m;i++)cin>>a[i].u>>a[i].v>>a[i].t;
	std::sort(a+1,a+1+m);
	for(i=1;i<=m;i=j+1)
	{
		for(j=i;a[i].t==a[j+1].t;j++);
		for(k=i;k<=j;k++)if(find(a[k].u)!=find(a[k].v))ans++;
		for(k=i;k<=j;k++)if(merge(a[k].u,a[k].v))ans--;
	}
	cout<<ans;
	return 0;
}