#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using std::cin;using std::cout;
int f[6007][2],in[6007];
std::vector<int>s[6007];
void dfs(int u){for(int v:s[u]){dfs(v),f[u][0]+=std::max(f[v][0],f[v][1]),f[u][1]+=f[v][0];}}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>f[i][1];
	for(int i=1,u,v;i<n;i++)cin>>v>>u,s[u].emplace_back(v),in[v]++;
	for(int i=1;i<=n;i++){if(!in[i]){dfs(i);return cout<<std::max(f[i][0],f[i][1]),0;}}
}