#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=101;
int n,m,k,cnt,fa[kN],dep[kN];
bool vis[kN];
std::basic_string<int>g[kN];
void dfs1(int u){
	for(int v:g[u])if(v!=fa[u])
		dep[v]=dep[u]+1,dfs1(v);
}
void dfs2(int u){
	cout<<u<<' ';
	for(int v:g[u])if(v!=fa[u]&&cnt&&!vis[v])
		cnt--,dfs2(v),cout<<u<<' ';
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>n>>k;m=1;
		memset(vis+1,0,sizeof(bool)*n);
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=2;i<=n;i++)cin>>fa[i],g[fa[i]]+=i;
		dep[1]=1;dfs1(1);
		for(int i=2;i<=n;i++)if(dep[i]<=k&&dep[i]>dep[m])m=i;
		cnt=k-dep[m];
		cout<<(k-1)*2-dep[m]+1<<'\n';
		while(m)vis[m]=true,m=fa[m];
		for(int i=1;i<=n;i++)if(vis[i])dfs2(i);
		cout<<'\n';
	}
	return 0;
}