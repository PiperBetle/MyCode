//不向焦虑与抑郁投降，这个世界终会有我们存在的地方。
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<tuple>
#include<map>
#include<vector>
#if __cplusplus>=202002L
#include<ranges>
using namespace std::views;
#endif
#define siz(x) int(std::size(x))
#define cauto const auto
#define all(x) std::begin(x),std::end(x)
#define rall(x) std::rbegin(x),std::rend(x)
#define sqrt __builtin_sqrt
#define fi first
#define se second
#define continue(x) {x;continue;}
#define break(x) {x;break;}
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
using tiii=std::tuple<int,int,int>;
using inlsi=const std::initializer_list<int>&;
using bsi=std::basic_string<int>;
using bsc=std::string;
#if __cplusplus>=201703L
using bscv=std::string_view;
inline bscv substrv(bscv s,int l,int r){return bscv(s.data()+l,r);}
#endif
constexpr venti operator""_vt(uloli x){return venti(x);}
constexpr bool ying=false,yang=true;
constexpr int N=1e6+1;
int n,m,f[N];
bsc a;
std::vector<tiii>ans;
std::map<bsc,tiii>s;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>n>>m;
		memset(f+1,0,sizeof(int)*m);
		ans.clear();s.clear();
		for(int k=1;k<=n;k++){
			cin>>a;
			for(int i=0;i<m-1;i++)s[a.substr(i,2)]={i,i+1,k};
			for(int i=0;i<m-2;i++)s[a.substr(i,3)]={i,i+2,k};
		}
		f[0]=1;cin>>a;
		for(int i=1;i<=m;i++){
			if(i>=2&&f[i-2]&&s.count(a.substr(i-2,2)))f[i]=2;
			if(i>=3&&f[i-3]&&s.count(a.substr(i-3,3)))f[i]=3;
		}
		if(!f[m])continue(cout<<"-1\n")
		for(int i=m;i;i-=f[i])
			ans.push_back(s[a.substr(i-f[i],f[i])]);
		cout<<siz(ans)<<'\n';
		for(auto[l,r,k]:ans|reverse)cout<<l+1<<' '<<r+1<<' '<<k<<'\n';
	}
	return 0;
}