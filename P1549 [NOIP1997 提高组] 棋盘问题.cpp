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
int n,m;
bsi b1,b2;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	if(n<=2)return cout<<"NO\n";
	else if(n==3){
	cout<<R"(3 6 9
7 8 1
2 4 5)";
	}else if(n==4){
		cout<<R"(15 11 16 12
13 3 6 9
14 7 8 1
4 2 10 5)";
	}else if(n==5){
		cout<<R"(5 11 17 23 1
7 13 25 19 3
9 15 21 6 12
18 24 4 10 16
22 2 8 14 20)";
	}else{
		for(int i=1;i<=n*n;i++)(i&1?b1:b2)+=i;
		std::sort(all(b1),[](int x,int y){return x%3>y%3;});
		std::sort(all(b2),[](int x,int y){return x%3<y%3;});
		for(int i:b1)if(cout<<i<<' ',(++m)%n==0)cout<<'\n';
		for(int i:b2)if(cout<<i<<' ',(++m)%n==0)cout<<'\n';
	}
	return 0;
}