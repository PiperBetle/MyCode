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
using loli=long long;
using uloli=unsigned long long;
using lodb=long double;
using venti=__int128_t;
using pii=std::pair<int,int>;
using inlsi=const std::initializer_list<int>&;
constexpr venti operator""_vt(uloli x){return venti(x);}
constexpr int N=1e6+1;
int n,q;
loli c[N];
std::string bb;
struct odt_node{
	int l,r;mutable int val;
	odt_node(int _a=0,int _b=0,int _c=0):l(_a),r(_b),val(_c){}
	bool operator<(const odt_node &t)const{return l<t.l;}
};
struct odt:std::set<odt_node>{
	struct BIT{
		loli data[N]={};
		void add(int x,loli k=1){for(;x<=n;x+=x&-x)data[x]+=k;}
		loli query(int x){loli k=0;for(;x;x-=x&-x)k+=data[x];return k;}
		void updata(int l,int r,loli k){add(l,k);add(r+1,-k);}
	}bt;
	auto split(int p){
		auto it=lower_bound(p);
		if(it!=end()&&it->l==p)return it;
		auto t=*--it;erase(it);emplace(t.l,p-1,t.val);
		return emplace(p,t.r,t.val).first; 
	}
	auto assign(int l,int r,int k){
		auto ir=split(r+1),il=split(l);
		for(auto it=il;it!=ir;it++)bt.updata(it->l,it->r,c[it->val]-c[k]);
		erase(split(l),split(r+1));
		return emplace(l,r,k).first;
	}
	auto &operator[](int k){split(k+1);return split(k)->val;}
}s;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>q;s.emplace(1,n,1);s.emplace(n+1,n+1,0);
	for(int x,y,z;q--;)switch(cin>>bb>>x;bb.front()){
	case 'C':cin>>y>>z;s.assign(x,y,z);break;
	case 'A':cin>>y;c[x]+=y;break;
	case 'Q':cout<<s.bt.query(x)+c[s[x]]<<'\n';break;
	}
	return 0;
}