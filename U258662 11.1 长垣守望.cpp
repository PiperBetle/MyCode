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
const int N=201,p=10000019;
int n,m,in[N],sz[N],a[N],f[N][N];
bsi g[N];
int qp(int x,int o){
	int res=1;
	while(o){
		if(o&1)res=1ll*res*x%p;
		x=1ll*x*x%p,o>>=1;
	}
	return res;
}
void dfs(int u,int fa){
	sz[u]=1,f[u][1]=a[u];
	for(int v:g[u])if(v^fa){
		dfs(v,u);
		for(int i=min(sz[u],m);i;i--)
			for(int j=min(sz[u]+sz[v],m+1)-i;j;j--)
			cmax(f[u][i+j],f[u][i]+f[v][j]);
		sz[u]+=sz[v];
	}
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1,u,w,t;i<=n;i++)
		cin>>u>>w>>t,g[u]+=i,a[i]=qp(w,t),in[i]++;
	for(int i=1;i<=n;i++)if(!in[i])g[0]+=i;
	dfs(0,0);
	cout<<f[0][m+1]<<'\n';
	return 0;
}