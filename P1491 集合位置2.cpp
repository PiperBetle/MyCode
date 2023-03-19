//不向焦虑与抑郁投降，这个世界终会有我们存在的地方。
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<tuple>
#include<ctime>
#include<random>
#include<queue>
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
using pdi=std::pair<double,int>;
using pid=std::pair<int,double>;
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
constexpr int N=201;
inline auto sqr(auto x){return x*x;}
std::priority_queue<pdi,std::vector<pdi>,std::greater<>>q;
std::vector<pid>g[N];
double ans=1e100;
int n,m,pre[N];
pii a[N];
bool vis[N];
double dis[N];
void dijkstra(int x,int y){
	memset(vis,0,sizeof vis);
	memset(dis,0x42,sizeof dis);
	for(q.emplace(dis[1]=0,1);!q.empty();){
		int u=q.top().se;q.pop();
		if(vis[u])continue;else vis[u]=true;
		for(auto[v,t]:g[u])if(!((x==u&&y==v)||(x==v&&y==u))&&dis[v]>dis[u]+t)
			q.emplace(dis[v]=dis[u]+t,v);
	}
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i].fi>>a[i].se;
	for(int i=1,u,v;i<=m;i++){
		cin>>u>>v;
		double t=sqrt(sqr(a[u].fi-a[v].fi)+sqr(a[u].se-a[v].se));
		g[u].emplace_back(v,t),g[v].emplace_back(u,t);
	}
	memset(dis,0x42,sizeof dis);
	for(q.emplace(dis[1]=0,1);!q.empty();){
		int u=q.top().se;q.pop();
		if(vis[u])continue;else vis[u]=true;
		for(auto[v,t]:g[u])if(dis[v]>dis[u]+t)
			pre[v]=u,q.emplace(dis[v]=dis[u]+t,v);
	}
	for(int v=n;v!=1;v=pre[v])dijkstra(pre[v],v),cmin(ans,dis[n]);
	if(ans>dis[n])printf("-1");else printf("%.2lf",ans);
	return 0;
}