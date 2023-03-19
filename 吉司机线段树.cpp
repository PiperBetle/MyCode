#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
using std::cin;using std::cout;
using loli=long long;
using uloli=unsigned long long;
using lodb=long double;
using venti=__int128_t;
using pii=std::pair<int,int>;
using inlsi=const std::initializer_list<int>&;
constexpr venti operator""_vt(uloli x){return venti(x);}
constexpr int N=1e6+1,inf=0x3f3f3f3f;
int n,m,a[N],T,tag[N],cnt[N];
pii mn[N];
loli sum[N];
#define ls (u<<1)
#define rs (u<<1|1)
#define mid ((l+r)>>1)
void push_up(int u){
	sum[u]=sum[ls]+sum[rs];
	if(mn[ls].fi==mn[rs].fi){
		mn[u].fi=mn[ls].fi;
		cnt[u]=cnt[ls]+cnt[rs];
		mn[u].se=std::min(mn[ls].se,mn[rs].se);
	}else if(mn[ls]<mn[rs]){
		mn[u].fi=mn[ls].fi;
		cnt[u]=cnt[ls];
		mn[u].se=std::min(mn[ls].se,mn[rs].fi);
	}else{
		mn[u].fi=mn[rs].fi;
		cnt[u]=cnt[rs];
		mn[u].se=std::min(mn[ls].fi,mn[rs].se);
	}
}
void push_tag(int u,int k){
	if(mn[u].fi>=k)return;
	sum[u]+=1ll*(k-mn[u].fi)*cnt[u];
	mn[u].fi=tag[u]=k;
}
void push_down(int u){
	if(tag[u]==inf)return;
	push_tag(ls,tag[u]);push_tag(rs,tag[u]);
	tag[u]=inf;
}
void build(int u,int l,int r){
	tag[u]=inf;
	if(l==r){sum[u]=mn[u].fi=a[l];mn[u].se=inf;cnt[u]=1;return;}
	build(ls,l,mid);build(rs,mid+1,r);
	push_up(u);
}
void updata(int u,int l,int r,int x,int y,int k){
	if(mn[u].fi>=k)return;
	if(x<=l&&r<=y&&mn[u].se>k)return push_tag(u,k);
	push_down(u);
	if(x<=mid)updata(ls,l,mid,x,y,k);
	if(y>mid)updata(rs,mid+1,r,x,y,k);
	push_up(u);
}
loli query(int u,int l,int r,int x,int y){
	if(x<=l&&r<=y)return sum[u];
	loli res=0;
	if(x<=mid)res+=query(ls,l,mid,x,y);
	if(y>mid)res+=query(rs,mid+1,r,x,y);
	return res;
}
#undef ls
#undef rs
#undef mid
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	build(1,1,n);
	for(int l,r,k;m--;){
		cin>>k;
		if(k==1){
			cin>>l>>r>>k;
			updata(1,1,n,l,r,k);
		}else{
			cin>>l>>r;
			cout<<query(1,1,n,l,r)<<'\n';
		}
		for(int j=1;j<=n;j++)cout<<query(1,1,n,j,j)<<' ';
		cout<<'\n';
	}
	return 0;
}