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
constexpr int N=2e5+10,P=998244353;
int n,a[N],pre[N],suf[N],c[N],ans,f[N];
inline int add0(int _x,int _y){return (_x+=_y)<P?_x:_x-P;}
template<typename...args>inline int add0(int _x,args..._y){return (_x+=add0(_y...))<P?_x:_x-P;}
inline int&add1(int&_x,int _y){return (_x+=_y)<P?_x:_x-=P;}
template<typename...args>inline int&add1(int&_x,args..._y){return (_x+=add0(_y...))<P?_x:_x-=P;}
inline int add0(inlsi _x){int _y=0;for(int _i:_x)add1(_y,_i);return _y;}
inline int&add1(int&_x,inlsi _y){return add1(_x,add0(_y));}
inline int sub0(int _x,int _y){return (_x-=_y)<0?_x+P:_x;}
template<typename...args>inline int sub0(int _x,args..._y){return (_x-=add0(_y...))<0?_x+P:_x;}
inline int&sub1(int&_x,int _y){return (_x-=_y)<0?_x+=P:_x;}
template<typename...args>inline int&sub1(int&_x,args..._y){return (_x-=add0(_y...))<0?_x+=P:_x;}
inline int sub0(inlsi _x,inlsi _y){return sub0(add0(_x),add0(_y));}
inline int&sub1(int&_x,inlsi _y){return sub1(_x,add0(_y));}
inline int mul0(int _x,int _y){return int(1ll*_x*_y%P);}
template<typename...args>inline int mul0(int _x,args..._y){return int(1ll*_x*mul0(_y...)%P);}
inline int&mul1(int&_x,int _y){return _x=int(1ll*_x*_y%P);}
template<typename...args>inline int&mul1(int&_x,args..._y){return _x=int(1ll*_x*mul0(_y...)%P);}
inline int mul0(inlsi _x){int _y=1;for(int _i:_x)mul1(_y,_i);return _y;}
inline int&mul1(int&_x,inlsi _y){return mul1(_x,mul0(_y));}
inline int qp(int _x,int _y){int _t=1;for(;_y;_y>>=1,mul1(_x,_x))if(_y&1)mul1(_t,_x);return _t;}
inline int _inv(int _x){return qp(_x,P-2);}
inline int div0(int _x,int _y){return mul0(_x,_inv(_y));}
template<typename...args>inline int div0(int _x,args..._y){return mul0(_x,_inv(mul0(_y...)));}
inline int&div1(int&_x,int _y){return _x=mul0(_x,_inv(_y));}
template<typename...args>inline int&div1(int&_x,args..._y){return _x=mul0(_x,_inv(mul0(_y...)));}
inline int div0(inlsi _x,inlsi _y){return div0(mul0(_x),mul0(_y));}
inline int&div1(int&_x,inlsi _y){return div1(_x,mul0(_y));}
struct{
	int d[N];
	void add(int x,int k){for(;x<=n+1;x+=x&-x)add1(d[x],k);}
	void del(int x,int k){for(;x<=n+1;x+=x&-x)sub1(d[x],k);}
	int ask(int x){int k=0;for(;x;x-=x&-x)add1(k,d[x]);return k;}
}tr;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(c[a[i]])suf[c[a[i]]]=i,pre[i]=c[a[i]];
		c[a[i]]=i;
	}
	tr.add(1,1);
	for(int i=1;i<=n;i++){
		f[i]=sub0(tr.ask(i),tr.ask(pre[i]));
		tr.del(pre[i]+1,f[pre[i]]);tr.add(i+1,f[i]);
		if(!suf[i])add1(ans,f[i]);
	}
	cout<<ans;
	return 0;
}