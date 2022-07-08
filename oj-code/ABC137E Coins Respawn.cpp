#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<vector>
#include<queue>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) x.begin(),x.end()
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=2501;
int n,m,p,dis[kN],cnt[kN];
bool vis[kN];
std::vector<pii>g[kN];
std::queue<int>q;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m>>p;
	for(int i=1,u,v,w;i<=m;i++)cin>>u>>v>>w,g[u].emplace_back(v,w-p);
	memset(dis+1,0xc0,sizeof(int)*n);
	q.emplace(1);dis[1]=0;vis[1]=true;
	while(!q.empty()){
		int u=q.front();q.pop();
		vis[u]=false;
		for(auto[v,w]:g[u]){
			if(vis[v])continue;
			if(dis[v]<dis[u]+w){
				dis[v]=dis[u]+w;
				if(!vis[v]){
					vis[v]=true;
					q.emplace(v);
					if(++cnt[v]>n)return cout<<"-1",0;
				}
			}
		}
	}
	cout<<std::max(0,dis[n]);
	return 0;
}