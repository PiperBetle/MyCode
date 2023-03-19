//不向焦虑与抑郁投降，这个世界终会有我们存在的地方。
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<ctime>
#include<vector>
#include<tuple>
#if __cplusplus>=202002L
#include<ranges>
namespace vw=std::views;
#endif
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) std::begin(x),std::end(x)
#define rall(x) std::rbegin(x),std::rend(x)
#define sqrt __builtin_sqrt
#define fi first
#define se second
#define continue(x) {x;continue;}
#define break(x) {x;break;}
using std::cin;using std::cout;
using std::max;using std::min;
using std::tie;using std::ignore;
template<typename any>inline void cmin(any &x,const any &y){if(y<x)x=y;}
template<typename any>inline void cmax(any &x,const any &y){if(x<y)x=y;}
template<typename any,typename...args>inline void cmax(any &x,const any &y,const args &...z){cmax(x,y);cmax(x,z...);}
template<typename any,typename...args>inline void cmin(any &x,const any &y,const args &...z){cmin(x,y);cmin(x,z...);}
using loli=long long;
using uloli=unsigned long long;
using lodb=long double;
using venti=__int128_t;
using pii=std::pair<int,int>;
using tiii=std::tuple<int,int,int>;
using inlsi=const std::initializer_list<int>&;
using bsi=std::basic_string<int>;
using bsc=std::string;
using std::operator""s;
#if __cplusplus>=201703L
using bscv=std::string_view;
using std::operator""sv;
#endif
struct _time{~_time(){std::cerr<<"\n\033[33;40m"<<1.*clock()/CLOCKS_PER_SEC<<"s\033[37;40m";}}_TM;
constexpr venti operator""_vt(uloli x){return venti(x);}
constexpr bool ying=false,yang=true;
constexpr int N=2e5+11;
int n,fa[N],dep[N],gs[N],top[N],sz[N],dfn[N],cnt;
loli ans;
std::vector<tiii>g[N];
void dfs1(int u){
	for(int v:g[u]|vw::elements<0>){
		if(v==fa[u])continue;
		fa[v]=u,dep[v]=dep[u]+1,sz[v]=1;
		dfs1(v);sz[u]+=sz[v];
		if(sz[v]>sz[gs[u]])gs[u]=v;
	}
}
void dfs2(int u,int t){
	top[u]=t;dfn[u]=++cnt;if(!gs[u])return;else dfs2(gs[u],t);
	for(int v:g[u]|vw::elements<0>)if(v!=fa[u]&&v!=gs[u])dfs2(v,v);
}
int LCA(int x,int y){
	for(;top[x]!=top[y];x=fa[top[x]])
		if(dep[top[x]]<dep[top[y]])std::swap(x,y);
	return dep[x]<dep[y]?x:y;
}
struct{
	int d[N];
private:
	void upd(int x,int k){for(;x<=n;x+=x&-x)d[x]+=k;}
	int ask(int x){int k=0;for(;x;x-=x&-x)k+=d[x];return k;}
public:
	void upd(int l,int r,int k){upd(l,k);upd(r+1,-k);}
	int operator[](int x){return ask(x);}
}tr;
void upd_tree(int x,int y,int k){
	for(;top[x]!=top[y];x=fa[top[x]]){
		if(dep[top[x]]<dep[top[y]])std::swap(x,y);
		tr.upd(dfn[top[x]],dfn[x],k);
	}
	if(dep[x]>dep[y])std::swap(x,y);
	tr.upd(dfn[x],dfn[y],k);
}
void dfs3(int u){
	for(auto[v,c1,c2]:g[u])if(v!=fa[u]){
		ans+=min(1ll*c1*tr[dfn[v]],1ll*c2);
		dfs3(v);
	}
}
signed main(){
//	freopen("hardware.in","r",stdin);
//	freopen("hardware.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1,u,v,c1,c2;i<n;i++){
		cin>>u>>v>>c1>>c2;
		g[u].emplace_back(v,c1,c2);
		g[v].emplace_back(u,c1,c2);
	}
	dfs1(1);dfs2(1,1);
	for(int i=1;i<n;i++){
		int p=LCA(i,i+1);
		upd_tree(i,p,1);
		upd_tree(i+1,p,1);
		upd_tree(p,p,-2);
	}
	dfs3(1);
	cout<<ans;
	return 0;
}