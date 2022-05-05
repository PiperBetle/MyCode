#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<ext/pb_ds/priority_queue.hpp>
using namespace __gnu_pbds;
using std::cin;using std::cout;
struct edge{int go,data;};
std::vector<edge>s[1000007];
int dis[1000007],visit[1000007];
struct point{int id,dis;bool operator<(const point&n)const{return dis>n.dis;}};
priority_queue<point>q;
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,ans=0x3f3f3f3f;
	int u,v,t;
	
	memset(dis,0x3f,sizeof dis);
	cin>>n>>m>>k;
	for(i=1;i<=m;i++)
	{
		cin>>u>>v>>t;
		s[u].emplace_back((edge){v,t});
		s[v].emplace_back((edge){u,t});
		for(j=1;j<=k;j++)
			s[u+(j-1)*n].emplace_back((edge){v+j*n,t>>1}),
			s[v+(j-1)*n].emplace_back((edge){u+j*n,t>>1}),
			s[u+j*n].emplace_back((edge){v+j*n,t}),
			s[v+j*n].emplace_back((edge){u+j*n,t});
	}
	dis[1]=0;q.push((point){1,0});
	while(!q.empty())
	{
		int now=q.top().id;q.pop();
		if(visit[now])continue;visit[now]=1;
		for(auto it:s[now])if(dis[it.go]>dis[now]+it.data)
		{
			dis[it.go]=dis[now]+it.data;
			if(!visit[it.go])q.push((point){it.go,dis[it.go]});
		}
	}
	for(i=0;i<=k;i++)ans=std::min(ans,dis[n+i*n]);
	cout<<ans;
	
	return 0;
}