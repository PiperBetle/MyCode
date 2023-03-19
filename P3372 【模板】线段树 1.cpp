#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
#define cauto const auto
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int N=1e5+1;
int n,m;
struct sgt{
	int a[N<<1],tag[N<<1];
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
	for(int i=1;i<=n;i++)cin>>sg.a[i];
	sg.build(1,1,n);
	for(int t,x,y;m--;){
		cin>>t>>x>>y;
		if(t==1)cin>>t,sg.add(1,1,n,x,y,t);
		else cout<<sg.ask(1,1,n,x,y)<<'\n';
	}
	return 0;
}