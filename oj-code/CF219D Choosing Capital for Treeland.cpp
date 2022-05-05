#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
struct edge{int go,data;};
std::vector<edge>s[200007];
int f[200007];
using std::cin;using std::cout;
void pre_work(int u,int fa){for(auto[v,t]:s[u])if(v==fa)continue;else f[1]+=t,pre_work(v,u);}
void dfs(int u,int fa){for(auto[v,t]:s[u])if(v==fa)continue;else f[v]=f[u]+(t?-1:1),dfs(v,u);}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,ans=0x3f3f3f3f;cin>>n;
	for(int i=1,u,v;i<n;i++)cin>>u>>v,s[u].emplace_back(v,0),s[v].emplace_back(u,1);
	pre_work(1,0);dfs(1,0);
	for(int i=1;i<=n;i++)ans=std::min(ans,f[i]);
	cout<<ans<<'\n';
	for(int i=1;i<=n;i++)if(ans==f[i])cout<<i<<' ';
	return 0;
}