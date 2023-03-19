#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
using std::cin;using std::cout;
using std::max;using std::min;
constexpr int N=1e5+1,inf=0x3f3f3f3f;
struct odt_node{
	int l,r;mutable int val;
	odt_node(int a=0,int b=0,int c=0):l(a),r(b),val(c){}
	bool operator<(const odt_node &t)const{return l<t.l;}
};
int n,m,a[N];
struct odt:std::set<odt_node>{
	auto split(int p){
		auto it=lower_bound(p);
		if(it!=end()&&it->l==p)return it;
		auto t=*--it;erase(it);emplace(t.l,p-1,t.val);
		return emplace(p,t.r,t.val).first; 
	}
	auto updata(int l,int k){
		auto il=split(l);
		if((a[l]-=k)>=il->val)goto pblk;
		else il->val=a[l];	
		for(auto it=std::next(il);;++it){
			if(it->val<il->val){
				int t=il->val;
				erase(il,it);
				emplace(l,it->l-1,t);
				goto pblk;
			}
		}
		pblk:il=lower_bound(l);
		if(il!=--end()&&il->val==std::next(il)->val){
			int l=il->l,r=std::next(il)->r,t=il->val;
			erase(std::next(il));erase(il);
			emplace(l,r,t);
		}
		il=lower_bound(l);
		if(il!=begin()&&il->val==std::prev(il)->val){
			int l=std::prev(il)->l,r=il->r,t=il->val;
			erase(std::prev(il));erase(il);
			emplace(l,r,t);
		}
	}
}s;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>n>>m;
		s.clear();
		int j=1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]<a[j])s.emplace(j,i-1,a[j]),j=i;
		}
		s.emplace(j,n,a[j]);s.emplace(n+1,n+1,-inf);
		for(int x,k;m--;){
			cin>>x>>k;
			s.updata(x,k);
			cout<<siz(s)-1<<' ';
		}
		cout<<'\n';
	}
	return 0;
}