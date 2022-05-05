#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
using std::cin;using std::cout;
int n,m,ans;
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
	void assign(int l,int r,int k){
		auto it_r=split(r+1),it_l=split(l);
		s.erase(it_l,it_r);
		auto it=s.insert(odt_node(l,r,k)).first;
		if(it==s.begin())return;
		it_l=it,it_r=it;it_l--;it_r++;
		l=it->l,r=it->r,k=it->data;
		if(it_r!=s.end()&&it_l->data==k&&it_r->data==k)l=it_l->l,r=it_r->r,s.erase(it_l,++it_r);
		else if(it_l->data==k)l=it_l->l,s.erase(it_l,++it);
		else if(it_r!=s.end()&&it_r->data==k)r=it_r->r,s.insert(it,++it_r);
		if(l!=r)s.insert(odt_node(l,r,k));
	}
	int query(int pos,int now=0,int ans=0){
		for(auto it:s){
			if(it.r>n||it.data!=0){now=0;continue;}
			if(now==0)ans=it.l;
			now+=it.r-it.l+1;
			if(now>=pos)return ans;
		}
		return -1;
	}
};
odt<int>s;
signed main(){
//	freopen(".in","r",stdin);freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;s.insert(1,n,0);s.insert(n+1,n+1,-1);
	while(m--){
		char c;int l,r;cin>>c;
		if(c=='A'){
			cin>>r;l=s.query(r);
			if(l==-1){ans++;continue;}
			s.assign(l,l+r-1,0);
		}else cin>>l>>r,s.assign(l,r,0);
	}
	cout<<ans;
	return 0;
}