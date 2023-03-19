#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using std::cin;using std::cout;
using pii=std::pair<int,int>;
constexpr int kN=1e5+1;
std::vector<pii>g[kN];
int n,m,s,dis[kN];
bool vis[kN];
std::priority_queue<pii,std::vector<pii>,std::greater<pii>>q;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m>>s;
	for(int i=1,u,v,t;i<=m;i++)cin>>u>>v>>t,g[u].emplace_back(v,t);
	memset(dis+1,0x3f,sizeof(int)*n);
	dis[s]=0;q.emplace(0,s);
	for(;!q.empty();){
		int u=q.top().second;q.pop();
		if(vis[u])continue;else vis[u]=true;
		for(auto[v,t]:g[u])if(dis[v]>dis[u]+t){
			dis[v]=dis[u]+t;
			if(!vis[v])q.emplace(dis[v],v);
		}
	}
	for(int i=1;i<=n;i++)cout<<(dis[i]==0x3f3f3f3f?-1:dis[i])<<' ';
	return 0;
}