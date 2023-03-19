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
constexpr int N=2001,MOD=1e9+7;
int n,ans,fac[4*N],ifa[4*N],f[2*N][2*N];
struct{int x,y;}a[200001];
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
	for(int i=2;i<4*N;i++)fac[i]=mul0(fac[i-1],i);
	ifa[4*N-1]=qp(fac[4*N-1],MOD-2);
	for(int i=4*N-2;i>=2;i--)ifa[i]=mul0(ifa[i+1],i+1);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].x>>a[i].y,f[N-a[i].x][N-a[i].y]++;
	for(int i=1;i<2*N;i++)for(int j=1;j<2*N;j++)add1(f[i][j],f[i-1][j],f[i][j-1]);
	for(int i=1;i<=n;i++)add1(ans,sub0(f[N+a[i].x][N+a[i].y],combi(2*a[i].x+2*a[i].y,2*a[i].x)));
	cout<<mul1(ans,qp(2,MOD-2));
	return 0;
}