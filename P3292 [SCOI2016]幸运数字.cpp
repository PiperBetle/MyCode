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
template<typename any,int W>struct LineBase{
	using type=LineBase<any,W>;
	any a[W+1];
	any &operator[](int x){return a[x];}
	any operator[](int x)const{return a[x];}
	type &operator+=(any x){for(int i=std::__lg(x);x;i=std::__lg(x^=a[i]))if(!a[i])return a[i]=x,*this;return *this;}
	type &operator+=(const type &y){for(int i=W;~i;i--)if(y[i])*this+=y[i];return *this;}
	friend type operator+(const type &x,const type &y){type res=x;return res+=y;}
	void clear(){memset(a,0,sizeof a);}
	type &init(any x){return *this+=x;}
	type &operator=(any x){clear();return *this+=x;}
	any max(any res=0){for(int i=W;~i;i--)res=std::max(res,res^a[i]);return res;}
};
constexpr int N=20001,M=std::__lg(N)+1,W=60;
LineBase<loli,60>s[M][N];
bsi g[N];
int n,m,p[M][N],dep[N];
loli a[N];
void dfs(int u,int fa){
	p[0][u]=fa;dep[u]=dep[fa]+1;s[0][u].init(a[u]);
	for(int i=1;i<M;i++)
		p[i][u]=p[i-1][p[i-1][u]],s[i][u]=s[i-1][u]+s[i-1][p[i-1][u]];
	for(int v:g[u])if(v!=fa)dfs(v,u);
}
loli LCA(int u,int v){
	LineBase<loli,60>res;res.clear();
	if(dep[u]>dep[v])std::swap(u,v);
	for(int k=dep[v]-dep[u],i=M-1;~i;i--)if(k>>i&1)
		res+=s[i][v],v=p[i][v];
	if(u==v)return (res+=s[0][u]).max();
	for(int i=M-1;~i;i--)if(p[i][u]!=p[i][v])
		(res+=s[i][u])+=s[i][v],u=p[i][u],v=p[i][v];
	return (((res+=s[0][u])+=s[0][v])+=s[0][p[0][u]]).max();
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1,u,v;i<n;i++)cin>>u>>v,g[u]+=v,g[v]+=u;
	dfs(1,0);
	for(int x,y;m--;)cin>>x>>y,cout<<LCA(x,y)<<'\n';
	return 0;
}