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
constexpr int N=3e5+1;
int n,m,a[N],ans1,ans2;
struct{
	int tag[N<<2],sum[N<<2];
#define ls (u*2)
#define rs (u*2+1)
#define mid ((l+r)/2)
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
	int ask(int u,int l,int r,int x,int y){
		if(x<=l&&r<=y)return sum[u];
		pushdown(u,l,r);
		int res=0;
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
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n;i>=1;i--)a[i]-=a[i-1];
	sg.build(1,1,n);
	for(int i=n;i>m;i--){
		int w=sg.ask(1,1,n,1,i);
		if(w<=0)continue;
		sg.add(1,1,n,i-m+1,i,-(w+m-1)/m);
		ans1+=(w+m-1)/m;
	}
	for(int i=1;i<=m;i++){
		int w=sg.ask(1,1,n,1,i);
		cmax(ans2,(w+i-1)/i);
	}
	cout<<ans1+ans2;
	return 0;
}