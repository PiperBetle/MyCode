#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<set>
#define siz(x) int((x).size())
#define cauto const auto
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=2e5+1,MOD=998244353;
constexpr int add0(int x,int y){return (x+=y)<MOD?x:x-MOD;}
constexpr int&add1(int&x,int y){return (x+=y)<MOD?x:x-=MOD;}
constexpr int sub0(int x,int y){return (x-=y)<0?x+MOD:x;}
constexpr int&sub1(int&x,int y){return (x-=y)<0?x+=MOD:x;}
constexpr int mul(const std::initializer_list<int>&x){loli y=1;for(int i:x)(y*=i)%=MOD;return int(y%MOD);}
constexpr int calc(int l,int r){return mul({add0(l,r),sub0(add0(r,1),l),499122177});}
struct odt_node{
	loli l,r;mutable int val;
	odt_node(loli a=0,loli b=0,int c=0):l(a),r(b),val(c){}
	bool operator<(const odt_node &t)const{return l<t.l;}
};
struct odt:std::set<odt_node>{
	auto split(loli p){
		auto it=lower_bound(p);
		if(it!=end()&&it->l==p)return it;
		auto t=*--it;erase(it);emplace(t.l,p-1,t.val);
		return emplace(p,t.r,t.val).first;
	}
	auto assign(loli l,loli r,int k){
		erase(split(l),split(r+1));
		return emplace(l,r,k).first;
	}
	auto query(loli l,loli r,int k){
		int ans=0;
		for(auto ir=split(r+1),il=split(l);il!=ir;il++)
			add1(ans,mul({sub0(k,il->val),calc(int(il->l%MOD),int(il->r%MOD))}));
		assign(l,r,k);
		return ans;
	}
}s;
struct{loli l,r,val;}a[kN];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	loli n;int m;cin>>n>>m;
	s.emplace(1,n,0),s.emplace(n+1,n+1,0);
	for(int i=1;i<=m;i++)
		cin>>a[i].val>>a[i].l>>a[i].r,
		cout<<s.query(a[i].l,a[i].r,int(a[i].val%MOD))<<'\n';
	return 0;
}