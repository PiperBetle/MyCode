#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#define int long long
using std::cin;using std::cout;
bool a[100007],vis[100007];
int n,m,cnt;
std::vector<int>s[100007];
void dfs(int now,int data)
{
	if(data>m)return;
	vis[now]=1;bool flag=1;
	for(auto it:s[now])if(!vis[it])
		flag=0,dfs(it,a[it]?data+1:0);
	if(flag)cnt++;
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,u,v;
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=1;i<n;i++)cin>>u>>v,s[u].emplace_back(v),s[v].emplace_back(u);
	dfs(1,a[1]);
	cout<<cnt;
	return 0;
}