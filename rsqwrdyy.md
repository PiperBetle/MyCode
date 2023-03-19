给定一棵有根树，开始每个点是黑色的，每轮操作会随机选一个黑点，然后把这个点到根路径上的所有点染白，问要把所有点全部染白期望需要几轮。  
第一行一个 $n$ 表示节点数量。第二行 $n-1$ 个整数，第 $i$ 个整数 $fa_i$ 表示第 $i+1$ 个节点的父亲。$n\le10^7,fa_i<i+1$

期望比较难做，但是可以计算每个节点被染色的期望次数加起来。对每个节点的子树进行计算，其中有一个点被染色了，这个节点就被染色了，所以这个节点的贡献是 $\dfrac1{siz_i}$，把所有节点的 $\dfrac1{siz_i}$ 加起来就是最终答案了。  
但是由于 $n$ 比较大，而且本体 $fa_i<i+1$，所以可以不去递归而是倒着循环一遍。另外逆元的处理采取线形求逆元。  
一种线形求逆元的办法：$\dfrac1i=\dfrac{n!}{(n-1)!}$，所以求出阶乘和阶乘的逆元即可。

代码：
```cpp
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
constexpr int N=1e7+1,P=998244353;
int n,m,fac[N],fa[N],inv[N],sz[N],ans;
inline int&add1(int&x,int y){return (x+=y)>=P?x-=P:x;}
inline int mul0(int x,int y){return int(1ll*x*y%P);}
inline int mul0(int x,int y,int z){return int(1ll*x*y%P*z%P);}
inline int&mul1(int&x,int y){return x=int(1ll*x*y%P);}
inline int qp(int x,int y=P-2){int z=1;for(;y;mul1(x,x),y/=2)if(y&1)mul1(z,x);return z;}
signed main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int u,v=2;v<=n;v++)cin>>u,fa[v]=u;
	fac[0]=fac[1]=inv[0]=inv[1]=1;
	for(int i=2;i<=n;i++)fac[i]=mul0(fac[i-1],i);
	inv[n]=qp(fac[n]);
	for(int i=n-1;i>=2;i--)inv[i]=mul0(inv[i+1],i+1);
	for(int i=n;i>=1;i--)sz[fa[i]]+=++sz[i],add1(ans,mul0(fac[sz[i]-1],inv[sz[i]]));
	cout<<ans;
	return 0;
}
```