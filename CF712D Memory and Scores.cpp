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
constexpr int N=3001*100+100+1,P=1e9+7,W=N/2;
int a,b,k,n,ans;
inline int add0(int x,int y){return (x+=y)<P?x:x-P;}
inline int&add1(int&x,int y){return (x+=y)<P?x:x-=P;}
inline int sub0(int x,int y){return (x-=y)<0?x+P:x;}
inline int mul0(int x,int y){return int(1ll*x*y%P);}
struct{
	int d[N],s[N];
	int&operator[](int x){return d[x];}
	void sets(){for(int i=1;i<N;i++)s[i]=add0(s[i-1],d[i]);}
	int ask(int x,int y){return sub0(s[y],s[x-1]);}
}f1[2],f2[2];
signed main(){
//	freopen("score.in","r",stdin);
//	freopen("score.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>a>>b>>k>>n;
	f1[0][W+a]=f2[0][W+b]=1;f1[0].sets();f2[0].sets();
	for(int i=1;i<=n;i++){
		for(int j=2*k;j<N-2*k;j++)f1[i&1][j]=f1[~i&1].ask(j-k,j+k);
		for(int j=2*k;j<N-2*k;j++)f2[i&1][j]=f2[~i&1].ask(j-k,j+k);
		f1[i&1].sets();f2[i&1].sets();
	}
	for(int j=2*k;j<N-2*k;j++)add1(ans,mul0(f1[n&1][j],f2[n&1].ask(1,j-1)));
	cout<<ans;
	return 0;
}