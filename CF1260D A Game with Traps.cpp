//不向焦虑与抑郁投降，这个世界终会有我们存在的地方。
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<tuple>
#include<ctime>
#include<random>
#if __cplusplus>=202002L
#include<ranges>
namespace vw=std::views;
#endif
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) std::begin(x),std::end(x)
#define rall(x) std::rbegin(x),std::rend(x)
#define sqrt __builtin_sqrt
#define fi first
#define se second
#define continue(x) {x;continue;}
#define break(x) {x;break;}
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
using tiii=std::tuple<int,int,int>;
using inlsi=const std::initializer_list<int>&;
using bsi=std::basic_string<int>;
using bsc=std::string;
using std::operator""s;
#if __cplusplus>=201703L
using bscv=std::string_view;
using std::operator""sv;
#endif
struct _time{~_time(){std::cerr<<"\n\033[33;40m"<<1.*clock()/CLOCKS_PER_SEC<<"s\033[37;40m";}}_TM;
std::mt19937 rng(std::random_device{}());
constexpr venti operator""_vt(uloli x){return venti(x);}
constexpr bool ying=false,yang=true;
constexpr int N=2e5+1;
int n,m,k,t,a[N],c[N],ans;
struct{int l,r,d;}b[N];
bool check(int x){
	for(int i=1;i<=k;i++)if(b[i].d>a[x])
		c[b[i].l]++,c[b[i].r+1]--;
	for(int i=1;i<=n+1;i++)c[i]+=c[i-1];
	int res=n+1;
	for(int i=1;i<=n+1;i++)
		if(c[i]>0)res+=2,c[i]=0;
	return res<=t;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>m>>n>>k>>t;a[0]=0x3f3f3f3f;
	for(int i=1;i<=m;i++)cin>>a[i];
	std::sort(a+1,a+1+m,std::greater<>());
	for(int i=1;i<=k;i++)cin>>b[i].l>>b[i].r>>b[i].d;
	for(int l=0,r=m,mid;l<=r;)
		if(check(mid=(l+r)/2))ans=mid,l=mid+1;
		else r=mid-1;
	cout<<ans;
	return 0;
}