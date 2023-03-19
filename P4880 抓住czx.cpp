#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<ext/pb_ds/priority_queue.hpp>
using namespace __gnu_pbds;
#define int long long
using std::cin;using std::cout;
struct fly{int now,time;bool operator<(const fly&n)const{return time<n.time;}};
std::vector<fly>a;
struct edge{int go,data;};
std::vector<edge>s[500007];
struct point{int p,dis;bool operator<(const point&n)const{return dis>n.dis;}};
priority_queue<point>q;
int dis[500007];bool visit[500007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,T;
	int u,v,t,begin,end;
	
	cin>>n>>m>>begin>>end;
	a.emplace_back((fly){end,0});
	for(i=1;i<=m;i++)cin>>u>>v>>t,s[u].emplace_back((edge){v,t}),s[v].emplace_back((edge){u,t});
	memset(dis,0x3f,sizeof dis);
	while(!q.empty())q.pop();
	q.push((point){begin,0});dis[begin]=0;
	while(!q.empty())
	{
		point now=q.top();q.pop();
		if(visit[now.p])continue;visit[now.p]=1;
		for(auto it:s[now.p])
			if(dis[it.go]>dis[now.p]+it.data)
			{
				dis[it.go]=dis[now.p]+it.data;
				if(!visit[it.go])q.push((point){it.go,dis[it.go]});
			}
	}
	// for(i=1;i<=n;i++)cout<<dis[i]<<' ';cout<<'\n';
	cin>>T;
	while(T--)cin>>t>>v,a.emplace_back((fly){v,t});
	std::sort(a.begin(),a.end());
	for(auto it=a.begin();it!=a.end();it++)
		if(dis[end]<it->time)return cout<<std::max(dis[end],(it-1)->time),0;
		else end=it->now;
	cout<<std::max(dis[(a.end()-1)->now],(a.end()-1)->time);
	
	return 0;
}