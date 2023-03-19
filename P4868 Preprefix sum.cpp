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
struct _time{~_time(){std::cerr<<"\n\033[33;40m"<<1.*clock()/CLOCKS_PER_SEC<<"s\033[37;40m";}}_TM;
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) std::begin(x),std::end(x)
#define rall(x) std::rbegin(x),std::rend(x)
#define sqrt __builtin_sqrt
#define fi first
#define se second
#define continue(x...) {x;continue;}
#define break(x...) {x;break;}
using std::cin;using std::cout;
using std::max;using std::min;
using std::tie;using std::ignore;
template<typename any>inline void cmin(any&x,const any&y){if(y<x)x=y;}
template<typename any>inline void cmax(any&x,const any&y){if(x<y)x=y;}
template<typename any,typename...args>inline void cmin(any&x,const any&y,const args&...z){cmin(x,y);cmin(x,z...);}
template<typename any,typename...args>inline void cmax(any&x,const any&y,const args&...z){cmax(x,y);cmax(x,z...);}
using loli=long long;
using unt=unsigned;
using lolu=unsigned long long;
using lodb=long double;
using venti=__int128_t;
using pii=std::pair<int,int>;
using tiii=std::tuple<int,int,int>;
using inlsi=const std::initializer_list<int>&;
using bsi=std::basic_string<int>;
using bsl=std::basic_string<loli>;
using bsc=std::string;
using std::operator""s;
#if __cplusplus>=201703L
using bscv=std::string_view;
using std::operator""sv;
#endif
std::mt19937 rng(std::random_device{}());
#define type std::pair<T1,T2>
template<typename T1,typename T2>std::istream&operator>>(std::istream&x,type&y){return x>>y.fi>>y.se;}
template<typename T1,typename T2>std::ostream&operator<<(std::ostream&x,const type&y){return x<<y.fi<<' '<<y.se;}
template<typename T1,typename T2>type operator+(const type&x,const type&y){return{x.fi+y.fi,x.se+y.se};}
template<typename T1,typename T2>type operator+=(type&x,const type&y){x.fi+=y.fi;x.se+=y.se;return x;}
template<typename T1,typename T2>type operator-(const type&x,const type&y){return{x.fi-y.fi,x.se-y.se};}
template<typename T1,typename T2>type operator-=(type&x,const type&y){x.fi-=y.fi;x.se-=y.se;return x;}
#undef type
template<typename any>any get(std::istream&x=cin){any y;x>>y;return y;}
template<typename any>any&STLcls(any &x){any{}.swap(x);return x;}
constexpr venti operator""_vt(lolu x){return venti(x);}
constexpr bool ying=false,yang=true;
constexpr int N=100001;
int n,m;
loli a[N];
int b[N];
struct sgt{
	int tag[N<<1];
	loli sum[N<<1];
#define mid ((l+r)/2)
#define ls (mid*2)
#define rs (mid*2+1)
	void build(int u,int l,int r){
		if(l==r){sum[u]=a[l];return;}
		build(ls,l,mid);build(rs,mid+1,r);
		sum[u]=sum[ls]+sum[rs];
	}
	void mark(int u,int l,int r,int k){
		tag[u]+=k;
		sum[u]+=k*(r-l+1ll);
	}
	void pushdown(int u,int l,int r){
		if(!tag[u])return;
		mark(ls,l,mid,tag[u]);
		mark(rs,mid+1,r,tag[u]);
		tag[u]=0;
	}
	void add(int u,int l,int r,int x,int y,int k){
		if(x<=l&&r<=y)return mark(u,l,r,k);
		pushdown(u,l,r);
		if(x<=mid)add(ls,l,mid,x,y,k);
		if(y>mid)add(rs,mid+1,r,x,y,k);
		sum[u]=sum[ls]+sum[rs];
	}
	loli ask(int u,int l,int r,int x,int y){
		if(x<=l&&r<=y)return sum[u];
		pushdown(u,l,r);
		loli res=0;
		if(x<=mid)res+=ask(ls,l,mid,x,y);
		if(y>mid)res+=ask(rs,mid+1,r,x,y);
		return res;
	}
#undef ls
#undef rs
#undef mid
}sg;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>b[i],a[i]=b[i]+a[i-1];
	sg.build(1,1,n);
	for(int l,r;m--;)switch(get<bsc>().front()){
	case 'M':{
		cin>>l>>r;
		sg.add(1,1,n,l,n,r-b[l]);
		b[l]=r;
	}break;
	case 'Q':{
		cin>>l;
		cout<<sg.ask(1,1,n,1,l)<<'\n';
	}break;
	}
	return 0;
}