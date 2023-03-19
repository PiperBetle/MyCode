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
constexpr int N=1e5+1,M=2e6+1;
int n,m,deg[N];
bool vis[N],ins[N],del[M];
bsi s,e,g[N];
bsi::iterator hed[N];
std::vector<bsi>ans;
void dfs(int u){
	vis[u]=true;
	for(auto it=hed[u];it!=g[u].end();++it)if(int v=e[*it];!del[*it]){
		del[*it]=del[*it^1]=yang;hed[u]=next(it);
		dfs(v);
		if(ins[v]){
			ans.emplace_back(1,v);
			for(;s.back()!=v;s.pop_back())
				ans.back()+=s.back(),ins[s.back()]=ying;
		}else s+=v,ins[v]=yang;
	}
}
signed main(){
//  freopen(".in","r",stdin);
//  freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1,u,v,c1,c2;i<=m;i++)
		if(cin>>u>>v>>c1>>c2,
			c1!=c2)g[u]+=siz(e),e+=v,g[v]+=siz(e),e+=u,deg[u]++,deg[v]++;
	for(int i=1;i<=n;i++)if(deg[i]&1)return cout<<"NIE",0;
	for(int i=1;i<=n;i++)hed[i]=g[i].begin();
	for(int i=1;i<=n;i++)if(!vis[i]){
		dfs(i);
		if(ins[i]){
			for(int j:s)ins[j]=ying;
			ans.emplace_back().swap(s);
		}
	}
	cout<<siz(ans)<<'\n';
	for(cauto&v:ans){
		cout<<siz(v)<<' ';
		for(int i:v)cout<<i<<' ';
		cout<<v.front()<<'\n';
	}
	return 0;
}