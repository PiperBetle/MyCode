//不向焦虑与抑郁投降，这个世界终会有我们存在的地方。
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<tuple>
#include<ctime>
#include<random>
#include<list>
#if __cplusplus>=202002L
#include<ranges>
namespace vw=std::views;
#endif
#define siz(x) int((x).size())
struct _time{~_time(){std::cerr<<"\n\033[33;40m"<<1.*clock()/CLOCKS_PER_SEC<<"s\033[37;40m";}}_TM;
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
template<typename any,typename...args>inline void cmin(any &x,const any &y,const args &...z){cmin(x,y);cmin(x,z...);}
template<typename any,typename...args>inline void cmax(any &x,const any &y,const args &...z){cmax(x,y);cmax(x,z...);}
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
std::mt19937 rng(std::random_device{}());
constexpr venti operator""_vt(uloli x){return venti(x);}
constexpr bool ying=false,yang=true;
struct node{
	int sum,lmx,rmx,ans;
	node &operator=(bool x){
		if(x) sum=lmx=rmx=ans=1;
		else sum=-1,lmx=rmx=ans=0;
		return *this;
	}
	friend node operator+(const node &x,const node &y){
		return {x.sum+y.sum,max(x.lmx,x.sum+y.lmx),max(y.rmx,x.rmx+y.sum),max({x.ans,y.ans,x.rmx+y.lmx})};
	}
};
constexpr int N=1e6+1;
node s[N<<2];
int n,m,ans;
bool a[N];
char c;
#define ls (u<<1)
#define rs (u<<1|1)
#define mid ((l+r)>>1)
void build(int u,int l,int r){
	if(l==r)return s[u]=a[l],void();
	build(ls,l,mid);build(rs,mid+1,r);
	s[u]=s[ls]+s[rs];
}
void updata(int u,int l,int r,int x,bool k){
	if(l==r)return s[u]=k,void();
	x<=mid?updata(ls,l,mid,x,k):updata(rs,mid+1,r,x,k);
	s[u]=s[ls]+s[rs];
}
node query(int u,int l,int r,int x,int y){
	if(x<=l&&r<=y)return s[u];
	if(y<=mid)return query(ls,l,mid,x,y);
	if(x>mid)return query(rs,mid+1,r,x,y);
	return query(ls,l,mid,x,y)+query(rs,mid+1,r,x,y);
}
#undef ls
#undef rs
#undef mid
signed main(){
//	freopen("hypercube.in","r",stdin);
//	freopen("hypercube.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>c,a[i]=(c=='1');
	build(1,1,n);
	for(int x,y;m--;){
		cin>>x>>y;
		node res=query(1,1,n,x,y);
		ans^=((res.ans?:1)-res.sum);
	}
	cout<<ans;
	return 0;
}