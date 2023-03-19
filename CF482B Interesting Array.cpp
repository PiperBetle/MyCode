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
constexpr int N=1e5+1;
struct{int l,r,k;}a[N];
int n,m,sum[N<<2],tag[N<<2];
#define ls (u<<1)
#define rs (u<<1|1)
#define mid ((l+r)>>1)
void spread(int u){
	if(!tag[u])return;
	sum[ls]|=tag[u],sum[rs]|=tag[u];
	tag[ls]|=tag[u],tag[rs]|=tag[u];
	tag[u]=0;
}
void updata(int u,int l,int r,int x,int y,int k){
	if(x<=l&&r<=y){sum[u]|=k;tag[u]|=k;return;}
	spread(u);
	if(x<=mid)updata(ls,l,mid,x,y,k);
	if(y>mid)updata(rs,mid+1,r,x,y,k);
	sum[u]=(sum[ls]&sum[rs]);
}
int query(int u,int l,int r,int x,int y){
	if(x<=l&&r<=y)return sum[u];
	spread(u);int res=(1<<30)-1;
	if(x<=mid)res&=query(ls,l,mid,x,y);
	if(y>mid)res&=query(rs,mid+1,r,x,y);
	return res;
}
void print(int u,int l,int r){
	if(l==r){cout<<sum[u]<<' ';return;}
	spread(u);print(ls,l,mid);print(rs,mid+1,r);
}
#undef ls
#undef rs
#undef mid
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=m;i++)cin>>a[i].l>>a[i].r>>a[i].k,updata(1,1,n,a[i].l,a[i].r,a[i].k);
	for(int i=1;i<=m;i++)if(query(1,1,n,a[i].l,a[i].r)!=a[i].k)return cout<<"NO",0;
	cout<<"YES\n";print(1,1,n);
	return 0;
}