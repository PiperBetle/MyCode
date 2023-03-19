#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<set>
using std::cin;using std::cout;
int n,m,ans;
struct odt_node{
	int l,r;mutable int val;
	odt_node(int a=0,int b=0,int c=0):l(a),r(b),val(c){}
	bool operator<(const odt_node &t)const{return l<t.l;}
};
struct odt_tree:std::set<odt_node>{
	auto split(int p){
		auto it=lower_bound(p);
		if(it!=end()&&it->l==p)return it;
		auto t=*--it;erase(it);emplace(t.l,p-1,t.val);
		return emplace(p,t.r,t.val).first; 
	}
	auto assign(int l,int r,int k){
		auto ir=split(r+1),il=split(l);
		for(auto it=il;it!=ir;)ans+=(k-it->val)*(it->r-it->l+1),it=erase(it);
		return emplace(l,r,k).first;
	}
}s;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;ans=n;s.emplace(1,n,1);s.emplace(n+1,n+1,0);
	for(int l,r,t;m--;)cin>>l>>r>>t,s.assign(l,r,t-1),cout<<ans<<'\n';
	return 0;
}