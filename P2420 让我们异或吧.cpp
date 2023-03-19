#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using std::cin;using std::cout;
struct edge{int go,data;};
std::vector<edge>s[100007];
int d[100007],n;
void dfs(int now,int data,int fa){
	d[now]=data;
	for(auto it:s[now])if(it.go!=fa)dfs(it.go,data^it.data,now);
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,m,u,v,t;
	cin>>n;
	for(i=1;i<n;i++)cin>>u>>v>>t,s[u].emplace_back(edge{v,t}),s[v].emplace_back(edge{u,t});
	dfs(1,0,0);
	cin>>m;
	for(i=1;i<=m;i++)cin>>u>>v,cout<<(d[u]^d[v])<<'\n';
	return 0;
}
