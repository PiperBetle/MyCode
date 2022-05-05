#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#define int long long
#define MOD 1000000007
using std::cin;using std::cout;
struct edge{int u,v,t;bool operator<(const edge&n){return t<n.t;}};
std::vector<edge>a;
int fa[1000007],d[1000007],h[1000007];
inline int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,H;
	int u,v,t;
	
	cin>>n>>m>>H;
	auto f=[&](int x,int y){return (x-1)*m+y;};
	for(i=1;i<=n;i++)for(j=1;j<m;j++)cin>>t,a.emplace_back((edge){f(i,j),f(i,j+1),t});
	for(i=1;i<n;i++)for(j=1;j<=m;j++)cin>>t,a.emplace_back((edge){f(i,j),f(i+1,j),t});
	for(i=1;i<=n;i++)for(j=1;j<=m;j++)t=f(i,j),fa[t]=t,d[t]=1;
	std::sort(a.begin(),a.end());
	for(auto&it:a)
	{
		int fx=find(it.u),fy=find(it.v);
		if(fx!=fy){fa[fy]=fx;d[fx]=(d[fx]-h[fx]+it.t)*(d[fy]-h[fy]+it.t)%MOD;h[fx]=it.t;}
	}
	t=find(1);
	cout<<(d[t]-h[t]+H)%MOD;
	
	return 0;
}