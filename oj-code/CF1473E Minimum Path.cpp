#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<ext/pb_ds/priority_queue.hpp>
#define int long long
using std::cin;using std::cout;
template<typename any>inline any max(any x,any y){return x<y?y:x;}
template<typename any>inline any min(any x,any y){return x<y?x:y;}
struct edge{int go,data;};
std::vector<edge>s[1000007];
int dis[1000007];bool vis[1000007];
struct point{int id,dis;bool operator<(const point&n)const{return dis>n.dis;}};
__gnu_pbds::priority_queue<point>q;
signed main()
{
//	freopen("muban.in","r",stdin);
//	freopen("muban.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,n,m,u,v,t;
	cin>>n>>m;
	for(i=1;i<=m;i++)
		cin>>u>>v>>t,
		s[u].emplace_back(edge{v,t}),
		s[u].emplace_back(edge{n+v,t<<1}),
		s[u].emplace_back(edge{n*2+v,0}),
		s[n+u].emplace_back(edge{n+v,t}),
		s[n*2+u].emplace_back(edge{n*2+v,t}),
		s[n*3+u].emplace_back(edge{n*3+v,t}),
		s[n+u].emplace_back(edge{n*3+v,0}),
		s[n*2+u].emplace_back(edge{n*3+v,t<<1}),
		std::swap(u,v),
		s[u].emplace_back(edge{v,t}),
		s[u].emplace_back(edge{n+v,t<<1}),
		s[u].emplace_back(edge{n*2+v,0}),
		s[n+u].emplace_back(edge{n+v,t}),
		s[n*2+u].emplace_back(edge{n*2+v,t}),
		s[n*3+u].emplace_back(edge{n*3+v,t}),
		s[n+u].emplace_back(edge{n*3+v,0}),
		s[n*2+u].emplace_back(edge{n*3+v,t<<1});
	memset(dis,0x3f,sizeof dis);
	q.push(point{1,dis[1]=0});
	while(!q.empty())
	{
		u=q.top().id;q.pop();
		if(vis[u])continue;
		vis[u]=true;
		for(auto v:s[u])if(dis[v.go]>dis[u]+v.data){
			dis[v.go]=dis[u]+v.data;
			if(!vis[v.go])q.push(point{v.go,dis[v.go]});
		}
	}
	for(i=2;i<=n;i++)cout<<min(dis[n*3+i],dis[i])<<' ';
	return 0;
}