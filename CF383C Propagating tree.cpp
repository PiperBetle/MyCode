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
constexpr int N=200001;
int n,m,cnt,dfn[N],end[N],dep[N],a[N];
bsi g[N];
void dfs(int u,int fa){
	dfn[u]=++cnt;dep[u]=dep[fa]^1;
	for(int v:g[u])if(v!=fa)dfs(v,u);
	end[u]=cnt;
}
struct{
	int d[N];
	void add(int x,int k){for(;x<=n;x+=x&-x)d[x]+=k;}
	int ask(int x){int k=0;for(;x;x-=x&-x)k+=d[x];return k;}
}c[2];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1,u,v;i<n;i++)cin>>u>>v,g[u]+=v,g[v]+=u;
	dfs(1,0);
	for(int x,k;m--;)switch(cin>>x,x){
	case 1:cin>>x>>k;c[dep[x]].add(dfn[x],k);c[dep[x]].add(end[x]+1,-k);break;
	case 2:cin>>x;cout<<a[x]+c[dep[x]].ask(dfn[x])-c[dep[x]^1].ask(dfn[x])<<'\n';break;
	}
	return 0;
}