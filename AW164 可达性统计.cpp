#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<bitset>
std::vector<int>s[30007];
bool vis[30007];
std::bitset<30007>f[30007];
using std::cin;using std::cout;
std::bitset<30007>dfs(int now){
	if(vis[now])return f[now];else vis[now]=true;
	for(auto it:s[now])f[now]|=dfs(it);
	return f[now];
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,n,m,u,v;
	cin>>n>>m;
	for(i=1;i<=n;i++)f[i][i]=true;
	for(i=1;i<=m;i++)cin>>u>>v,s[u].emplace_back(v);
	for(i=1;i<=n;i++)cout<<dfs(i).count()<<'\n';
	return 0;
}