//不向焦虑与抑郁投降，这个世界终会有我们存在的地方。
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<tuple>
#define int loli
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
int n,m,p,ans=1;
pii a[N],b[N];
signed main(){
//	freopen("eat.in","r",stdin);
//	freopen("eat.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].fi;
	for(int i=1;i<=n;i++)cin>>a[i].se;
	for(int i=1;i<=n;i++)
		if(a[i].fi==1)ans+=a[i].se;
		else b[++m]=a[i];
	p=int(std::max_element(b+1,b+1+m,[](const pii &x,const pii &y){
		return 1.l*(ans+x.se)/(ans*x.fi)<1.l*(ans+y.se)/(ans*y.fi);
	})-b);
	if(!m)return cout<<ans,0;
	if(b[p].se>=ans*b[p].fi)(ans+=b[p].se)%=MOD;else p=0;
	for(int i=1;i<=m;i++)if(i!=p)(ans*=b[i].fi)%=MOD;
	cout<<ans;
	return 0;
}