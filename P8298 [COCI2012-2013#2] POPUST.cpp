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
constexpr int N=5e5+2,inf=0x3f3f3f3f;
int n,sum[N],mna[N],mnc[N];
pii a[N];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].fi>>a[i].se;
	std::sort(a+1,a+1+n,[](const pii &x,const pii &y){return x.se<y.se;});
	mna[n+1]=mnc[0]=inf;
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i].se,mnc[i]=min(mnc[i-1],a[i].fi-a[i].se);
	for(int i=n;i>=1;i--)mna[i]=min(mna[i+1],a[i].fi);
	for(int i=1;i<=n;i++)cout<<min(sum[i-1]+mna[i],sum[i]+mnc[i])<<'\n';
	return 0;
}