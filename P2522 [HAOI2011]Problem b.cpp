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
struct _time{~_time(){std::cerr<<"\n\033[33;40m"<<1.*clock()/CLOCKS_PER_SEC<<"s\033[37;40m";}}_TM;
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
template<typename any>inline void cmin(any&x,const any&y){if(y<x)x=y;}
template<typename any>inline void cmax(any&x,const any&y){if(x<y)x=y;}
template<typename any,typename...args>inline void cmin(any&x,const any&y,const args&...z){cmin(x,y);cmin(x,z...);}
template<typename any,typename...args>inline void cmax(any&x,const any&y,const args&...z){cmax(x,y);cmax(x,z...);}
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
#define type std::pair<T1,T2>
template<typename T1,typename T2>std::istream&operator>>(std::istream&x,type&y){return x>>y.fi>>y.se;}
template<typename T1,typename T2>std::ostream&operator<<(std::ostream&x,const type&y){return x<<y.fi<<' '<<y.se;}
template<typename T1,typename T2>type operator+(const type&x,const type&y){return{x.fi+y.fi,x.se+y.se};}
template<typename T1,typename T2>type operator+=(type&x,const type&y){x.fi+=y.fi;x.se+=y.se;return x;}
template<typename T1,typename T2>type operator-(const type&x,const type&y){return{x.fi-y.fi,x.se-y.se};}
template<typename T1,typename T2>type operator-=(type&x,const type&y){x.fi-=y.fi;x.se-=y.se;return x;}
#undef type
template<typename any>any get(std::istream&x=cin){any y;x>>y;return y;}
template<typename any>any&STLcls(any &x){any{}.swap(x);return x;}
constexpr venti operator""_vt(lolu x){return venti(x);}
constexpr bool ying=false,yang=true;
constexpr int N=5e4+1;
bsi pt;
bool pr[N];
int mu[N],l1,l2,r1,r2,k;
int calc(int n,int m){
	int res=0;
	for(int l=1,r;l<=min(n,m);l=r+1)
		r=min(n/(n/l),m/(m/l)),
		res+=(mu[r]-mu[l-1])*(n/l)*(m/l);
	return res;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	mu[1]=1;
	for(int i=2;i<N;i++){
		if(!pr[i])pt+=i,mu[i]=-1;
		for(int j:pt){
			if(i*j>=N)break;
			pr[i*j]=true;
			if(i%j==0)break(mu[i*j]=0)
			mu[i*j]=-mu[i];
		}
	}
	for(int i=2;i<N;i++)mu[i]+=mu[i-1];
	int T;cin>>T;while(T--){
		cin>>l1>>r1>>l2>>r2>>k;
		l1=(l1+k-1)/k;r1/=k;
		l2=(l2+k-1)/k;r2/=k;
		if(l1>r1||l2>r2)continue(cout<<"0\n")
		cout<<calc(r1,r2)-calc(l1-1,r2)-calc(r1,l2-1)+calc(l1-1,l2-1)<<'\n';
	}
	return 0;
}