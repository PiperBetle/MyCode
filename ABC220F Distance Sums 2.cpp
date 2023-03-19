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
constexpr int N=2e5+1;
bsi g[N];
int n,sz[N],dep[N];
loli ans[N];
void dfs1(int u,int fa){
	sz[u]=1;
	for(int v:g[u])if(v!=fa)
		ans[1]+=dep[v]=dep[u]+1,dfs1(v,u),sz[u]+=sz[v];
}
void dfs2(int u,int fa){
	for(int v:g[u])if(v!=fa)
		ans[v]=ans[u]-2*sz[v]+n,dfs2(v,u);		
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1,u,v;i<n;i++)cin>>u>>v,g[u]+=v,g[v]+=u;
	dfs1(1,0);dfs2(1,0);
	for(int i=1;i<=n;i++)cout<<ans[i]<<'\n';
	return 0;
}