#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) x.begin(),x.end()
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=1e5+1;
struct sgt{
#define ls (u*2)
#define rs (u*2+1)
#define mid ((l+r)/2)
	struct{loli sum=0,tag=0;}s[kN<<2];
	int data[kN];
	void build(int u,int l,int r){
		if(l==r){s[u].sum=data[l];return;}
		build(ls,l,mid);build(rs,mid+1,r);
		s[u].sum=s[ls].sum+s[rs].sum;
	}
	void pushdown(int u,int l,int r){
		if(!s[u].tag)return;
		s[ls].tag+=s[u].tag,s[rs].tag+=s[u].tag;
		s[ls].sum+=s[u].tag*(mid-l+1);
		s[rs].sum+=s[u].tag*(r-mid);
		s[u].tag=0;
	}
	void updata(int u,int l,int r,int x,int y,int k){
		if(x<=l&&r<=y){s[u].sum+=k*(r-l+1);s[u].tag+=k;return;}
		pushdown(u,l,r);
		if(x<=mid)updata(ls,l,mid,x,y,k);
		if(y>mid)updata(rs,mid+1,r,x,y,k);
		s[u].sum=s[ls].sum+s[rs].sum;
	}
	loli query(int u,int l,int r,int x,int y){
		if(x<=l&&r<=y)return s[u].sum;
		loli k=0;pushdown(u,l,r);
		if(x<=mid)k+=query(ls,l,mid,x,y);
		if(y>mid)k+=query(rs,mid+1,r,x,y);
		return k;
	}
#undef ls
#undef rs
#undef mid
}s;
int n,m;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>s.data[i];
	for(int i=n;i>=1;i--)s.data[i]-=s.data[i-1];
	s.build(1,1,n);
	for(int t,l,r,k,d;m--;){
		cin>>t;
		if(t==1){
			cin>>l>>r>>k>>d;
			s.updata(1,1,n,l,l,k);
			if(l<r)s.updata(1,1,n,l+1,r,d);
			if(r<n)s.updata(1,1,n,r+1,r+1,-k-d*(r-l));
		}else cin>>l,cout<<s.query(1,1,n,1,l)<<'\n';
	}
	return 0;
}