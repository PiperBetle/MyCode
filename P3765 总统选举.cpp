#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<tuple>
#include<ext/pb_ds/assoc_container.hpp>
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
namespace pbds=__gnu_pbds;
constexpr int N=5e5+1;
struct:pbds::tree<int,pbds::null_type,std::less<>,pbds::rb_tree_tag,pbds::tree_order_statistics_node_update>{
	int count(int l,int r)const{return order_of_key(r+1)-order_of_key(l);}
}b[N];
int n,m,a[N];
pii s[N<<2];
#define ls (u<<1)
#define rs (u<<1|1)
#define mid ((l+r)>>1)
pii operator+(const pii &x,const pii &y){
	if(x.fi==y.fi)return {x.fi,x.se+y.se};
	if(x.se>y.se)return {x.fi,x.se-y.se};
	if(x.se<y.se)return {y.fi,y.se-x.se};
	return {0,0};
}
void build(int u,int l,int r){
	if(l==r){s[u]={a[l],1};return;}
	build(ls,l,mid);build(rs,mid+1,r);
	s[u]=s[ls]+s[rs];
}
void updata(int u,int l,int r,int x,int k){
	if(l==r){s[u]={k,1};return;}
	x<=mid?updata(ls,l,mid,x,k):updata(rs,mid+1,r,x,k);
	s[u]=s[ls]+s[rs];
}
pii query(int u,int l,int r,int x,int y){
	if(x<=l&&r<=y)return s[u];
	if(y<=mid)return query(ls,l,mid,x,y);
	if(x>mid)return query(rs,mid+1,r,x,y);
	return query(ls,l,mid,x,y)+query(rs,mid+1,r,x,y);
}
void updata(int x,int k){
	if(a[x]==k)return;
	b[a[x]].erase(x);
	b[a[x]=k].insert(x);
	updata(1,1,n,x,k);
}
#undef ls
#undef rs
#undef mid
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],b[a[i]].insert(i);
	build(1,1,n);
	for(int l,r,s,k;m--;){
		cin>>l>>r>>s>>k;
		int x=query(1,1,n,l,r).fi;
		if(b[x].count(l,r)>(r-l+1)/2)s=x;
		cout<<s<<'\n';
		while(k--)cin>>l,updata(l,s);
	}
	int x=s[1].fi;
	cout<<(b[x].count(1,n)>n/2?x:-1);
	return 0;
}