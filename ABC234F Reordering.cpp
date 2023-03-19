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
constexpr int kN=5001,MOD=998244353;
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
int fac[kN],ifa[kN],f[27][kN],cnt[27];
inline int binum(int _x,int _y){return mul0(fac[_x],ifa[_y],ifa[_x-_y]);}
std::string s;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	fac[0]=fac[1]=ifa[0]=ifa[1]=1;
	for(int i=2;i<kN;i++)fac[i]=mul0(fac[i-1],i);
	ifa[kN-1]=qp(fac[kN-1],MOD-2);
	for(int i=kN-2;i>=2;i--)ifa[i]=mul0(ifa[i+1],i+1);
	cin>>s;f[0][0]=1;
	for(char c:s)cnt[c-'a']++;
	for(int i=0;i<26;i++)for(int j=0;j<=siz(s);j++)for(int k=0;k<=std::min(j,cnt[i]);k++)
		add1(f[i+1][j],mul0(f[i][j-k],binum(j,k)));
	int ans=0;
	for(int i=1;i<=siz(s);i++)add1(ans,f[26][i]);
	cout<<ans;
	return 0;
}