#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
struct edge{int go,data;};
std::vector<edge>s[107];
int n,m,f[107][107];
using std::cin;using std::cout;
void dfs(int u,int fa){
	for(auto v:s[u]){
		if(v.go==fa)continue;else dfs(v.go,u);
		for(int j=m;j>=1;j--)for(int i=0;i<j;i++)
			f[u][j]=std::max(f[u][j],f[v.go][i]+f[u][j-i-1]+v.data);
	}
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1,u,v,t;i<n;i++)cin>>u>>v>>t,s[u].emplace_back(edge{v,t}),s[v].emplace_back(edge{u,t});
	dfs(1,0);cout<<f[1][m];
	return 0;
}