#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using std::cin;using std::cout;
std::vector<int>s[100007];
int dis[100007];
inline void dfs(int now,int data)
{
	if(dis[now])return;
	dis[now]=data;
	for(auto it:s[now])dfs(it,data);
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,n,m,u,v;

	cin>>n>>m;
	for(i=1;i<=m;i++)cin>>u>>v,s[v].emplace_back(u);
	for(i=n;i>=1;i--)dfs(i,i);
	for(i=1;i<=n;i++)cout<<dis[i]<<' ';
	
	return 0;
}