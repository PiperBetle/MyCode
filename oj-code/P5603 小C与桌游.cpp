#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<ext/pb_ds/priority_queue.hpp>
using namespace __gnu_pbds;
using std::cin;using std::cout;
std::vector<int>s[500007];
int in[500007];bool vis[500007];
priority_queue<int,std::greater<int>>q1;
priority_queue<int,std::less<int>>q2;
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,h;
	int u,v,t;
	
	cin>>n>>m;
	for(i=1;i<=m;i++)cin>>u>>v,s[u].emplace_back(v),in[v]++;
	for(i=1;i<=n;i++)if(!in[i])q1.push(i);
	int ans1=0,maxn=0;
	while(!q1.empty())
	{
		int now=q1.top();q1.pop();
		if(now>maxn)maxn=now,ans1++;
		for(auto it:s[now])if(!--in[it])q1.push(it);
	}
	
	memset(in,0,sizeof in);
	for(i=1;i<=n;i++)for(auto it:s[i])in[it]++;
	for(i=1;i<=n;i++)if(!in[i])q1.push(i),q2.push(i);
	int ans2=0;maxn=0;
	while(!q2.empty())
	{
		int now=q2.top();q2.pop();
		if(vis[now])continue;vis[now]=1;
		if(now>maxn)maxn=now,ans2++;
		for(auto it:s[now])if(!--in[it])q1.push(it),q2.push(it);
		while(!q1.empty()&&q1.top()<=maxn)
		{
			now=q1.top();q1.pop();
			if(vis[now])continue;vis[now]=1;
			for(auto it:s[now])if(!--in[it])q1.push(it),q2.push(it);
		}
	}
	cout<<ans1<<'\n'<<ans2;
	
	return 0;
}