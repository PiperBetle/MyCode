#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
using std::cin;using std::cout;
using loli=long long;
using uloli=unsigned long long;
using lodb=long double;
using venti=__int128_t;
using pii=std::pair<int,int>;
using inlsi=const std::initializer_list<int>&;
constexpr venti operator""_vt(uloli x){return venti(x);}
constexpr int N=2e5+1;
int n,m,q,fa[N],dep[N],gs[N],top[N],sz[N],dfn[N],b[N],lc[N];
std::basic_string<int>g[N];
void dfs1(int u){
	for(int v:g[u]){
		if(v==fa[u])continue;
		fa[v]=u,dep[v]=dep[u]+1,sz[v]=1;
		dfs1(v);sz[u]+=sz[v];
		if(sz[v]>sz[gs[u]])gs[u]=v;
	}
}
void dfs2(int u,int t){
	static int cnt=0;
	top[u]=t;dfn[u]=++cnt;
	if(!gs[u])return;else dfs2(gs[u],t);
	for(int v:g[u])if(v!=fa[u]&&v!=gs[u])dfs2(v,v);
}
inline int LCA(int x,int y){
	for(;top[x]!=top[y];x=fa[top[x]])if(dep[top[x]]<dep[top[y]])std::swap(x,y);
	return dep[x]<dep[y]?x:y;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1,u,v;i<n;i++)cin>>u>>v,g[u]+=v,g[v]+=u;
	dep[0]=0x3f3f3f3f;sz[1]=dep[1]=1;dfs1(1);dfs2(1,1);
	cin>>q;while(q--){
		cin>>m;
		for(int i=1;i<=m;i++)cin>>b[i];
		cout<<([]{
			if(m==1)return true;
			std::sort(b+1,b+1+m,[](int x,int y){return dfn[x]<dfn[y];});
			int rt=0,cnt=0;
			for(int i=1;i<m;i++)if(dep[lc[i]=LCA(b[i],b[i+1])]<dep[rt])rt=lc[i];
			for(int i=1;i<m;i++)if(lc[i]!=b[i]&&lc[i]!=b[i+1])cnt+=(lc[i]==rt?1:2);
			return cnt<2;
		}()?"YES\n":"NO\n");
	}
	return 0;
}