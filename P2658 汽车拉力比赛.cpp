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
constexpr int N=501,M=1<<29;
int n,m,h[N][N],g[N][N],ans,fa[N*N];
bsi z;
inline int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
inline void merge(int x,int y){if((x=find(x))!=(y=find(y)))fa[x]=y;}
inline int id(int i,int j){return m*(i-1)+j;}
bool check(int x){
	for(int i=1;i<=id(n,m);i++)fa[i]=i;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
		if(i!=1&&abs(h[i][j]-h[i-1][j])<=x)merge(id(i,j),id(i-1,j));
		if(i!=n&&abs(h[i][j]-h[i+1][j])<=x)merge(id(i,j),id(i+1,j));
		if(j!=1&&abs(h[i][j]-h[i][j-1])<=x)merge(id(i,j),id(i,j-1));
		if(j!=m&&abs(h[i][j]-h[i][j+1])<=x)merge(id(i,j),id(i,j+1));
	}
	for(int i=1;i<siz(z);i++)if(find(z[i])!=find(z[0]))return false;
	return true;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>h[i][j];
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>g[i][j];
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(g[i][j])z+=id(i,j);
	for(int i=M;i;i/=2)if(!check(ans+i))ans+=i;
	if(!check(ans))ans++;cout<<ans;
	return 0;
}