//不向焦虑与抑郁投降，这个世界终会有我们存在的地方。
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<tuple>
#include<ctime>
#include<random>
#include<map>
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
std::mt19937_64 rng(std::random_device{}());
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
constexpr int N=2507;
int n,m,q;
lolu d[N][N],k;
std::map<std::tuple<int,int,int,int>,lolu>mp;
void add(int x,int y,lolu k){
	for(int i=x;i<=n;i+=i&-i)for(int j=y;j<=m;j+=j&-j)
		d[i][j]+=k;
}
lolu ask(int x,int y){
	lolu k=0;
	for(int i=x;i;i-=i&-i)for(int j=y;j;j-=j&-j)
		k+=d[i][j];
	return k;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m>>q;
	for(int x1,y1,x2,y2;q--;)switch(get<int>()){
	case 1:{
		cin>>x1>>y1>>x2>>y2;
		if(auto it=mp.find({x1,y1,x2,y2});it==mp.end())
			k=mp[{x1,y1,x2,y2}]=rng();
		else k=mp[{x1,y1,x2,y2}];
		add(x2+1,y2+1,k);
		add(x1,y2+1,-k);
		add(x2+1,y1,-k);
		add(x1,y1,k);
	}break;
	case 2:{
		cin>>x1>>y1>>x2>>y2;
		if(auto it=mp.find({x1,y1,x2,y2});it==mp.end())
			k=mp[{x1,y1,x2,y2}]=rng();
		else k=mp[{x1,y1,x2,y2}];
		add(x2+1,y2+1,-k);
		add(x1,y2+1,k);
		add(x2+1,y1,k);
		add(x1,y1,-k);
	}break;
	case 3:{
		cin>>x1>>y1>>x2>>y2;
		cout<<(ask(x1,y1)==ask(x2,y2)?"Yes\n":"No\n");break;
	}break;
	}
	return 0;
}