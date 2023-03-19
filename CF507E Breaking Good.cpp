#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using std::cin;using std::cout;
struct edge{int go,data;};
std::vector<edge>s[100007];
int dis[100007],f[100007],pre[100007],a[100007];
std::queue<int>q;
struct line{int u,v,t;};
std::vector<line>e;
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,sum=0;
	int u,v,t;
	
	memset(dis,0x3f,sizeof dis);
	cin>>n>>m;
	for(i=1;i<=m;i++)
		cin>>u>>v>>t,sum+=t,
		s[u].emplace_back((edge){v,t}),
		s[v].emplace_back((edge){u,t}),
		e.emplace_back((line){u,v,t});
	dis[1]=0;q.push(1);
	while(!q.empty())
	{
		int now=q.front();q.pop();
		for(auto it:s[now])
			if(dis[it.go]>dis[now]+1)
				dis[it.go]=dis[now]+1,pre[it.go]=now,
				f[it.go]=f[now]+(it.data^1),q.push(it.go);
			else if(dis[it.go]==dis[now]+1&&f[now]+(it.data^1)<f[it.go])
				pre[it.go]=now,f[it.go]=f[now]+(it.data^1);
	}
	cout<<sum-dis[n]+(f[n]<<1)<<'\n';
	for(i=n;i!=1;i=pre[i])a[i]=pre[i];
	for(auto it:e)
		if(a[it.u]==it.v||a[it.v]==it.u){if(!it.t)cout<<it.u<<' '<<it.v<<" 1\n";}
		else if(it.t)cout<<it.u<<' '<<it.v<<" 0\n";
	
	return 0;
}