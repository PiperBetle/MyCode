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
constexpr int kN=100001;
int n,m;
struct sgt{
	// int a[kN];
	// std::array<int,kN>a;
	std::basic_string<int>a;
	// struct tree{int li,ri;loli sum,tag;int num(){return ri-li+1;}}s[kN<<2];
	struct tree{int li,ri;loli sum,tag;int num(){return ri-li+1;}};
	std::basic_string<tree>s;
	// std::array<tree,kN<<2>s;
	sgt(){a.resize(kN);s.resize(kN<<2);}
#define ls (now*2)
#define rs (now*2+1)
#define mid ((s[now].li+s[now].ri)/2)
	auto build(int now,int l,int r){
		s[now].tag=0;s[now].li=l;s[now].ri=r;
		if(l==r){s[now].sum=a[l];return;}
		build(ls,l,mid);build(rs,mid+1,r);
		s[now].sum=s[ls].sum+s[rs].sum;
	}
	auto spread(int now){
		if(!s[now].tag)return;
		s[ls].sum+=s[now].tag*s[ls].num();
		s[rs].sum+=s[now].tag*s[rs].num();
		s[ls].tag+=s[now].tag;s[rs].tag+=s[now].tag;
		s[now].tag=0;
	}
	auto add(int now,int l,int r,int k){
		if(l<=s[now].li&&s[now].ri<=r){s[now].sum+=k*s[now].num(),s[now].tag+=k;return;}
		spread(now);
		if(l<=mid)add(ls,l,r,k);
		if(r>mid)add(rs,l,r,k);
		s[now].sum=s[ls].sum+s[rs].sum;
	}
	auto query(int now,int l,int r,loli sum=0){
		if(l<=s[now].li&&s[now].ri<=r)return s[now].sum;
		spread(now);
		if(l<=mid)sum+=query(ls,l,r);
		if(r>mid)sum+=query(rs,l,r);
		return sum;
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
		if(t==1)cin>>t,sg.add(1,x,y,t);
		else cout<<sg.query(1,x,y)<<'\n';
	}
	return 0;
}