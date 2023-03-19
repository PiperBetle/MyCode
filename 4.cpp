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
struct odt_node{
	int l,r;mutable int val;
	odt_node(int a=0,int b=0,int c=0):l(a),r(b),val(c){}
	bool operator<(const odt_node &t)const{return l<t.l;}
};
struct odt:std::set<odt_node>{
	auto split(int p){
		auto it=lower_bound(p);
		if(it!=end()&&it->l==p)return it;
		auto t=*--it;erase(it);emplace(t.l,p-1,t.val);
		return emplace(p,t.r,t.val).first;
	}
	auto assign(int l,int r,int k){
		erase(split(l),split(r+1));
		return emplace(l,r,k).first;
	}
	auto assign(iterator l,iterator r,int k){
		odt_node t(l->l,r->r,k);
		erase(l,++r);
		return emplace(t).first;
	}
	auto merge(int p){
		int t=split(p)->val;
		for(auto it=std::next(split(p));;++it)
			if(it==end()||it->val!=t){assign(split(p),--it,t);break;}
		if(split(p)==begin())return;
		for(auto it=std::prev(split(p));;--it)
			if(it==begin()||it->val!=t){assign(++it,split(p),t);break;}
	}
	auto div(int l,int r,int k){
		for(auto ir=split(r+1),il=split(l);il!=ir;)for(auto jl=std::next(il);;++jl)
			if(jl==ir||il->val/k!=jl->val/k){
				odt_node t(il->l,std::prev(jl)->r,il->val/k);
				erase(il,jl);emplace(t);il=jl;break;
			}
		merge(r+1);merge(l);
	}
	auto sum(int l,int r){
		loli ans=0;
		for(auto ir=split(r+1),il=split(l);il!=ir;++il)ans+=1ll*(il->r-il->l+1)*il->val;
		merge(r+1);merge(l);
		return ans;
	}
}s;
int n,m;
signed main(){
	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;s.emplace(n+1,n+1,0);
	for(int i=1,t;i<=n;i++)cin>>t,s.emplace(i,i,t);
	for(int t,l,r,x;m--;){
		cin>>t>>l>>r;
		switch(t){
		case 1:cin>>x;s.div(l,r,x);break;
		case 2:cin>>x;s.assign(l,r,x);break;
		case 3:cout<<s.sum(l,r)<<'\n';break;
		}
	}
	return 0;
}