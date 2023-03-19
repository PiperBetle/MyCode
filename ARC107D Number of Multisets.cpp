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
template<typename any>any&STLcls(any &x){any{}.swap(x);return x;}
constexpr venti operator""_vt(lolu x){return venti(x);}
constexpr bool ying=false,yang=true;
constexpr int P=998244353,N=3001;
struct mint{
	int d;
	mint()=default;
	constexpr mint(int x):d(x){}
	constexpr mint(loli x):d(int(x%P)){}
	constexpr explicit operator int(){return d;}
	friend std::istream &operator>>(std::istream &x,mint &y){return x>>y.d;}
	friend std::ostream &operator<<(std::ostream &x,mint y){return x<<y.d;}
	constexpr friend mint operator+(mint x,mint y){return (x.d+=y.d)<P?x.d:x.d-P;}
	constexpr mint &operator+=(mint z){return (d+=z.d)<P?d:d-=P,*this;}
	constexpr friend mint operator-(mint x,mint y){return (x.d-=y.d)<0?x.d+P:x.d;}
	constexpr mint &operator-=(mint z){return (d-=z.d)<0?d+=P:d,*this;}
	constexpr friend mint operator*(mint x,mint y){return int(1ll*x.d*y.d%P);}
	constexpr mint &operator*=(mint z){return d=int(1ll*d*z.d%P),*this;}
	constexpr static mint qpow(int x,loli y=P-2){int z=1;for(;y;y>>=1,x=int(1ll*x*x%P))if(y&1)z=int(1ll*x*z%P);return z;}
	constexpr friend mint operator/(mint x,mint y){return x*=qpow(y.d);}
	constexpr mint &operator/=(mint z){return (*this)*=qpow(z.d);}
	constexpr mint inv(){return qpow(d);}
	constexpr mint pow(mint z){return qpow(d,z.d);}
	constexpr mint pow(int z){return z>=0?qpow(d,z):1/qpow(d,-z);}
	constexpr int operator+(){return d;}
	constexpr mint operator-(){return P-d;}
};
int n,k;
mint f[N][N];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		f[i][i]=1;
		for(int j=i-1;j>=0;j--){
			f[i][j]+=f[i-1][j-1];
			if(j*2<=i)f[i][j]+=f[i][j*2];
		}
	}
	cout<<f[n][k];
	return 0;
}