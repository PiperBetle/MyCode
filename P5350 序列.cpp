#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#define int long long
using std::cin;using std::cout;
constexpr int MOD=1e9+7;
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
		erase(split(l),split(r+1));
		return emplace(l,r,k).first;
	}
	int query(int l,int r,int sum=0){
		auto ir=split(r+1),il=split(l);
		for(auto it=il;it!=ir;it++)sum+=(it->r-it->l+1)*it->val;
		return sum%MOD;
	}
	void add(int l,int r,int k){
		auto ir=split(r+1),il=split(l);
		for(auto it=il;it!=ir;it++){
			it->val+=k;
			if(it->val>=MOD)it->val-=MOD;
		}
	}
	void copy(int l1,int r1,int l2,int r2){
		int p=l2-l1;
		split(r2+1),split(l2);split(r1+1),split(l1);
		erase(lower_bound(l2),lower_bound(r2+1));
		for(auto it=lower_bound(l1);it->r<=r1;it++)emplace(it->l+p,it->r+p,it->val);
	}
	void swap(int l1,int r1,int l2,int r2){
		int p=l2-l1;
		std::vector<odt_node>t1,t2;
		auto ir=split(r2+1),il=split(l2);
		for(auto it=il;it!=ir;it++)t2.emplace_back(it->l,it->r,it->val);
		ir=split(r1+1),il=split(l1);
		for(auto it=il;it!=ir;it++)t1.emplace_back(it->l,it->r,it->val);
		erase(il,ir);
		for(auto it:t2)emplace(it.l-p,it.r-p,it.val);
		ir=split(r2+1),il=split(l2);
		erase(il,ir);
		for(auto it:t1)emplace(it.l+p,it.r+p,it.val);
	}
	void reverse(int l,int r){
		auto ir=split(r+1),il=split(l);
		std::vector<odt_node>t;
		for(auto it=il;it!=ir;it++)t.emplace_back(it->l-l,it->r-l,it->val);
		erase(il,ir);
		for(auto it:t)emplace(r-it.r,r-it.l,it.val);
	}
}s;
signed main(){
//	freopen(".in","r",stdin);freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int n,m;cin>>n>>m;s.emplace(n+1,n+1,0);
	for(int i=1,t;i<=n;i++)cin>>t,s.emplace(i,i,t);
	while(m--){
		int t,l,r,x,y,k;cin>>t;switch(t){
		case 1:cin>>l>>r;cout<<s.query(l,r)<<'\n';break;
		case 2:cin>>l>>r>>k;s.assign(l,r,k);break;
		case 3:cin>>l>>r>>k;s.add(l,r,k);break;
		case 4:cin>>l>>r>>x>>y;s.copy(l,r,x,y);break;
		case 5:cin>>l>>r>>x>>y;if(l>x)std::swap(l,x),std::swap(r,y);s.swap(l,r,x,y);break;
		case 6:cin>>l>>r;s.reverse(l,r);break;
		}
	}
	for(auto it:s)for(;it.l<=it.r&&it.r<=n;it.l++)cout<<it.val<<' ';
	return 0;
}