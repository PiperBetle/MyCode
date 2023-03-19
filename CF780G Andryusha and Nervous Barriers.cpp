#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<queue>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int N=100001,MOD=1e9+7;
inline int add0(int _x,int _y){return (_x+=_y)<MOD?_x:_x-MOD;}
inline int&add1(int&_x,int _y){return (_x+=_y)<MOD?_x:_x-=MOD;}
int h,w,n;
int s[4*N];
std::priority_queue<pii,std::vector<pii>,std::greater<>>q[4*N];
struct ban{int u,l,r,s;friend bool operator<(const ban &x,const ban &y){return x.u>y.u;}}a[N];
#define ls (u<<1)
#define rs (u<<1|1)
#define mid ((l+r)>>1)
inline void pushup(int u){s[u]=std::min(s[ls],s[rs]);}
inline void build(int u,int l,int r){
	if(l==r){q[u].emplace(s[u]=h+1,1);return;}
	build(ls,l,mid);build(rs,mid+1,r);pushup(u);
}
inline void updata(int u,int l,int r,int x,int h,int v){
	if(l==r){q[u].emplace(h,v);s[u]=q[u].top().fi;return;}
	x<=mid?updata(ls,l,mid,x,h,v):updata(rs,mid+1,r,x,h,v);pushup(u);
}
inline int query(int u,int l,int r,int x,int y,int k){
	if(s[u]>k)return 0;
	int ans=0;
	if(l==r){
		for(;!q[u].empty()&&q[u].top().fi<=k;q[u].pop())add1(ans,q[u].top().se);
		s[u]=(q[u].empty()?MOD:q[u].top().fi);
	}else{
		if(x<=mid)add1(ans,query(ls,l,mid,x,y,k));
		if(y>mid)add1(ans,query(rs,mid+1,r,x,y,k));
		pushup(u);
	}
	return ans;
}
#undef ls
#undef rs
#undef mid
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>h>>w>>n;
	for(int i=1;i<=n;i++)cin>>a[i].u>>a[i].l>>a[i].r>>a[i].s;
	std::sort(a+1,a+1+n);build(1,1,w);
	for(int i=1,v;i<=n;i++){
		v=query(1,1,w,a[i].l,a[i].r,std::min(h+1,a[i].u+a[i].s));
		if(a[i].l==1)updata(1,1,w,a[i].r+1,a[i].u,add0(v,v));
		else if(a[i].r==w)updata(1,1,w,a[i].l-1,a[i].u,add0(v,v));
		else updata(1,1,w,a[i].l-1,a[i].u,v),updata(1,1,w,a[i].r+1,a[i].u,v);
	}
	cout<<query(1,1,w,1,w,MOD);
	return 0;
}