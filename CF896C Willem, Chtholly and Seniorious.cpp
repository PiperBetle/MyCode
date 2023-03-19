#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<vector>
#include<set>
#define int loli
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
using pli=std::pair<loli,int>;
using inlsi=const std::initializer_list<int>&;
constexpr venti operator""_vt(uloli x){return venti(x);}
struct odt_node{
	int l,r;mutable loli val;
	odt_node(int a=0,int b=0,loli c=0):l(a),r(b),val(c){}
	bool operator<(const odt_node &t)const{return l<t.l;}
};
int qp(int a,int b,int p){int t=1;for(;b;b>>=1,a=int(1ll*a*a%p))if(b&1)t=int(1ll*t*a%p);return t;}
struct odt:std::set<odt_node>{
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
	auto updata(int l,int r,int k){
		for(auto ir=split(r+1),il=split(l);il!=ir;++il)il->val+=k;
	}
	auto kth(int l,int r,int k){
		static std::vector<pli>b;b.clear();
		for(auto ir=split(r+1),il=split(l);il!=ir;++il)b.emplace_back(il->val,il->r-il->l+1);
		std::sort(all(b));
		for(auto[num,cnt]:b)if((k-=cnt)<=0)return num;
		return loli(EOF);
	}
	auto query(int l,int r,int x,int y){
		int sum=0;
		for(auto ir=split(r+1),il=split(l);il!=ir;++il)sum=int((sum+(il->r-il->l+1ll)*qp(int(il->val%y),x,y))%y);
		return sum;
	}
}s;
int n,m,seed,vmax;
int rnd(){
	int ret=seed;
	seed=int((seed*7ll+13)%int(1e9+7));
	return ret;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m>>seed>>vmax;s.emplace(n+1,n+1,0);
	for(int i=1;i<=n;i++)s.emplace(i,i,rnd()%vmax+1);
	for(int i=1,l,r,x,y;i<=m;i++)switch(rnd()%4+1){
	case 1:l=rnd()%n+1,r=rnd()%n+1;if(l>r)std::swap(l,r);x=rnd()%vmax+1;s.updata(l,r,x);break;
	case 2:l=rnd()%n+1,r=rnd()%n+1;if(l>r)std::swap(l,r);x=rnd()%vmax+1;s.assign(l,r,x);break;
	case 3:l=rnd()%n+1,r=rnd()%n+1;if(l>r)std::swap(l,r);x=rnd()%(r-l+1)+1;cout<<s.kth(l,r,x)<<'\n';break;
	case 4:l=rnd()%n+1,r=rnd()%n+1;if(l>r)std::swap(l,r);x=rnd()%vmax+1,y=rnd()%vmax+1;cout<<s.query(l,r,x,y)<<'\n';break;
	}
	return 0;
}