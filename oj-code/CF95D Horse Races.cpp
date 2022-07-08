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
constexpr int MOD=1e9+7,kN=1001;
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
int f[kN][kN][2],T,k;
std::basic_string<int>sta;
int dfs(int pos,int dis,bool cnt,bool lim){
	if(!pos)return cnt;
	if(!lim&&~f[pos][dis][cnt])return f[pos][dis][cnt];
	int ans=0,num=lim?sta[pos]:9;
	for(int i=0;i<=num;i++){
		if(i==4||i==7)add1(ans,dfs(pos-1,k,cnt||dis,lim&&i==num));
		else add1(ans,dfs(pos-1,dis?dis-1:0,cnt,lim&&i==num));
	}
	if(!lim)f[pos][dis][cnt]=ans;
	return ans;
}
int solve(const std::string &s){
	sta.clear();
	for(int c:s)sta+=c-'0';
	std::reverse(sta.begin(),sta.end());
	sta=0+sta;
	return dfs(siz(sta),0,0,1);
}
int check(const std::string &s){
	int lst=0x3f3f3f3f;
	for(int i=siz(s)-1;i>=0;i--)
		if(s[i]=='4'||s[i]=='7'){if(lst-i<=k)return true;else lst=i;}
	return false;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	memset(f,-1,sizeof f);
	cin>>T>>k;
	for(std::string l,r;T--;){
		cin>>l>>r;
		cout<<sub0(add0(solve(r),check(l)),solve(l))<<'\n';
	}
	return 0;
}