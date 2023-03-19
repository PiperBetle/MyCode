#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<tuple>
#include<set>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
using std::cin;using std::cout;
using std::max;using std::min;
using std::tie;using std::ignore;
template<typename any>inline void cmin(any &x,const any &y){if(y<x)x=y;}
template<typename any>inline void cmax(any &x,const any &y){if(x<y)x=y;}
template<typename any,typename...args>inline void cmax(any &x,const any &y,const args &...z){cmax(x,y);cmax(x,z...);}
template<typename any,typename...args>inline void cmin(any &x,const any &y,const args &...z){cmin(x,y);cmin(x,z...);}
using loli=long long;
using uloli=unsigned long long;
using lodb=long double;
using venti=__int128_t;
using pii=std::pair<int,int>;
using inlsi=const std::initializer_list<int>&;
using bsi=std::basic_string<int>;
using bsc=std::basic_string<char>;
constexpr venti operator""_vt(uloli x){return venti(x);}
constexpr int N=2.1e5+1;
struct odt_node{
	int l,r;mutable int v;
	odt_node(int a=0,int b=0,int c=0):l(a),r(b),v(c){}
	bool operator<(const odt_node &t)const{return l<t.l;}
};
struct odt:std::set<odt_node>{
	auto split(int p){
		auto it=lower_bound(p);
		if(it!=end()&&it->l==p)return it;
		auto t=*--it;erase(it);emplace(t.l,p-1,t.v);
		return emplace(p,t.r,t.v).first; 
	}
	auto assign(int l,int r,int k){
		erase(split(l),split(r+1));
		return emplace(l,r,k).first;
	}
	auto add(int p){
		split(p+1);auto it=split(p);
		if(!it->v){it->v=1;return;}
		int l=it->l;while(it->v)++it;int r=it->l-1;
		assign(l,r,0);split(r+2);split(r+1)->v=1;
	}
	auto sub(int p){
		split(p+1);auto it=split(p);
		if(it->v){it->v=0;return;}
		int l=it->l;while(!it->v)++it;int r=it->l-1;
		assign(l,r,1);split(r+2);split(r+1)->v=0;
	}
	auto query(){
		for(auto it=--end();;--it)
			if(it->v)return assign(it->r+1,rbegin()->r,0),it->r;
			else if(it==begin())return 0;
	}
}s;
int n,m,a[N];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;s.emplace(1,N,0);
	for(int i=1;i<=n;i++)cin>>a[i],s.add(a[i]);
	for(int x,y;m--;)cin>>x>>y,s.sub(a[x]),s.add(a[x]=y),cout<<s.query()<<'\n';
	return 0;
}