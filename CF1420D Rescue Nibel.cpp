#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<tuple>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
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
using inlsi=const std::initializer_list<int>&;
using bsi=std::basic_string<int>;
using bsc=std::basic_string<char>;
constexpr venti operator""_vt(uloli x){return venti(x);}
constexpr int N=3e5+1,MOD=998244353;
inline int&add1(int&_x,int _y){return (_x+=_y)<MOD?_x:_x-=MOD;}
inline int mul0(int _x,int _y){return int(1ll*_x*_y%MOD);}
template<typename...args>inline int mul0(int _x,args..._y){return int(1ll*_x*mul0(_y...)%MOD);}
inline int&mul1(int&_x,int _y){return _x=int(1ll*_x*_y%MOD);}
inline int qp(int _x,int _y=MOD-2){int _z=1;for(;_y;_y>>=1,mul1(_x,_x))if(_y&1)mul1(_z,_x);return _z;}
int n,m,fac[N<<1],inv[N<<1],ans;
inline int binom(int _x,int _y){return mul0(fac[_x],inv[_y],inv[_x-_y]);}
pii a[N];
bsi b;
struct{
	int d[N<<1];
	void add(int x,int k=1){for(;x<siz(b);x+=x&-x)d[x]+=k;}
	int ask(int x){int k=0;for(;x;x-=x&-x)k+=d[x];return k;}
	int ask(int l,int r){return ask(r)-ask(l-1);}
}tr;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	fac[0]=fac[1]=inv[0]=inv[1]=1;
	for(int i=2;i<=n;i++)fac[i]=mul0(fac[i-1],i);
	inv[n]=qp(fac[n]);
	for(int i=n-1;i>=2;i--)inv[i]=mul0(inv[i+1],i+1);
	for(int i=1;i<=n;i++)cin>>a[i].fi>>a[i].se,(b+=a[i].fi)+=a[i].se;
	std::sort(all(b));b.erase(std::unique(all(b)),b.end());b=0+b;
	std::sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		a[i].fi=int(std::lower_bound(all(b),a[i].fi)-b.begin());
		a[i].se=int(std::lower_bound(all(b),a[i].se)-b.begin());
		int c=tr.ask(a[i].fi,siz(b)-1);tr.add(a[i].se);
		if(c>=m-1)add1(ans,binom(c,m-1));
	}
	cout<<ans;
	return 0;
}