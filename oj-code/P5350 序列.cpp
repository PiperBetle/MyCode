#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#define int long long
using std::cin;using std::cout;
constexpr int MOD=1e9+7;
template<typename any>struct odt{
	struct odt_node{
		int l,r;mutable any data;
		odt_node(int _l,int _r=-1,any _data=0):l(_l),r(_r),data(_data){}
		bool operator<(const odt_node &t)const{return l<t.l;}
	};
	std::set<odt_node>s;
	auto begin(){return s.begin();}
	auto end(){return s.end();}
	auto split(int pos){
		auto it=s.lower_bound(pos);
		if(it!=s.end()&&it->l==pos)return it;
		it--;int l=it->l,r=it->r;any k=it->data;
		s.erase(it);s.emplace(l,pos-1,k);
		return s.emplace(pos,r,k).first;
	}
	auto assign(int l,int r,any k){
		auto it_r=split(r+1),it_l=split(l);
		s.erase(it_l,it_r);
		return s.emplace(l,r,k).first;
	}
	any query(int l,int r,any sum=0){
		auto it_r=split(r+1),it_l=split(l);
		for(auto it=it_l;it!=it_r;it++)sum+=(it->r-it->l+1)*it->data;
		return sum%MOD;
	}
	void add(int l,int r,any k){
		auto it_r=split(r+1),it_l=split(l);
		for(auto it=it_l;it!=it_r;it++){
			it->data+=k;
			if(it->data>=MOD)it->data-=MOD;
		}
	}
	void copy(int l1,int r1,int l2,int r2){
		int p=l2-l1;
		split(r2+1),split(l2);split(r1+1),split(l1);
		s.erase(s.lower_bound(l2),s.lower_bound(r2+1));
		for(auto it=s.lower_bound(l1);it->r<=r1;it++)s.emplace(it->l+p,it->r+p,it->data);
	}
	void swap(int l1,int r1,int l2,int r2){
		int p=l2-l1;
		std::vector<odt_node>t1,t2;
		auto it_r=split(r2+1),it_l=split(l2);
		for(auto it=it_l;it!=it_r;it++)t2.emplace_back(it->l,it->r,it->data);
		it_r=split(r1+1),it_l=split(l1);
		for(auto it=it_l;it!=it_r;it++)t1.emplace_back(it->l,it->r,it->data);
		s.erase(it_l,it_r);
		for(auto it:t2)s.emplace(it.l-p,it.r-p,it.data);
		it_r=split(r2+1),it_l=split(l2);
		s.erase(it_l,it_r);
		for(auto it:t1)s.emplace(it.l+p,it.r+p,it.data);
	}
	void reverse(int l,int r){
		auto it_r=split(r+1),it_l=split(l);
		std::vector<odt_node>t;
		for(auto it=it_l;it!=it_r;it++)t.emplace_back(it->l-l,it->r-l,it->data);
		s.erase(it_l,it_r);
		for(auto it:t)s.emplace(r-it.r,r-it.l,it.data);
	}
};
odt<int>s;
signed main(){
//	freopen(".in","r",stdin);freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int n,m;cin>>n>>m;s.s.emplace(n+1,n+1,0);
	for(int i=1,t;i<=n;i++)cin>>t,s.s.emplace(i,i,t);
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
	for(auto it:s)for(;it.l<=it.r&&it.r<=n;it.l++)cout<<it.data<<' ';
	return 0;
}