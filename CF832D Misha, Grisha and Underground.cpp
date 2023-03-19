#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
using std::cin;using std::cout;
using std::max;using std::min;
template<typename any>inline void cmin(any &x,const any &y){if(y<x)x=y;}
template<typename any>inline void cmax(any &x,const any &y){if(x<y)x=y;}
template<typename any,typename...args>inline void cmax(any &x,const any &y,const args &...z){cmax(x,y);cmax(x,z...);}
template<typename any,typename...args>inline void cmin(any &x,const any &y,const args &...z){cmin(x,y);cmin(x,z...);}
using loli=long long;
using uloli=unsigned long long;
using lodb=long double;
using venti=__int128_t;
using pii=std::pair<int,int>;
using inlsi=const std::initializer_list<int>&;
using bsi=std::basic_string<int>;
constexpr venti operator""_vt(uloli x){return venti(x);}
constexpr int N=1e5+1;
std::basic_string<int>g[N];
int n,m,fa[N],sz[N],dep[N],gs[N],top[N];
// void dfs1(int u){
// 	sz[u]=1;dep[u]=dep[fa[u]]+1;
// 	for(int v:g[u])if(v!=fa[u]){
// 		fa[v]=u;dfs1(v);sz[u]+=sz[v];
// 		if(sz[v]>sz[gs[u]])gs[u]=v;
// 	}
// }
// void dfs2(int u,int t){
// 	top[u]=t;if(!gs[u])return;else dfs2(gs[u],t);
// 	for(int v:g[u])if(v!=fa[u]&&v!=gs[u])dfs2(v,v);
// }
void dfs1(int u){
	for(int v:g[u]){
		if(v==fa[u])continue;
		fa[v]=u,dep[v]=dep[u]+1,sz[v]=1;
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
int dis(int x,int y){
	return dep[x]+dep[y]-dep[LCA(x,y)]*2;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int u=2,v;u<=n;u++)cin>>v,g[u]+=v,g[v]+=u;
	dep[1]=1;sz[1]=1;dfs1(1);dfs2(1,1);
	for(int x,y,z,d1,d2,d3;m--;){
		cin>>x>>y>>z;
		d1=dis(x,y),d2=dis(x,z),d3=dis(y,z);
		cout<<max({(d1+d2-d3)/2,(d1+d3-d2)/2,(d2+d3-d1)/2})+1<<'\n';
	}
	return 0;
}