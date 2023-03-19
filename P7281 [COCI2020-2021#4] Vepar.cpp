//不向焦虑与抑郁投降，这个世界终会有我们存在的地方。
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<tuple>
#include<ctime>
#include<random>
#if __cplusplus>=202002L
#include<ranges>
namespace vw=std::views;
#endif
struct _time{~_time(){std::cerr<<"\n"<<1.*clock()/CLOCKS_PER_SEC<<"s";}}_TM;
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) std::begin(x),std::end(x)
#define rall(x) std::rbegin(x),std::rend(x)
#define sqrt __builtin_sqrt
#define fi first
#define se second
#define continue(x...) {x;continue;}
#define break(x...) {x;break;}
using std::cin;using std::cout;
using std::max;using std::min;
using std::tie;using std::ignore;
template<typename any>inline void cmin(any &x,const any &y){if(y<x)x=y;}
template<typename any>inline void cmax(any &x,const any &y){if(x<y)x=y;}
template<typename any,typename...args>inline void cmin(any &x,const any &y,const args &...z){cmin(x,y);cmin(x,z...);}
template<typename any,typename...args>inline void cmax(any &x,const any &y,const args &...z){cmax(x,y);cmax(x,z...);}
using loli=long long;
using unt=unsigned;
using lolu=unsigned long long;
using lodb=long double;
using venti=__int128_t;
using pii=std::pair<int,int>;
using tiii=std::tuple<int,int,int>;
using inlsi=const std::initializer_list<int>&;
using bsi=std::basic_string<int>;
using bsl=std::basic_string<loli>;
using bsc=std::string;
using std::operator""s;
#if __cplusplus>=201703L
using bscv=std::string_view;
using std::operator""sv;
#endif
std::mt19937 rng(std::random_device{}());
constexpr venti operator""_vt(lolu x){return venti(x);}
constexpr bool ying=false,yang=true;
constexpr int N=1e7+1;
int n,a,b,c,d;
bsi pt;
bool pr[N];
int calc(int x,int l,int r){
	int sum=0;
	for(loli i=x;i<N;i*=x)
		sum+=r/i;
	for(loli i=x;i<N;i*=x)
		sum-=(l-1)/i;
	return sum;
}
signed main(){
//	freopen("illusionary.in","r",stdin);
//	freopen("illusionary.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	for(int i=2;i<N;i++){
		if(!pr[i])pt+=i;
		for(int it=0;it<siz(pt);it++){
			int j=pt[it];
			if(i*j>=N)break;
			pr[i*j]=true;
			if(i%j==0)break;
		}
	}
	int T;cin>>T;while(T--)cout<<[]{
		cin>>a>>b>>c>>d;
		if(c<=a&&b<=d)return "DA\n";
		if(a<=c&&c<=b&&b<=d){int bb=b,cc=c;b=cc-1;c=bb+1;}
		if(c<=a&&a<=d&&d<=b){int aa=a,dd=d;a=dd+1;d=aa-1;}
		for(int i:pt)if(calc(i,a,b)>calc(i,c,d))
			return "NE\n";
		return "DA\n";
	}();
	return 0;
}