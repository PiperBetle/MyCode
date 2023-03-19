#pragma GCC optimize(2)
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using std::cin;using std::cout;
int a[100007],in[100007],visit[100007];
std::vector<int>s1[100007],s2[100007],ans;
std::queue<int>q;
inline void dfs(int now)
{
	visit[now]=1;
	for(auto it:s2[now])
		if(!visit[it])dfs(it);
	ans.emplace_back(now);
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,cnt=0;
	int u,v,t;
	
	cin>>n>>m;
	for(i=1;i<=m;i++)cin>>a[i];
	for(i=1;i<=n;i++)for(cin>>t;t--;)
		cin>>u,s1[u].emplace_back(i),s2[i].emplace_back(u),in[i]++;
	for(i=1;i<=n;i++)if(!in[i])q.emplace(i);
	while(!q.empty())
	{
		int now=q.front();q.pop();
		for(auto it:s1[now])
			if(--in[it]==0)q.emplace(it);
	}
	for(i=1;i<=m;i++)if(in[a[i]])return cout<<"-1",0;
	for(i=1;i<=m;i++)if(!visit[a[i]])dfs(a[i]);
	cout<<ans.size()<<'\n';
	for(auto it:ans)cout<<it<<' ';
	
	return 0;
}