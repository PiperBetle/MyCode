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
constexpr int kN=1001,MOD=1e9+7;
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
int f[kN][11][11][2][2];
std::basic_string<int>sta;
int dfs(int pos,int d1,int d2,bool zer,bool cnt,bool lim){
	if(!pos)return cnt;
	if(!lim&&~f[pos][d1][d2][zer][cnt])return f[pos][d1][d2][zer][cnt];
	int ans=0;
	for(int i=zer?1:0,num=lim?sta[pos]:9;i<=num;i++)
		add1(ans,dfs(pos-1,i,d1,0,cnt||i==d1||i==d2,lim&&i==num));
	if(!lim)f[pos][d1][d2][zer][cnt]=ans;
	return ans;
}
int check(const std::string &s){
	for(int i=0;i<siz(s);i++)
		if((i>0&&s[i]==s[i-1])||(i>1&&s[i]==s[i-2]))return 1;
	return 0;
}
int solve(const std::string &s){
	sta.clear();
	for(char c:s)sta+=c-'0';
	std::reverse(sta.begin(),sta.end());
	sta=0+sta;
	int ans=dfs(siz(sta)-1,10,10,1,0,1);
	for(int i=siz(sta)-2;i>=1;i--)add1(ans,dfs(i,10,10,1,0,0));
	return ans;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	memset(f,-1,sizeof f);
	std::string l,r;cin>>l>>r;
	cout<<sub0(add0(solve(r),check(l)),solve(l));
	return 0;
}