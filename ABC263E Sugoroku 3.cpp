#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
using std::cin;using std::cout;
using loli=long long;
using uloli=unsigned long long;
using lodb=long double;
using venti=__int128_t;
using pii=std::pair<int,int>;
using inlsi=const std::initializer_list<int>&;
constexpr venti operator""_vt(uloli x){return venti(x);}
constexpr int N=2e5+1,MOD=998244353;
inline int add0(int _x,int _y){return (_x+=_y)<MOD?_x:_x-MOD;}
template<typename...args>inline int add0(int _x,args..._y){return (_x+=add0(_y...))<MOD?_x:_x-MOD;}
inline int&add1(int&_x,int _y){return (_x+=_y)<MOD?_x:_x-=MOD;}
template<typename...args>inline int&add1(int&_x,args..._y){return (_x+=add0(_y...))<MOD?_x:_x-=MOD;}
inline int add0(inlsi _x){int _y=0;for(int _i:_x)add1(_y,_i);return _y;}
inline int&add1(int&_x,inlsi _y){return add1(_x,add0(_y));}
inline int sub0(int _x,int _y){return (_x-=_y)<0?_x+MOD:_x;}
template<typename...args>inline int sub0(int _x,args..._y){return (_x-=add0(_y...))<0?_x+MOD:_x;}
inline int&sub1(int&_x,int _y){return (_x-=_y)<0?_x+=MOD:_x;}
template<typename...args>inline int&sub1(int&_x,args..._y){return (_x-=add0(_y...))<0?_x+=MOD:_x;}
inline int sub0(inlsi _x,inlsi _y){return sub0(add0(_x),add0(_y));}
inline int&sub1(int&_x,inlsi _y){return sub1(_x,add0(_y));}
inline int mul0(int _x,int _y){return int(1ll*_x*_y%MOD);}
template<typename...args>inline int mul0(int _x,args..._y){return int(1ll*_x*mul0(_y...)%MOD);}
inline int&mul1(int&_x,int _y){return _x=int(1ll*_x*_y%MOD);}
template<typename...args>inline int&mul1(int&_x,args..._y){return _x=int(1ll*_x*mul0(_y...)%MOD);}
inline int mul0(inlsi _x){int _y=1;for(int _i:_x)mul1(_y,_i);return _y;}
inline int&mul1(int&_x,inlsi _y){return mul1(_x,mul0(_y));}
inline int qp(int _x,int _y){int _t=1;for(;_y;_y>>=1,mul1(_x,_x))if(_y&1)mul1(_t,_x);return _t;}
inline int _inv(int _x){return qp(_x,MOD-2);}
inline int div0(int _x,int _y){return mul0(_x,_inv(_y));}
template<typename...args>inline int div0(int _x,args..._y){return mul0(_x,_inv(mul0(_y...)));}
inline int&div1(int&_x,int _y){return _x=mul0(_x,_inv(_y));}
template<typename...args>inline int&div1(int&_x,args..._y){return _x=mul0(_x,_inv(mul0(_y...)));}
inline int div0(inlsi _x,inlsi _y){return div0(mul0(_x),mul0(_y));}
inline int&div1(int&_x,inlsi _y){return div1(_x,mul0(_y));}
int n,a[N],f[N],sum[N];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<n;i++)cin>>a[i];
	for(int i=n-1;i>=1;i--){
		f[i]=mul0(add0(sub0(sum[i+1],sum[i+a[i]+1]),a[i]+1),_inv(a[i]));
		sum[i]=add0(sum[i+1],f[i]);
	}
	cout<<f[1];
	return 0;
}