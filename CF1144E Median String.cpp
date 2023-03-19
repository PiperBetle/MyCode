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
template<typename any>inline void cmin(any &x,const any &y){if(y<x)x=y;}
template<typename any>inline void cmax(any &x,const any &y){if(x<y)x=y;}
template<typename any,typename...args>inline void cmin(any &x,const any &y,const args &...z){cmin(x,y);cmin(x,z...);}
template<typename any,typename...args>inline void cmax(any &x,const any &y,const args &...z){cmax(x,y);cmax(x,z...);}
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
constexpr venti operator""_vt(lolu x){return venti(x);}
constexpr bool ying=false,yang=true;
int n;
struct bigint:bsc{
#define a (*this)
	bigint()=default;
	bigint(int x){resize(x+1);}
	bigint(const bsc &s){
		assign(all(s));
		for(char&i:a)i-='a';
		reverse(all(a));
	}
	bigint &del0(){
		while(siz(a)>1&&!back())pop_back();
		return a;
	}
	friend bigint operator+(const bigint &x,const bigint &y){
		bigint z=max(siz(x),siz(y))+1;
		for(int i=0;i<siz(z)-1;i++){
			z[i]+=x[i]+y[i];
			if(z[i]>=26)z[i]-=26,z[i+1]++;
		}
		return z.del0();
	}
	bigint &div2(){
		for(int i=siz(a)-1;~i;i--){
			if(a[i]&1)a[i-1]+=26;
			a[i]/=2;
		}
		return a.del0();
	}
	template<typename any>
	friend any &operator<<(any &x,const bigint &y){
		for(int i=n-siz(y);i>=1;i--)x<<'a';
		for(int i=siz(y)-1;~i;i--)x<<char(y[i]+'a');
		return x;
	}
#undef a
}a,b;
bsc s;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	cin>>s;a=s;
	cin>>s;b=s;
	cout<<(a+b).div2();
	return 0;
}