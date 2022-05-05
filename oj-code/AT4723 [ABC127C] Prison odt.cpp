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
	void insert(int _l,int _r,any _data){s.insert(odt_node(_l,_r,_data));}
	auto begin(){return s.begin();}
	auto end(){return s.end();}
	auto split(int pos){
		auto it=s.lower_bound(pos);
		if(it!=s.end()&&it->l==pos)return it;
		it--;int l=it->l,r=it->r;any k=it->data;
		s.erase(it);s.insert(odt_node(l,pos-1,k));
		return s.insert(odt_node(pos,r,k)).first;
	}
	void assign(int l,int r,any k){
		auto it_r=split(r+1),it_l=split(l);
		s.erase(it_l,it_r);
		s.insert(odt_node(l,r,k));
	}
};
odt<int>s;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int n,m,ans=0;cin>>n>>m;
	s.insert(1,n,1);
	s.insert(n+1,n+1,0);
	for(int i=1,x,y;i<=m;i++)cin>>x>>y,s.assign(1,x-1,0),s.assign(y+1,n,0);
	for(auto it:s)ans+=(it.r-it.l+1)*it.data;
	cout<<ans;
	return 0;
}