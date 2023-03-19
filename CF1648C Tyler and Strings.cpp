//不向焦虑与抑郁投降，这个世界终会有我们存在的地方。
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
constexpr int N=1e6+1,MOD=998244353;
inline int&add1(int&x,int y){return (x+=y)<MOD?x:x-=MOD;}
inline int mul0(int x,int y){return int(1ll*x*y%MOD);}
inline int mul0(int x,int y,int z){return int(1ll*x*y%MOD*z%MOD);}
inline int&mul1(int&x,int y){return x=int(1ll*x*y%MOD);}
inline int qp(int x,int y=MOD-2){int z=1;for(;y;y/=2,mul1(x,x))if(y&1)mul1(z,x);return z;}
int n,m,fac[N],a[N],b[N],fc=1,ans;
struct{
	int d[N];
	void add(int x){for(;x<N;x+=x&-x)d[x]++;}
	void del(int x){for(;x<N;x+=x&-x)d[x]--;}
	int ask(int x){int k=0;for(;x;x-=x&-x)k+=d[x];return k;}
	int operator[](int x){return ask(x)-ask(x-1);}
}tr;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	fac[0]=1;for(int i=1;i<N;i++)fac[i]=mul0(fac[i-1],i);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],tr.add(a[i]);
	for(int i=1;i<=m;i++)cin>>b[i];
	for(int i=1;i<N;i++)mul1(fc,fac[tr[i]]);
	for(int i=1;i<=min(n+1,m);i++){
		if(i>n){if(n<m)add1(ans,1);break;}
		add1(ans,mul0(tr.ask(b[i]-1),fac[n-i],qp(fc)));
		if(tr[b[i]])mul1(fc,qp(tr[b[i]])),tr.del(b[i]);else break;
	}
	cout<<ans;
	return 0;
}