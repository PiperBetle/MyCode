//不向焦虑与抑郁投降，这个世界终会有我们存在的地方。
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<tuple>
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
constexpr int N=2e5+1,M=1e3+1,P=998244353;
int n,m,k,f[2][N],ans[N];
inline int&add1(int&x,int y){return (x+=y)<P?x:x-=P;}
inline int&add1(int&x,int y,int z){return (x+=y)<P?x:x-=P,(x+=z)<P?x:x-=P;}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>k;f[k&1][0]=1;
	for(int i=k;k<=n;k+=i++){
		for(int j=i;j<=n;j++)add1(f[i&1][j],f[~i&1][j-i]+f[i&1][j-i]);
		f[i&1][0]=0;
		for(int j=1;j<=n;j++)add1(ans[j],f[i&1][j]);
		memset(f[~i&1]+1,0,sizeof(int)*n);
	}
	for(int j=1;j<=n;j++)cout<<ans[j]<<' ';
	return 0;
}