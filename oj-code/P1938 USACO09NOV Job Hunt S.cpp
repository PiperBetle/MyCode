#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#define int long long
using std::cin;using std::cout;
struct edge{int go,data;};
std::vector<edge>s[10007];
int dis[10007],cnt[10007];
bool visit[10007];
std::queue<int>q;
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,start;
	int u,v,t,ans=0;
	int m1,m2,d;
	
	cin>>d>>m1>>n>>m2>>start;
	for(i=1;i<=m1;i++)cin>>u>>v,s[u].emplace_back((edge){v,d});
	for(i=1;i<=m2;i++)cin>>u>>v>>t,s[u].emplace_back((edge){v,d-t});
	memset(dis,0,sizeof dis);
	while(!q.empty())q.pop();
	q.push(start);visit[start]=cnt[start]=1;dis[start]=d;
	while(!q.empty())
	{
		int now=q.front();q.pop();
		visit[now]=0;
		for(auto it:s[now])
			if(dis[it.go]<dis[now]+it.data)
			{
				if(++cnt[it.go]>n)return cout<<"-1",0;
				dis[it.go]=dis[now]+it.data;
				if(visit[it.go]==0)q.push(it.go),visit[it.go]=1;
			}
	}
	for(i=1;i<=n;i++)ans=std::max(ans,dis[i]);
	cout<<ans;
	
	return 0;
}