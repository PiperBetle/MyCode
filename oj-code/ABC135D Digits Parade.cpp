#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) x.begin(),x.end()
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=1e5+1,MOD=1e9+7;
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
std::string s;
int f[kN][13];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>s;s='~'+s;f[0][0]=1;
	for(int i=1;i<siz(s);i++)
		if(s[i]=='?'){
			for(int j=0;j<13;j++)for(int k=0;k<10;k++)
				add1(f[i][(j*10+k)%13],f[i-1][j]);
		}else{
			for(int j=0,k=s[i]-'0';j<13;j++)
				add1(f[i][(j*10+k)%13],f[i-1][j]);
		}
	cout<<f[siz(s)-1][5];
	return 0;
}