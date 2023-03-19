#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=2e5+1,kM=2001,MOD=1e9+7;
int n,m,k,fac[kN],ifa[kN],f[kN];
pii a[kM];
inline int add0(int _x,int _y){return (_x+=_y)<MOD?_x:_x-MOD;}
template<typename...args>inline int add0(int _x,args..._y){return (_x+=add0(_y...))<MOD?_x:_x-MOD;}
inline int&add1(int&_x,int _y){return (_x+=_y)<MOD?_x:_x-=MOD;}
template<typename...args>inline int&add1(int&_x,args..._y){return (_x+=add0(_y...))<MOD?_x:_x-=MOD;}
inline int sub0(int _x,int _y){return (_x-=_y)<0?_x+MOD:_x;}
template<typename...args>inline int sub0(int _x,args..._y){return (_x-=add0(_y...))<0?_x+MOD:_x;}
inline int&sub1(int&_x,int _y){return (_x-=_y)<0?_x+=MOD:_x;}
template<typename...args>inline int&sub1(int&_x,args..._y){return (_x-=add0(_y...))<0?_x+=MOD:_x;}
inline int mul0(int _x,int _y){return int(1ll*_x*_y%MOD);}
template<typename...args>inline int mul0(int _x,args..._y){return int(1ll*_x*mul0(_y...)%MOD);}
inline int&mul1(int&_x,int _y){return _x=int(1ll*_x*_y%MOD);}
template<typename...args>inline int&mul1(int&_x,args..._y){return _x=int(1ll*_x*mul0(_y...)%MOD);}
inline int qp(int _x,int _y){int _t=1;for(;_y;_y>>=1,mul1(_x,_x))if(_y&1)mul1(_t,_x);return _t;}
inline int combi(int _x,int _y){return mul0(fac[_x],ifa[_x-_y],ifa[_y]);}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	fac[0]=fac[1]=ifa[0]=ifa[1]=1;
	for(int i=2;i<kN;i++)fac[i]=mul0(fac[i-1],i);
	ifa[kN-1]=qp(fac[kN-1],MOD-2);
	for(int i=kN-2;i>=2;i--)ifa[i]=mul0(ifa[i+1],i+1);
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++)cin>>a[i].first>>a[i].second;
	a[++k]={n,m};
	std::sort(a+1,a+1+k);
	for(int i=1;i<=k;i++){
		f[i]=combi(a[i].first+a[i].second-2,a[i].first-1);
		for(int j=1;j<i;j++)if(a[j].first<=a[i].first&&a[j].second<=a[i].second)
			sub1(f[i],mul0(f[j],combi(a[i].first+a[i].second-a[j].first-a[j].second,a[i].first-a[j].first)));
	}
	cout<<f[k];
	return 0;
}