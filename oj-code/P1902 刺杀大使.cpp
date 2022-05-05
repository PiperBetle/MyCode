#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using std::cin;using std::cout;
int p[1007][1007];
int f[1000007];
struct edge{int u,v,t;bool operator<(const edge&n){return t<n.t;}};
std::vector<edge>e;
inline int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,n,m;
	cin>>n>>m;
	for(i=1;i<=n;i++)for(j=1;j<=m;j++)cin>>p[i][j];
	auto d=[&](int x,int y){return (x-1)*m+y;};
	for(i=d(n,m);i--;)f[i]=i;
	for(i=1;i<=n;i++)for(j=1;j<=m;j++)
	{
		if(i>1)e.emplace_back(edge{d(i,j),d(i-1,j),std::max(p[i][j],p[i-1][j])});
		if(j>1)e.emplace_back(edge{d(i,j),d(i,j-1),std::max(p[i][j],p[i][j-1])});
		if(i<n)e.emplace_back(edge{d(i,j),d(i+1,j),std::max(p[i][j],p[i+1][j])});
		if(j<n)e.emplace_back(edge{d(i,j),d(i,j+1),std::max(p[i][j],p[i][j+1])});
	}
	std::sort(e.begin(),e.end());
	int x=d(1,1),y=d(n,m);
	for(auto it:e)
	{
		int fx=find(it.u),fy=find(it.v);
		if(fx==fy)continue;
		f[fx]=fy;
		if(find(x)==find(y))return cout<<it.t,0;
	}
}