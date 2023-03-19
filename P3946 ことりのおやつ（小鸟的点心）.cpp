#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#define int long long
using std::cin;using std::cout;
struct edge{int go,data;};
std::vector<edge>s[100007];
struct point{int h,l;}a[100007];
std::queue<int>que;
int dis[100007];
bool vis[100007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,n,m,t,start,end,g,q,u,v,now;
	cin>>n>>m>>start>>end>>g>>q;
	for(i=1;i<=n;i++)cin>>a[i].h>>a[i].l;
	while(m--)cin>>u>>v>>t,s[u].emplace_back(edge{v,t}),s[v].emplace_back(edge{u,t});
	memset(dis,0x3f,sizeof dis);
	while(!que.empty())que.pop();
	que.push(start);dis[start]=0;
	while(!que.empty())
	{
		vis[now=que.front()]=false;que.pop();
		for(auto it:s[now])if((dis[it.go]>dis[now]+it.data)&&(a[it.go].h+(dis[now]+it.data)*q<=a[it.go].l||it.go==end))
		{
			dis[it.go]=dis[now]+it.data;
			if(!vis[it.go])vis[it.go]=true,que.push(it.go);
		}
	}
	if(dis[end]>g)cout<<"wtnap wa kotori no oyatsu desu!\n";else cout<<dis[end];
	return 0;
}