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
constexpr int N=3e5+1;
int n,m,sum[N<<2],tag[N<<2];
pii a[N];
bsc s1,s2;
#define ls (u<<1)
#define rs (u<<1|1)
#define mid ((l+r)/2)
void pushup(int u){sum[u]=sum[ls]+sum[rs];}
void mark(int u,int l,int r,int k){tag[u]=k;sum[u]=k*(r-l+1);}
void pushdown(int u,int l,int r){
	if(tag[u]==-1)return;
	mark(ls,l,mid,tag[u]);mark(rs,mid+1,r,tag[u]);
	tag[u]=-1;
}
void build(int u,int l,int r){
	tag[u]=-1;
	if(l==r){sum[u]=s2[l]=='1';return;}
	build(ls,l,mid);build(rs,mid+1,r);
	pushup(u);
}
void assign(int u,int l,int r,int x,int y,int k){
	if(x<=l&&r<=y)return mark(u,l,r,k);
	pushdown(u,l,r);
	if(x<=mid)assign(ls,l,mid,x,y,k);
	if(y>mid)assign(rs,mid+1,r,x,y,k);
	pushup(u);
}
int query(int u,int l,int r,int x,int y){
	if(x<=l&&r<=y)return sum[u];
	pushdown(u,l,r);
	int k=0;
	if(x<=mid)k+=query(ls,l,mid,x,y);
	if(y>mid)k+=query(rs,mid+1,r,x,y);
	return k;
}
bool check(int u,int l,int r){
	if(l==r)return sum[u]==(s1[l]=='1');
	pushdown(u,l,r);
	return check(ls,l,mid)&&check(rs,mid+1,r);
}
#undef ls
#undef rs
#undef mid
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--)cout<<([]{
		cin>>n>>m>>s1>>s2;s1=' '+s1;s2=' '+s2;
		for(int i=1;i<=m;i++)cin>>a[i].fi>>a[i].se;
		build(1,1,n);
		for(int i=m;i>=1;i--){
			int k1=query(1,1,n,a[i].fi,a[i].se),k2=a[i].se-a[i].fi+1;
			if(k1*2==k2)return false;
			assign(1,1,n,a[i].fi,a[i].se,k1*2>k2);
		}
		return check(1,1,n);
	}()?"YES\n":"NO\n");
	return 0;
}