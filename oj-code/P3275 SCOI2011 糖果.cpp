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
std::queue<int>q;
int vis[100007],cnt[100007],dis[100007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,ans=0;
	int u,v,t;
	
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		cin>>t>>u>>v;
		if(t==1)s[u].emplace_back((edge){v,0}),s[v].emplace_back((edge){u,0});
		else if(t==2){if(u==v)return cout<<"-1",0;s[u].emplace_back((edge){v,1});}
		else if(t==3)s[v].emplace_back((edge){u,0});
		else if(t==4){if(u==v)return cout<<"-1",0;s[v].emplace_back((edge){u,1});}
		else s[u].emplace_back((edge){v,0});
	}
	for(i=1;i<=n;i++)s[0].emplace_back((edge){i,1});
	dis[0]=0;vis[0]=cnt[0]=1;q.push(0);
	while(!q.empty())
	{
		int now=q.front();q.pop();
		if(++cnt[now]>n)return cout<<"-1",0;
		vis[now]=0;
		for(auto it:s[now])
			if(dis[it.go]<dis[now]+it.data)
			{
				dis[it.go]=dis[now]+it.data;
				if(!vis[it.go])vis[it.go]=1,q.push(it.go);
			}
	}
	for(i=1;i<=n;i++)ans+=dis[i];
	cout<<ans;
	
	return 0;
}