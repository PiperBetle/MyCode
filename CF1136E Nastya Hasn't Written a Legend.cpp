//不向焦虑与抑郁投降，这个世界终会有我们存在的地方。
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<tuple>
#include<ctime>
#include<random>
#include<set>
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
constexpr int N=1e5+1;
int n,q,a[N];
loli b[N];
char c;
struct odt_node{
	int l,r;mutable loli val;
	odt_node(int _a=0,int _b=0,loli _c=0):l(_a),r(_b),val(_c){}
	bool operator<(const odt_node &t)const{return l<t.l;}
};
struct:std::set<odt_node>{
	loli tag[N<<2],sum[N<<2];
#define ls (u<<1)
#define rs (u<<1|1)
#define mid ((l+r)>>1)
	void build(int u,int l,int r){
		if(l==r){sum[u]=a[l];return;}
		build(ls,l,mid);build(rs,mid+1,r);
		sum[u]=sum[ls]+sum[rs];
	}
	void mark(int u,int l,int r,loli k){
		tag[u]+=k;
		sum[u]+=k*(r-l+1);
	}
	void pushdown(int u,int l,int r){
		if(!tag[u])return;
		mark(ls,l,mid,tag[u]);
		mark(rs,mid+1,r,tag[u]);
		tag[u]=0;
	}
	void add(int u,int l,int r,int x,int y,loli k){
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
	auto split(int p){
		auto it=lower_bound(p);
		if(it!=end()&&it->l==p)return it;
		auto t=*--it;erase(it);emplace(t.l,p-1,t.val);
		return emplace(p,t.r,t.val+b[p]-b[t.l]).first; 
	}
	auto assign(int l,int r,loli k){
		erase(split(l),split(r+1));
		return emplace(l,r,k).first;
	}
	auto updata(int p,int k){
		auto il=split(p),it=il;
		int r=it->r;loli val=it->val;
		for(;it!=end();++it){
			if(val+k+b[it->l]-b[p]<=it->val)break;
			r=it->r;add(1,1,n,it->l,r,val+k+b[it->l]-b[p]-it->val);
		}
		erase(il,it);emplace(p,r,val+k);
	}
}s;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=2;i<=n;i++)cin>>b[i],b[i]+=b[i-1];
	s.build(1,1,n);
	for(int i=1;i<=n;i++)s.emplace(i,i,a[i]);
	cin>>q;
	for(int l,r;q--;)switch(cin>>c,c){
	case '+':cin>>l>>r;s.updata(l,r);break;
	case 's':cin>>l>>r;cout<<s.ask(1,1,n,l,r)<<'\n';break;
	}
	return 0;
}