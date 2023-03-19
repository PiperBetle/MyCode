#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<tuple>
#define int loli
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
int n,a[N],s1,s2=1;
int qp(int _a,int _b=MOD-2){int _c=1;for(;_b;_b>>=1,_a=_a*_a%MOD)if(_b&1)_c=_c*_a%MOD;return _c;}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n*2;i++)cin>>a[i];
	std::sort(a+1,a+1+n*2);
	for(int i=1;i<=n;i++)(s1+=a[i+n]-a[i])%=MOD;
	for(int i=1;i<=n;i++)(s1*=(n+i))%=MOD,(s2*=i)%=MOD;
	cout<<s1*qp(s2)%MOD;
	return 0;
}