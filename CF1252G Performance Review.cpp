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
constexpr int N=1e5+1;
int n,m,q,a[N],sum[N];
bsi b[N];
#define ls (u<<1)
#define rs (u<<1|1)
#define mid ((l+r)>>1)
int m_n[N<<2],tag[N<<2];
void pushup(int u){
	m_n[u]=min(m_n[ls],m_n[rs]);
}
void pushdown(int u){
	if(!tag[u])return;
	m_n[ls]+=tag[u];tag[ls]+=tag[u];
	m_n[rs]+=tag[u];tag[rs]+=tag[u];
	tag[u]=0;
}
void build(int u,int l,int r){
	if(l==r)return m_n[u]=sum[l],void();
	build(ls,l,mid);build(rs,mid+1,r);
	pushup(u);
}
void updata(int u,int l,int r,int x,int y,int k){
	if(x<=l&&r<=y)return m_n[u]+=k,tag[u]+=k,void();
	pushdown(u);
	if(x<=mid)updata(ls,l,mid,x,y,k);
	if(y>mid)updata(rs,mid+1,r,x,y,k);
	pushup(u);
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[1])sum[0]++;
	}
	for(int i=1,k=0,l;i<=m;i++){
		cin>>l;b[i].resize(l);
		sum[i]=sum[i-1]+k-l;k=0;
		for(int&j:b[i]){
			cin>>j;
			if(j<a[1])k++;
		}
	}
	build(1,1,m);
	for(int x,y,z;q--;){
		cin>>x>>y>>z;y--;
		if(x!=m&&b[x][y]>a[1]&&z<a[1])updata(1,1,m,x+1,m,+1);
		if(x!=m&&b[x][y]<a[1]&&z>a[1])updata(1,1,m,x+1,m,-1);
		b[x][y]=z;
		cout<<(m_n[1]>=0)<<'\n';
	}
	return 0;
}