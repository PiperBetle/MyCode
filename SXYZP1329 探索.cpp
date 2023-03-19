#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
using std::cin;using std::cout;
struct odt{
	int l,r;mutable int data;
	bool operator<(const odt &n)const{return l<n.l;}
};
std::set<odt>s;
inline auto split(int pos){
	auto it=s.lower_bound(odt{pos,-1,0});
	if(it!=s.end()&&it->l==pos)return it;
	it--;int l=it->l,r=it->r,t=it->data;
	s.erase(it);s.insert(odt{l,pos-1,t});
	return s.insert(odt{pos,r,t}).first;
}
inline void assign(int l,int r,int k){
	auto it_r=split(r+1),it_l=split(l);
	s.erase(it_l,it_r);
	s.insert(odt{l,r,k});
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int n,m,ans=0;cin>>n>>m;
	s.insert(odt{1,n,1});
	s.insert(odt{n+1,n+1,0});
	for(int i=1,x,y;i<=m;i++)cin>>x>>y,assign(1,x-1,0),assign(y+1,n,0);
	for(auto it:s)ans+=(it.r-it.l+1)*it.data;
	cout<<ans;
	return 0;
}