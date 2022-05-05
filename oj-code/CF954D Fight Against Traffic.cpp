#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<ext/pb_ds/priority_queue.hpp>
using namespace __gnu_pbds;
using std::cin;using std::cout;
std::vector<int>s[1007];
int dis[2][1007],n,m;bool vis[1007];
struct point{int id,dis;bool operator<(const point&n)const{return dis>n.dis;}};
priority_queue<point>q;
inline void dijkstra(int x,int*dis)
{
	int i;
	for(i=0;i<=n;i++)dis[i]=0x3f3f3f3f,vis[i]=false;
	dis[x]=0;vis[x]=true;
	while(!q.empty())q.pop();
	q.push(point{x,0});
	while(!q.empty())
	{
		int now=q.top().id;q.pop();
		for(auto it:s[now])if(dis[it]>dis[now]+1)
		{
			dis[it]=dis[now]+1;
			if(!vis[it])vis[it]=1,q.push(point{it,dis[it]});
		}
	}
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,u,v,start,end,ans;
	cin>>n>>m>>start>>end;
	for(ans=-m,i=1;i<=m;i++)cin>>u>>v,s[u].emplace_back(v),s[v].emplace_back(u);
	dijkstra(start,dis[0]);
	dijkstra(end,dis[1]);
	for(i=1;i<n;i++)for(j=i+1;j<=n;j++)
		if(dis[0][i]+dis[1][j]+1>=dis[0][end]&&dis[0][j]+dis[1][i]+1>=dis[0][end])ans++;
	cout<<ans;
	return 0;
}