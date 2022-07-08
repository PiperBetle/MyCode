#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=1e5+1;
std::basic_string<int>g[kN];
int n,q,fa[kN],dep[kN],sz[kN],gs[kN],top[kN];
void dfs1(int u){
	for(int v:g[u])if(v!=fa[u]){
		dep[v]=dep[u]+1,sz[v]=1,fa[v]=u;
		dfs1(v);sz[u]+=sz[v];
		if(sz[v]>sz[gs[u]])gs[u]=v;
	}
}
void dfs2(int u,int t){
	top[u]=t;if(!gs[u])return;else dfs2(gs[u],t);
	for(int v:g[u])if(v!=fa[u]&&v!=gs[u])dfs2(v,v);
}
int LCA(int x,int y){
	for(;top[x]!=top[y];x=fa[top[x]])if(dep[top[x]]<dep[top[y]])std::swap(x,y);
	return dep[x]<dep[y]?x:y;
}
int dis(int u,int v){return dep[u]+dep[v]-2*dep[LCA(u,v)];}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1,u,v;i<n;i++)cin>>u>>v,g[u]+=v,g[v]+=u;
	dep[1]=sz[1]=1;dfs1(1);dfs2(1,1);
	cin>>q;for(int x,y,a,b,k;q--;){
		cin>>x>>y>>a>>b>>k;
		int d1=dis(a,b),d2=dis(a,x)+1+dis(y,b),d3=dis(a,y)+1+dis(x,b);
		auto check=[&](int d){return d<=k&&d%2==k%2;};
		cout<<(check(d1)||check(d2)||check(d3)?"YES\n":"NO\n");
	}
	return 0;
}