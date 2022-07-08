#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
#define cauto const auto
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int MOD=1e9+7,kN=2*2e5+1;
inline int add0(int _x,int _y){return (_x+=_y)<MOD?_x:_x-MOD;}
template<typename...args>inline int add0(int _x,args..._y){return (_x+=add0(_y...))<MOD?_x:_x-MOD;}
inline int&add1(int&_x,int _y){return (_x+=_y)<MOD?_x:_x-=MOD;}
template<typename...args>inline int&add1(int&_x,args..._y){return (_x+=add0(_y...))<MOD?_x:_x-=MOD;}
inline int sub0(int _x,int _y){return (_x-=_y)<0?_x+MOD:_x;}
template<typename...args>inline int sub0(int _x,args..._y){return (_x-=add0(_y...))<0?_x+MOD:_x;}
inline int&sub1(int&_x,int _y){return (_x-=_y)<0?_x+=MOD:_x;}
template<typename...args>inline int&sub1(int&_x,args..._y){return (_x-=add0(_y...))<0?_x+=MOD:_x;}
inline int mul(int _x,int _y){return int(1ll*_x*_y%MOD);}
template<typename...args>inline int mul(int _x,args..._y){return int(1ll*_x*mul(_y...)%MOD);}
inline int qp(int _x,int _y){int _t=1;for(;_y;_y>>=1,_x=mul(_x,_x))if(_y&1)_t=mul(_x,_t);return _t;}
int fac[kN],ifa[kN];
inline int binum(int x,int y){return mul(fac[x],ifa[y],ifa[x-y]);}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	fac[0]=fac[1]=ifa[0]=ifa[1]=1;
	for(int i=2;i<kN;i++)fac[i]=mul(fac[i-1],i);
	ifa[kN-1]=qp(fac[kN-1],MOD-2);
	for(int i=kN-2;i>1;i--)ifa[i]=mul(ifa[i+1],i+1);
	int n,k,ans=0;cin>>n>>k;
	if(k>=n-1)return cout<<binum(2*n-1,n-1),0;
	for(int i=0;i<=k;i++)add1(ans,mul(binum(n,i),binum(n-1,i)));
	cout<<ans;
	return 0;
}