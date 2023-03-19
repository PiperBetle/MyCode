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
constexpr int N=1e5+1,P=1e9+7;
inline int&add1(int&x,int y){return (x+=y)<P?x:x-=P;}
inline int mul0(int x,int y){return int(1ll*x*y%P);}
inline int&mul1(int&x,int y){return x=int(1ll*x*y%P);}
inline int mul0(int x,int y,int z){return int(1ll*x*y%P*z%P);}
inline int qp(int x,int y=P-2){int z=1;for(;y;y>>=1,x=mul1(x,x))if(y&1)mul1(z,x);return z;}
int n,k,ans,fac[N],inv[N];
inline int binum(int x,int y){return mul0(fac[x],inv[y],inv[x-y]);}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>k;cmin(k,n);
	fac[0]=fac[1]=inv[0]=inv[1]=1;
	for(int i=2;i<=n;i++)fac[i]=mul0(fac[i-1],i);
	inv[n]=qp(fac[n]);
	for(int i=n-1;i>=2;i--)inv[i]=mul0(inv[i+1],i+1);
	for(int i=0;i<=k;i++)add1(ans,binum(n,i));
	cout<<ans;
	return 0;
}