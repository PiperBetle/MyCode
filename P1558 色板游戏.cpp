#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<set>
using std::cin;using std::cout;
struct odt_node{
	int l,r;mutable int val;
	odt_node(int a=0,int b=0,int c=0):l(a),r(b),val(c){}
	bool operator<(const odt_node &t)const{return l<t.l;}
};
struct odt_tree:std::set<odt_node>{
	bool c[31];
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
	int query(int l,int r){
		memset(c,0,sizeof c);
		for(auto ir=split(r+1),il=split(l);il!=ir;il++)c[il->val]=true;
		return (int)std::count(std::begin(c),std::end(c),true);
	}
}s;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int n,T,l,r,c;char t;cin>>n>>T>>T;
	s.emplace(1,n,1),s.emplace(n+1,n+1,0);
	while(T--)switch(cin>>t>>l>>r;t){
	case 'C':cin>>c;s.assign(std::min(l,r),std::max(l,r),c);break;
	case 'P':cout<<s.query(std::min(l,r),std::max(l,r))<<'\n';break;
	}
	return 0;
}