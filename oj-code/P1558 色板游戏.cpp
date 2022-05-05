#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
using std::cin;using std::cout;
template<typename any>struct odt{
	struct odt_node{
		int l,r;mutable any data;
		odt_node(int _l,int _r=-1,any _data=0):l(_l),r(_r),data(_data){}
		bool operator<(const odt_node &t)const{return l<t.l;}
	};
	std::set<odt_node>s;
	auto insert(int _l,int _r,any _data){return s.insert(odt_node(_l,_r,_data));}
	auto begin(){return s.begin();}
	auto end(){return s.end();}
	auto split(int pos){
		auto it=s.lower_bound(pos);
		if(it!=s.end()&&it->l==pos)return it;
		it--;int l=it->l,r=it->r;any k=it->data;
		s.erase(it);s.insert(odt_node(l,pos-1,k));
		return s.insert(odt_node(pos,r,k)).first;
	}
	auto assign(int l,int r,any k){
		auto it_r=split(r+1),it_l=split(l);
		s.erase(it_l,it_r);
		return s.insert(odt_node(l,r,k));
	}
	int query(int l,int r,int ans=0){
		auto it_r=split(r+1),it_l=split(l);bool c[31]={};
		for(auto it=it_l;it!=it_r;it++)c[it->data]=true;
		for(int i=1;i<=30;i++)ans+=c[i];
		return ans;
	}
};
odt<int>s;
signed main(){
//	freopen(".in","r",stdin);freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int n,T,l,r,c;char t;cin>>n>>T>>T;
	s.insert(1,n,1),s.insert(n+1,n+1,0);
	while(T--){
		switch(cin>>t>>l>>r;t){
		case 'C':cin>>c;s.assign(std::min(l,r),std::max(l,r),c);break;
		case 'P':cout<<s.query(std::min(l,r),std::max(l,r))<<'\n';break;
		}
	}
	return 0;
}