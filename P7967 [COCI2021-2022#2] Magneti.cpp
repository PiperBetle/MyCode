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
constexpr int N=10001,P=1e9+7,M=51;
int n,l,a[N],fac[N],inv[N],f[M][M][N],ans;
inline int&add1(int&x,int y){return (x+=y)<P?x:x-=P;}
inline int mul0(int x,int y){return int(1ll*x*y%P);}
inline int mul0(int x,int y,int z){return int(1ll*x*y%P*z%P);}
inline int&mul1(int&x,int y){return x=int(1ll*x*y%P);}
inline int qp(int x,int y=P-2){int z=1;for(;y;mul1(x,x),y/=2)if(y&1)mul1(z,x);return z;}
inline int combi(int x,int y){return mul0(fac[x],inv[y],inv[x-y]);}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	fac[0]=fac[1]=inv[0]=inv[1]=1;
	for(int i=2;i<N;i++)fac[i]=mul0(fac[i-1],i);
	inv[N-1]=qp(fac[N-1]);
	for(int i=N-2;i>=2;i--)inv[i]=mul0(inv[i+1],i+1);
	cin>>n>>l;
	for(int i=1;i<=n;i++)cin>>a[i];
	std::sort(a+1,a+1+n);
	f[0][0][0]=1;
	for(int i=1;i<=n;i++)for(int j=1;j<=i;j++)for(int k=1;k<=l;k++){
		f[i][j][k]=f[i-1][j-1][k-1];
		if(k>=a[i])add1(f[i][j][k],mul0(f[i-1][j][k-a[i]],2*j));
		if(k>=2*a[i]-1)add1(f[i][j][k],mul0(f[i-1][j+1][k-2*a[i]+1],j*(j+1)));
	}
	for(int i=1;i<=l;i++)add1(ans,mul0(f[n][1][i],combi(l-i+n,n)));
	cout<<ans;
	return 0;
}