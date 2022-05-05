#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#define int long long
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
		s.erase(it);insert(l,pos-1,k);
		return insert(pos,r,k).first;
	}
	auto assign(int l,int r,any k){
		auto it_r=split(r+1),it_l=split(l);
		s.erase(it_l,it_r);
		return insert(l,r,k).first;
	}
};
odt<int>s;
odt<int>::odt_node a[40007];
signed main(){
//	freopen(".in","r",stdin);freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int n,m2=-0x3f3f3f3f3f3f3f3f,ans=0;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].l>>a[i].r>>a[i].data,a[i].r--,m2=std::max(a[i].r,m2);
	std::sort(a+1,a+1+n,[](const auto &x,const auto &y){return x.data<y.data;});
	s.insert(1,m2,0);s.insert(m2+1,m2+1,0);
	for(int i=1;i<=n;i++)s.assign(a[i].l,a[i].r,a[i].data);
	for(auto it:s)ans+=(it.r-it.l+1)*it.data;
	cout<<ans;
	return 0;
}