//不向焦虑与抑郁投降，这个世界终会有我们存在的地方。
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<tuple>
#include<ctime>
#include<random>
#include<ext/pb_ds/priority_queue.hpp>
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
template<typename any>constexpr any&cmin(any&x,any&&y){if(y<x)x=y;return x;}
template<typename any>constexpr any&cmax(any&x,any&&y){if(x<y)x=y;return x;}
template<typename any,typename...args>constexpr any&cmin(any&x,any&&y,args&&...z){if(y<x)x=y;return cmin(x,std::forward<any>(z)...);}
template<typename any,typename...args>constexpr any&cmax(any&x,any&&y,args&&...z){if(x<y)x=y;return cmax(x,std::forward<any>(z)...);}
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
template<typename any>any&STLcls(any &x){any{}.swap(x);return x;}
constexpr venti operator""_vt(lolu x){return venti(x);}
constexpr bool ying=false,yang=true;
constexpr int N=1e5+1;
int n,m,fa[N];
bool del[N];
__gnu_pbds::priority_queue<pii,std::greater<>>q[N];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)fa[i]=i,q[i].push({get<int>(),i});
	for(int x,y,fx,fy;m--;)switch(get<int>()){
	case 1:{
		cin>>x>>y;fx=find(x),fy=find(y);
		if(fx==fy||del[x]||del[y])continue;
		fa[fx]=fy;q[fy].join(q[fx]);
	}break;
	case 2:{
		cin>>x;fx=find(x);
		if(del[x])continue(cout<<"-1\n")
		cout<<q[fx].top().fi<<'\n';
		del[q[fx].top().se]=true;
		q[fx].pop();
	}break;
	}
	return 0;
}