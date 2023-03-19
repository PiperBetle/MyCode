//不向焦虑与抑郁投降，这个世界终会有我们存在的地方。
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<tuple>
#include<ctime>
#include<random>
#include<list>
#include<unordered_set>
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
template<typename any,typename...args>inline void cmin(any &x,const any &y,const args &...z){cmin(x,y);cmin(x,z...);}
template<typename any,typename...args>inline void cmax(any &x,const any &y,const args &...z){cmax(x,y);cmax(x,z...);}
using loli=long long;
using uloli=unsigned long long;
using lodb=long double;
using venti=__int128_t;
using pii=std::pair<int,int>;
using tiii=std::tuple<int,int,int>;
using tcii=std::tuple<char,int,int>;
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
constexpr int N=2e5+1;
int n,m,a[N],fa[N],sum[N],ans[N];
bool del[N];
std::list<int>b[N];
tcii q[N];
std::vector<pii>e;
std::unordered_set<int>g;
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
signed main(){
//	freopen("farm.in","r",stdin);
//	freopen("farm.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;e.emplace_back();
	for(int i=1;i<=m;i++){
		auto&[c,x,y]=q[i];
		cin>>c;
		switch(c){
		case 'D':cin>>x;del[x]=yang;break;
		case 'A':cin>>x>>y;g.insert(siz(e));e.emplace_back(x,y);break;
		case 'R':cin>>x;g.erase(x);break;
		}
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;
		if(del[i]){
			b[i].push_back(i);
		}else{
			ans[i]=m;
			sum[i]=1;
		}
	}
	for(int k:g){
		auto[x,y]=e[k];
		x=find(x),y=find(y);
		if(x!=y){
			fa[y]=x;
			b[x].splice(b[x].end(),b[y]);
			sum[x]+=sum[y];
			if(sum[x]){
				for(int i:b[x])ans[i]=m;
				b[x].clear();
			}
		}
	}
	for(int k=m;k>=1;k--){
		auto[c,x,y]=q[k];
		switch(c)
		{case 'D':{
			x=find(x);
			sum[x]++;
			for(int i:b[x])ans[i]=k-1;
			b[x].clear();
		}break;case 'A':{
		}break;case 'R':{
			y=find(e[x].se),x=find(e[x].fi);
			if(x!=y){
				fa[y]=x;
				b[x].splice(b[x].end(),b[y]);
				sum[x]+=sum[y];
				if(sum[x]){
					for(int i:b[x])ans[i]=k-1;
					b[x].clear();
				}
			}
		}break;
		}
	}
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<'\n';
	return 0;
}