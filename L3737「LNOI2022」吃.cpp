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
constexpr int N=5e5+1,MOD=1e9+7;
int n,m,ans=1;
pii a[N],b[N];
bsi mul;
bool bm=false;
inline int&add1(int y){
	if((ans+=y)>=MOD)ans-=MOD,bm=true;
	return ans;
}
inline int&mul1(int y){
	loli z=1ll*ans*y;
	if(z>=MOD)z%=MOD,bm=true;
	return ans=int(z);
}
signed main(){
//	freopen("eat.in","r",stdin);
//	freopen("eat.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].fi;
	for(int i=1;i<=n;i++)cin>>a[i].se;
	for(int i=1;i<=n;i++){
		if(a[i].fi==1)add1(a[i].se);
		else if(a[i].fi>=a[i].se)mul+=a[i].fi;
		else b[++m]=a[i];
	}
	for(int i:mul)mul1(i);
	std::sort(b+1,b+1+m,[](const pii &x,const pii &y){
		return x.se!=y.se?x.se<y.se:x.fi<y.fi;
	});
	for(int i=1;i<=m;i++){
		if(bm){mul1(b[i].fi);continue;}
		if(ans>=b[i].se)mul1(b[i].fi);
		else add1(b[i].se);
	}
	cout<<ans;
	return 0;
}
// 存不下了，表示肯定是乘法好了，除非是 1
// 必然是先加法再乘法
// a[i]>=b[i] 必然乘法
// 保证 a[i]<=b[i] && a[i]!=1