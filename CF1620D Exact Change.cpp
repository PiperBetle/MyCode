//不向焦虑与抑郁投降，这个世界终会有我们存在的地方。
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<tuple>
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
#endif
constexpr venti operator""_vt(uloli x){return venti(x);}
constexpr bool ying=false,yang=true;
constexpr int N=101,inf=0x3f3f3f3f;
int n,m,a[N];
inline int calc(int t1,int t2){
	int res=0;
	for(int i=1;i<=n;i++){
		int k=inf;
		for(int c1=0;c1<=t1;c1++)for(int c2=0;c2<=t2;c2++)
			if(int r=a[i]-c1-c2-c2;r>=0&&r%3==0)cmin(k,r/3);
		cmax(res,k);
	}
	return res+t1+t2;
};
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>n;m=inf;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=0;i<=2;i++)for(int j=0;j<=2;j++)cmin(m,calc(i,j));
		cout<<m<<'\n';
	}
	return 0;
}