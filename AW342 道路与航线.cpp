#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
struct edge{int go,data;};
std::vector<edge>s[25007];
using std::cin;using std::cout;
std::deque<int>q;
int dis[25007];
bool vis[25007];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,n,m1,m2,start,u,v,t;
	cin>>n>>m1>>m2>>start;
	memset(dis,0x3f,sizeof dis);
	for(i=1;i<=m1;i++)cin>>u>>v>>t,s[u].emplace_back(edge{v,t}),s[v].emplace_back(edge{u,t});
	for(i=1;i<=m2;i++)cin>>u>>v>>t,s[u].emplace_back(edge{v,t});
	for(q.push_front(start),dis[start]=0;!q.empty();){
		u=q.front();q.pop_front();
		vis[u]=false;
		for(auto it:s[u])if(dis[it.go]>dis[u]+it.data){
			dis[it.go]=dis[u]+it.data;
			if(!vis[it.go]){
				if(q.empty()||dis[it.go]>dis[q.front()])q.push_back(it.go);
				else q.push_front(it.go);
				vis[it.go]=true;
			}
		}
	}
	for(i=1;i<=n;i++)if(dis[i]==0x3f3f3f3f)cout<<"NO PATH\n";else cout<<dis[i]<<'\n';
	return 0;
}