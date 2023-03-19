#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<set>
#define int long long
using std::cin;using std::cout;
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
}s;
odt_node a[40001];
signed main(){
//	freopen(".in","r",stdin);freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int n,m2=-0x3f3f3f3f3f3f3f3f,ans=0;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].l>>a[i].r>>a[i].val,a[i].r--,m2=std::max(a[i].r,m2);
	std::sort(a+1,a+1+n,[](const auto &x,const auto &y){return x.val<y.val;});
	s.emplace(1,m2,0);s.emplace(m2+1,m2+1,0);
	for(int i=1;i<=n;i++)s.assign(a[i].l,a[i].r,a[i].val);
	for(auto it:s)ans+=(it.r-it.l+1)*it.val;
	cout<<ans;
	return 0;
}