#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<set>
#define siz(x) int((x).size())
#define cauto const auto
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=5e5+1;
int n,m,a[kN];
struct odt_node{
	int l,r;mutable int val;
	odt_node(int _a=0,int _b=0,int _c=0):l(_a),r(_b),val(_c){}
	bool operator<(const odt_node &t)const{return l<t.l;}
};
struct odt:std::set<odt_node>{
	struct sgt{
		struct{int li,ri;loli sum,tag;int num(){return ri-li+1;}}s[kN<<2];
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
		auto add(int now,int l,int r,loli k){
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
	auto build(int r){sg.build(1,1,r);}
	auto split(int p){
		auto it=lower_bound(p);
		if(it!=end()&&it->l==p)return it;
		auto t=*--it;erase(it);emplace(t.l,p-1,t.val);
		return emplace(p,t.r,t.val).first;
	}
	auto assign(int l,int r,int k){
		for(auto ir=split(r+1),il=split(l);il!=ir;++il)
			sg.add(1,il->l,il->r,k-il->val);
		erase(split(l),split(r+1));
		emplace(l,r,k);
	}
	auto div(int l,int r,int k){
		for(auto ir=split(r+1),il=split(l);il!=ir;++il)
			sg.add(1,il->l,il->r,il->val/k-il->val);
		for(auto ir=split(r+1),il=split(l);il!=ir;)for(auto jl=std::next(il);;++jl)
			if(jl==ir||il->val/k!=jl->val/k){
				odt_node t(il->l,std::prev(jl)->r,il->val/k);
				erase(il,jl);emplace(t);il=jl;break;
			}
	}
	auto query(int l,int r){return sg.query(1,l,r);}
}s;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;s.emplace(n+1,n+1,0);
	for(int i=1;i<=n;i++)cin>>a[i],s.emplace(i,i,a[i]);
	s.build(n);
	for(int t,l,r,x;m--;){
		cin>>t>>l>>r;
		switch(t){
		case 1:cin>>x;s.div(l,r,x);break;
		case 2:cin>>x;s.assign(l,r,x);break;
		case 3:cout<<s.query(l,r)<<'\n';break;
		}
	}
	return 0;
}