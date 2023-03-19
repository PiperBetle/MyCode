#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<array>
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
constexpr int N=5e4+1;
int n,q,a[N];
struct LineBase{
	int a[30];
	int &operator[](int x){return a[x];}
	int operator[](int x)const{return a[x];}
	auto &operator+=(int x){for(int i=std::__lg(x);x;i=std::__lg(x^=a[i]))if(!a[i])return a[i]=x,*this;return *this;}
	auto clear(){memset(a,0,sizeof a);}
	auto &operator=(int x){clear();return *this+=x;}
	friend auto operator+(LineBase x,const LineBase &y){for(int i=29;~i;i--)if(y[i])x+=y[i];return x;}
	auto max(int res=0){for(int i=29;i>=0;i--)res=std::max(res,res^a[i]);return res;}
}lb[N<<2];
struct BIT{
	int data[N];
	void add(int x,int k=1){for(;x<=n;x+=x&-x)data[x]^=k;}
	int query(int x){int k=0;for(;x;x-=x&-x)k^=data[x];return k;}
}tr;
#define ls (u<<1)
#define rs (u<<1|1)
#define mid ((l+r)>>1)
void build(int u,int l,int r){
	if(l==r){lb[u]+=a[l];return;}
	build(ls,l,mid);build(rs,mid+1,r);
	lb[u]=lb[ls]+lb[rs];
}
void updata(int u,int l,int r,int x,int k){
	if(l==r){lb[u]=k;return;}
	x<=mid?updata(ls,l,mid,x,k):updata(rs,mid+1,r,x,k);
	lb[u]=lb[ls]+lb[rs];
}
auto query(int u,int l,int r,int x,int y){
	if(x<=l&&r<=y)return lb[u];
	if(y<=mid)return query(ls,l,mid,x,y);
	if(x>mid)return query(rs,mid+1,r,x,y);
	return query(ls,l,mid,x,y)+query(rs,mid+1,r,x,y);
}
#undef ls
#undef rs
#undef mid
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n;i>=1;i--)a[i]^=a[i-1];
	build(1,1,n);for(int i=1;i<=n;i++)tr.add(i,a[i]);
	for(int t,l,r,x;q--;){
		cin>>t;
		if(t==1){
			cin>>l>>r>>x;
			tr.add(l,x),updata(1,1,n,l,a[l]^=x);
			if(r<n)tr.add(r+1,x),updata(1,1,n,r+1,a[r+1]^=x);
		}else{
			cin>>l>>r>>x;
			if(int k=tr.query(l);l==r)cout<<std::max(x,k^x)<<'\n';
			else cout<<(query(1,1,n,l+1,r)+=k).max(x)<<'\n';
		}
	}
	return 0;
}