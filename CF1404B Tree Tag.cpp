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
constexpr int N=1e5+1;
int n,a,b,m1,m2,d,d1[N],d2[N],ds[N];
bsi g[N];
void dfs(int u,int fa){
	d1[u]=d2[u]=0;ds[u]=ds[fa]+1;
	for(int v:g[u])if(v!=fa){
		dfs(v,u);int w=d1[v]+1;
		if(w>d1[u])d2[u]=d1[u],d1[u]=w;
		else if(w>d2[u])d2[u]=w;
	}
	cmax(d,d1[u]+d2[u]);
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	ds[0]=-1;int T;cin>>T;while(T--)cout<<([]{
		cin>>n>>a>>b>>m1>>m2;d=0;
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1,u,v;i<n;i++)cin>>u>>v,g[u]+=v,g[v]+=u;
		dfs(a,0);
		if(2*m1>=min(m2,d)||ds[b]<=m1)return true;
		return false;
	}()?"Alice\n":"Bob\n");
	return 0;
}