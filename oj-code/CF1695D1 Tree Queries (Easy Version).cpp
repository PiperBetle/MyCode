#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) x.begin(),x.end()
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=1e5+1;
std::basic_string<int>g[kN];
int T,n,ans;
bool vis[kN];
int dfs(int u,int fa){
	if(siz(g[u])>2)return u;
	for(int v:g[u])if(v!=fa)return dfs(v,u);
	return u; 
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>T;while(T--){
		cin>>n;
		for(int i=1;i<=n;i++)g[i].clear();
		memset(vis+1,0,sizeof(bool)*n);
		for(int i=1,u,v;i<n;i++)cin>>u>>v,g[u]+=v,g[v]+=u;
		for(int i=1;i<=n;i++)if(siz(g[i])==1)vis[dfs(i,0)]=true,ans++;
		for(int i=1;i<=n;i++)if(vis[i])ans--;
		cout<<std::max(1,ans)<<'\n';
	}
	return 0;
}