#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<set>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
using std::cin;using std::cout;
using std::prev;using std::next;
using loli=long long;
using uloli=unsigned long long;
using lodb=long double;
using venti=__int128_t;
using pii=std::pair<int,int>;
using inlsi=const std::initializer_list<int>&;
constexpr venti operator""_vt(uloli x){return venti(x);}
struct odt_node{
	int l,r;mutable char val;
	odt_node(int a=0,int b=0,char c=0):l(a),r(b),val(c){}
	bool operator<(const odt_node &t)const{return l<t.l;}
};
int n,q,pre=1;
char c1,c2;
struct odt:std::set<odt_node>{
	auto split(int p){
		auto it=lower_bound(p);
		if(it!=end()&&it->l==p)return it;
		auto t=*--it;erase(it);emplace(t.l,p-1,t.val);
		return emplace(p,t.r,t.val).first; 
	}
	auto assign(int l,int r,char k){
		erase(split(l),split(r+1));
		return emplace(l,r,k).first;
	}
	bool query(int l,int r){
		auto ir=split(r+1),il=split(l);
		if(l!=1&&r!=n&&prev(il)->val==ir->val)return false;
		for(auto it=il;it!=ir;++it)if(il->val!=it->val)
			return assign(il->l,(--it)->r,il->val),false;
		return assign(l,r,il->val),true;
	}
}s;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>c2;
	for(int i=2;i<=n;i++){
		cin>>c1;
		if(c1!=c2)s.emplace(pre,i-1,c2),pre=i;
		c2=c1;
	}
	s.emplace(pre,n,c1);
	s.emplace(n+1,n+1,'D');
	cin>>q;
	for(int l,r;q--;){
		char op,k;cin>>op;
		if(op=='A')cin>>l>>r>>k,s.assign(l,r,k);
		else cin>>l>>r,cout<<(s.query(l,r)?"Yes\n":"No\n");
	}
	return 0;
}