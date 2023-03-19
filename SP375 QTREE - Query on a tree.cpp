//不向焦虑与抑郁投降，这个世界终会有我们存在的地方。
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<tuple>
#include<ctime>
#include<random>
#include<vector>
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
std::mt19937 rng(std::random_device{}());
constexpr venti operator""_vt(uloli x){return venti(x);}
constexpr bool ying=false,yang=true;
constexpr int N=10000+1;
int n,cnt,fa[N],top[N],dfn[N],gs[N],sz[N],dep[N],val[N],rnk[N],s[N<<2];
pii e[N];
std::vector<pii>g[N];
void dfs1(int u){
	// for(auto[v,w]:g[u]){
	for(pii i:g[u]){
		int v=i.fi,w=i.se;
		if(v==fa[u])continue;
		fa[v]=u,dep[v]=dep[u]+1,sz[v]=1,val[v]=w;
		dfs1(v);sz[u]+=sz[v];
		if(sz[v]>sz[gs[u]])gs[u]=v;
	}
}
void dfs2(int u,int t){
	top[u]=t;dfn[u]=++cnt;rnk[cnt]=u;if(!gs[u])return;else dfs2(gs[u],t);
	// for(int v:g[u]|vw::keys)if(v!=fa[u]&&v!=gs[u])dfs2(v,v);
	for(pii i:g[u]){
		int v=i.se;
		if(v!=fa[u]&&v!=gs[u])dfs2(v,v);
	}
}
#define ls (u<<1)
#define rs (u<<1|1)
#define mid ((l+r)>>1)
void build(int u,int l,int r){
	if(l==r)return s[u]=val[rnk[l]],void();
	build(ls,l,mid);build(rs,mid+1,r);
	s[u]=max(s[ls],s[rs]);
}
void updata(int u,int l,int r,int x,int k){
	if(l==r)return s[u]=k,void();
	x<=mid?updata(ls,l,mid,x,k):updata(rs,mid+1,r,x,k);
	s[u]=max(s[ls],s[rs]);
}
int query(int u,int l,int r,int x,int y){
	if(x<=l&&r<=y)return s[u];
	int res=0;
	if(x<=mid)cmax(res,query(ls,l,mid,x,y));
	if(y>mid)cmax(res,query(rs,mid+1,r,x,y));
	return res;	
}
#undef ls
#undef rs
#undef mid
int t_quary(int x,int y){
	if(x==y)return 0;
	int res=0;
	for(;top[x]!=top[y];x=fa[top[x]]){
		if(dep[top[x]]<dep[top[y]])std::swap(x,y);
		cmax(res,query(1,1,n,dfn[top[x]],dfn[x]));
	}
	if(dep[x]>dep[y])std::swap(x,y);
	return cmax(res,query(1,1,n,dfn[x]+1,dfn[y])),res;
}
bsc str;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>n;cnt=0;
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1,u,v,w;i<n;i++)cin>>u>>v>>w,g[u].emplace_back(v,w),g[v].emplace_back(u,w),e[i]={u,v};
		dfs1(1);dfs2(1,1);build(1,1,n);
		for(int x,y;cin>>str;)switch(str.front()){
		case 'C':cin>>x>>y;updata(1,1,n,max(dfn[e[x].fi],dfn[e[x].se]),y);break;
		case 'Q':cin>>x>>y;cout<<t_quary(x,y)<<'\n';break;
		case 'D':goto next;break;
		}
		next:;
	}
	return 0;
}