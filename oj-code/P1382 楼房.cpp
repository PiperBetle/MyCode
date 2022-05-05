#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
using std::cin;using std::cout;
template<typename any>struct odt{
	struct odt_node{
		int l,r;mutable any data;
		odt_node(){}
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
		s.erase(it);insert(l,pos,k);
		return insert(pos,r,k).first;
	}
	auto assign(int l,int r,any k){
		auto it_r=split(r),it_l=split(l);
		s.erase(it_l,it_r);
		return insert(l,r,k).first;
	}
};
odt<int>s;
odt<int>::odt_node a[100007];
std::vector<std::pair<int,int>>ans1,ans2;
signed main(){
//	freopen(".in","r",stdin);freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int n,m1=0x3f3f3f3f,m2=-0x3f3f3f3f;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].data>>a[i].l>>a[i].r,m1=std::min(m1,a[i].l),m2=std::max(m2,a[i].r);
	std::sort(a+1,a+1+n,[](const auto &x,const auto &y){return x.data<y.data;});
	s.insert(m1,m2,0);
	for(int i=1;i<=n;i++)s.assign(a[i].l,a[i].r,a[i].data);
	ans1.emplace_back(m1,0);
	for(auto it:s)if(it.r<=m2)ans1.emplace_back(it.l,it.data),ans1.emplace_back(it.r,it.data);
	ans1.emplace_back(m2,0);
	for(auto it=ans1.begin();it!=ans1.end();it++){
		auto pre=it;pre--;
		if(*pre!=*it)ans2.emplace_back(*it);
	}
	cout<<ans2.size()<<'\n';
	for(auto it:ans2)cout<<it.first<<' '<<it.second<<'\n';
	return 0;
}