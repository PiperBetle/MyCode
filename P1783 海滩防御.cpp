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
using tdii=std::tuple<double,int,int>;
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
constexpr int N=1002;
int n,m,fa[N];
pii a[N];
double dis(pii p1,pii p2){
	auto sqr=[](int x)->double{return 1.*x*x;};
	return sqrt(sqr(p1.fi-p2.fi)+sqr(p1.se-p2.se));
}
inline int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
std::vector<tdii>e;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=m;i++)cin>>a[i].fi>>a[i].se;
	for(int i=1;i<m;i++)for(int j=i+1;j<=m;j++)
		e.emplace_back(dis(a[i],a[j]),i,j);
	for(int i=1;i<=m;i++)
		e.emplace_back(a[i].fi*2,i,0),
		e.emplace_back((n-a[i].fi)*2,i,m+1);
	sort(all(e));
	for(int i=0;i<=m+1;i++)fa[i]=i;
	for(auto[w,x,y]:e){
		x=find(x),y=find(y);
		if(x!=y)fa[x]=y;
		if(find(0)==find(m+1))
			return printf("%.2f",w/2),0;
	}
	return 0;
}