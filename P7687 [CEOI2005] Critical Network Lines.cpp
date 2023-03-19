//不向焦虑与抑郁投降，这个世界终会有我们存在的地方。
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<tuple>
#include<ctime>
#include<random>
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
constexpr int N=1e5+1;
int n,m,c1,c2,a[N],b[N],dc,dfn[N],low[N];
bsi g[N];
std::vector<pii>ans;
void tarjan(int u,int fa){
	dfn[u]=low[u]=++dc;
	for(int v:g[u])if(v!=fa){
		if(!dfn[v]){
			tarjan(v,u);
			cmin(low[u],low[v]);
			if(low[v]>dfn[u]&&(!a[v]||!b[v]||a[v]==c1||b[v]==c2))
				ans.emplace_back(u,v);
			a[u]+=a[v],b[u]+=b[v];
		}else cmin(low[u],dfn[v]);
	}
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m>>c1>>c2;
	for(int i=1,x;i<=c1;i++)cin>>x,a[x]=1;
	for(int i=1,x;i<=c2;i++)cin>>x,b[x]=1;
	for(int i=1,u,v;i<=m;i++)cin>>u>>v,g[u]+=v,g[v]+=u;
	tarjan(1,0);
	cout<<siz(ans)<<'\n';
	for(auto[x,y]:ans)cout<<x<<' '<<y<<'\n';
	return 0;
}