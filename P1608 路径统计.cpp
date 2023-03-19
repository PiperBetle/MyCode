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
std::vector<edge>s[2007];
int dis[4000007],ans[4000007],a[2007][2007];
bool visit[4000007];
struct point{int p,dis;bool operator<(const point&n)const{return dis>n.dis;}}now;
priority_queue<point>q;
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m;
	int u,v,t;
	
	cin>>n>>m;
	memset(dis,0x3f,sizeof dis);
	memset(a,0x3f,sizeof a);
	for(i=1;i<=m;i++)cin>>u>>v>>t,a[u][v]=std::min(a[u][v],t);
	for(i=1;i<=n;i++)for(j=1;j<=n;j++)if(i!=j&&a[i][j])s[i].emplace_back((edge){j,a[i][j]});
	dis[1]=0;q.push((point){1,0});ans[1]=1;
	while(!q.empty())
	{
		now=q.top();q.pop();
		if(visit[now.p])continue;
		visit[now.p]=1;
		for(auto it:s[now.p])
			if(dis[it.go]>dis[now.p]+it.data)
			{
				ans[it.go]=ans[now.p];
				dis[it.go]=dis[now.p]+it.data;
				if(!visit[it.go])q.push((point){it.go,dis[it.go]});
			}
			else if(dis[it.go]==dis[now.p]+it.data)ans[it.go]+=ans[now.p];
	}
	if(dis[n]==0x3f3f3f3f3f3f3f3f)cout<<"No answer";
	else cout<<dis[n]<<' '<<ans[n];
	
	return 0;
}