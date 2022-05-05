#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<ext/pb_ds/priority_queue.hpp>
using namespace __gnu_pbds;
#define int long long
using std::cin;using std::cout;
struct edge{int go,data;};
std::vector<edge>s1[100007],s2[100007];
int dis[1000007],n,m,ans;bool visit[1000007];
struct point{int p,dis;bool operator<(const point&n)const{return dis>n.dis;}}now;
priority_queue<point>q;
inline void dijkstra(std::vector<edge>*s)
{
	memset(dis,0x3f,sizeof dis);
	memset(visit,0,sizeof visit);
	while(!q.empty())q.pop();
	dis[1]=0;q.push((point){1,0});
	while(!q.empty())
	{
		now=q.top();q.pop();
		if(visit[now.p])continue;
		visit[now.p]=1;
		for(auto it:s[now.p])
			if(dis[it.go]>dis[now.p]+it.data)
			{
				dis[it.go]=dis[now.p]+it.data;
				if(!visit[it.go])q.push((point){it.go,dis[it.go]});
			}
	}
	for(int i=2;i<=n;i++)ans+=dis[i];
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int u,v,t;
	
	cin>>n>>m;
	for(i=1;i<=m;i++)cin>>u>>v>>t,s1[u].emplace_back((edge){v,t}),s2[v].emplace_back((edge){u,t});
	dijkstra(s1);dijkstra(s2);
	cout<<ans;

	return 0;
}