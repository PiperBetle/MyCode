#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using std::cin;using std::cout;
int f[307][307],n,m;
std::vector<int>s[307];
void dfs(int u){for(int v:s[u]){dfs(v);for(int j=m;j>=1;j--)for(int k=1;k<j;k++)f[u][j]=std::max(f[u][j],f[u][j-k]+f[v][k]);}}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;m++;
	for(int i=1,u;i<=n;i++)cin>>u>>f[i][1],s[u].emplace_back(i);
	dfs(0);cout<<f[0][m];
	return 0;
}