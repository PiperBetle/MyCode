//不向焦虑与抑郁投降，这个世界终会有我们存在的地方。
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<tuple>
#include<ctime>
#include<random>
#include<stack>
#include<queue>
#if __cplusplus>=202002L
#include<ranges>
namespace vw=std::views;
#endif
struct _time{~_time(){std::cerr<<"\n\033[33;40m"<<1.*clock()/CLOCKS_PER_SEC<<"s\033[37;40m";}}_TM;
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) std::begin(x),std::end(x)
#define rall(x) std::rbegin(x),std::rend(x)
#define sqrt __builtin_sqrt
#define fi first
#define se second
#define continue(x...) {x;continue;}
#define break(x...) {x;break;}
using std::cin;using std::cout;
using std::max;using std::min;
using std::tie;using std::ignore;
template<typename any>inline void cmin(any&x,const any&y){if(y<x)x=y;}
template<typename any>inline void cmax(any&x,const any&y){if(x<y)x=y;}
template<typename any,typename...args>inline void cmin(any&x,const any&y,const args&...z){cmin(x,y);cmin(x,z...);}
template<typename any,typename...args>inline void cmax(any&x,const any&y,const args&...z){cmax(x,y);cmax(x,z...);}
using loli=long long;
using unt=unsigned;
using lolu=unsigned long long;
using lodb=long double;
using venti=__int128_t;
using pii=std::pair<int,int>;
using tiii=std::tuple<int,int,int>;
using inlsi=const std::initializer_list<int>&;
using bsi=std::basic_string<int>;
using bsl=std::basic_string<loli>;
using bsc=std::string;
using std::operator""s;
#if __cplusplus>=201703L
using bscv=std::string_view;
using std::operator""sv;
#endif
std::mt19937 rng(std::random_device{}());
#define type std::pair<T1,T2>
template<typename T1,typename T2>std::istream&operator>>(std::istream&x,type&y){return x>>y.fi>>y.se;}
template<typename T1,typename T2>std::ostream&operator<<(std::ostream&x,const type&y){return x<<y.fi<<' '<<y.se;}
template<typename T1,typename T2>type operator+(const type&x,const type&y){return{x.fi+y.fi,x.se+y.se};}
template<typename T1,typename T2>type operator+=(type&x,const type&y){x.fi+=y.fi;x.se+=y.se;return x;}
template<typename T1,typename T2>type operator-(const type&x,const type&y){return{x.fi-y.fi,x.se-y.se};}
template<typename T1,typename T2>type operator-=(type&x,const type&y){x.fi-=y.fi;x.se-=y.se;return x;}
#undef type
template<typename any>any get(std::istream&x=cin){any y;x>>y;return y;}
constexpr venti operator""_vt(lolu x){return venti(x);}
constexpr bool ying=false,yang=true;
constexpr int N=1e4+1;
int n1,n2,m,dc,dfn[N],low[N],bl[N],w[N],deg[N],val[N],f[N];
bsi g1[N],g2[N];
std::stack<int>s;
std::queue<int>q;
void tarjan(int u){
	low[u]=dfn[u]=++dc;
	s.push(u);
	for(int v:g1[u])
		if(!dfn[v])tarjan(v),cmin(low[u],low[v]);
		else if(!bl[v])cmin(low[u],dfn[v]);
	if(low[u]==dfn[u]){
		bl[u]=++n2;
		for(;s.top()!=u;s.pop())bl[s.top()]=n2;
		s.pop();
	}
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n1>>m;
	for(int i=1;i<=n1;i++)cin>>w[i];
	for(int u,v;m--;)cin>>u>>v,g1[u]+=v;
	for(int i=1;i<=n1;i++)if(!dfn[i])tarjan(i);
	for(int u=1;u<=n1;u++)for(int v:g1[u])if(bl[u]!=bl[v])
		deg[bl[v]]++,g2[bl[u]]+=bl[v];
	for(int i=1;i<=n1;i++)val[bl[i]]+=w[i];
	memcpy(f+1,val+1,sizeof(int)*n2);
	for(int i=1;i<=n2;i++)if(!deg[i])q.push(i);
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int v:g2[u]){
			cmax(f[v],f[u]+val[v]);
			if(!--deg[v])q.push(v);
		}
	}
	cout<<*std::max_element(f+1,f+1+n2);
	return 0;
}