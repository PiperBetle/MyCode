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
constexpr venti operator""_vt(uloli x){return venti(x);}
constexpr int N=1e5+1;
int n,m,p,fac[N],inv[N];
inline int add0(int _x,int _y){return (_x+=_y)<p?_x:_x-p;}
template<typename...args>inline int add0(int _x,args..._y){return (_x+=add0(_y...))<p?_x:_x-p;}
inline int&add1(int&_x,int _y){return (_x+=_y)<p?_x:_x-=p;}
template<typename...args>inline int&add1(int&_x,args..._y){return (_x+=add0(_y...))<p?_x:_x-=p;}
inline int sub0(int _x,int _y){return (_x-=_y)<0?_x+p:_x;}
template<typename...args>inline int sub0(int _x,args..._y){return (_x-=add0(_y...))<0?_x+p:_x;}
inline int&sub1(int&_x,int _y){return (_x-=_y)<0?_x+=p:_x;}
template<typename...args>inline int&sub1(int&_x,args..._y){return (_x-=add0(_y...))<0?_x+=p:_x;}
inline int mul0(int _x,int _y){return int(1ll*_x*_y%p);}
template<typename...args>inline int mul0(int _x,args..._y){return int(1ll*_x*mul0(_y...)%p);}
inline int&mul1(int&_x,int _y){return _x=int(1ll*_x*_y%p);}
template<typename...args>inline int&mul1(int&_x,args..._y){return _x=int(1ll*_x*mul0(_y...)%p);}
inline int qp(int _x,int _y){int _t=1;for(;_y;_y>>=1,mul1(_x,_x))if(_y&1)mul1(_t,_x);return _t;}
inline int combi(int _x,int _y){
	if(_x<_y)return 0;
	if(_x<p)return mul0(fac[_x],inv[_y],inv[_x-_y]);
	return mul0(combi(_x%p,_y%p),combi(_x/p,_y/p));
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	fac[0]=fac[1]=inv[0]=inv[1]=1;
	int T;cin>>T;while(T--){
		cin>>n>>m>>p;
		for(int i=2,t;i<N;i++){t=i;while(t%p==0)t/=p;fac[i]=mul0(fac[i-1],t);}
		inv[N-1]=qp(fac[N-1],p-2);
		for(int i=N-2,t;i>=2;i--){t=i+1;while(t%p==0)t/=p;inv[i]=mul0(inv[i+1],t);}
		cout<<combi(n+m,m)<<'\n';
	}
	return 0;
}