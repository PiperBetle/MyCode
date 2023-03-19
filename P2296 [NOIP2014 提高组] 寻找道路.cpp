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
constexpr int N=10001;
bsi g[N];
int n,m,bg,ed,dis[N];
bool vis[N],god[N];
std::queue<int>q;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1,u,v;i<=m;i++)if(cin>>u>>v,u!=v)g[v]+=u;
	for(int i=1;i<=n;i++)sort(all(g[i])),g[i].erase(unique(all(g[i])),g[i].end());
	cin>>bg>>ed;
	vis[ed]=true;q.push(ed);
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int v:g[u])if(!vis[v])
			vis[v]=true,q.push(v);
	}
	if(!vis[bg])return cout<<"-1",0;
	memcpy(god+1,vis+1,sizeof(bool)*n);
	for(int i=1;i<=n;i++)if(!vis[i])
		for(int v:g[i])god[v]=false;
	q.push(ed);
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int v:g[u])if(god[v]&&!dis[v])
			q.push(v),dis[v]=dis[u]+1;
	}
	cout<<(dis[bg]?dis[bg]:-1);
	return 0;
}