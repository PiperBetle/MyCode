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
constexpr int kN=201;
int n,m,ans,g[kN][kN],deg[kN];
void dfs(int u){
	for(int v=0;v<=n;v++)if(g[u][v]){
		g[u][v]=g[v][u]=0;
		if(u&&v)cout<<u<<' '<<v<<'\n';
		dfs(v);
	}
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>n>>m;ans=0;
		memset(deg+1,0,sizeof(int)*n);
		for(int i=1,u,v;i<=m;i++)cin>>u>>v,g[u][v]=g[v][u]=1,deg[u]++,deg[v]++;
		for(int i=1;i<=n;i++)if(deg[i]&1)g[0][i]=g[i][0]=1,deg[0]++,deg[i]++;else ans++;
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++)dfs(i);
	}
	return 0;
}