#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
std::vector<int>s[500007];
using std::cin;using std::cout;
int n,d,dep[500007],p[500007][21],m;
void dfs(int now,int fa){
	dep[now]=dep[fa]+1;p[now][0]=fa;
	for(int i=1;(1<<i)<=dep[now];i++)p[now][i]=p[p[now][i-1]][i-1];
	for(auto it:s[now])if(it!=fa)dfs(it,now);
}
int lca(int a,int b){
	if(dep[a]>dep[b])std::swap(a,b);
	for(int i=d;i>=0;i--)if(dep[a]<=dep[b]-(1<<i))b=p[b][i];
	if(a==b)return a;
	for(int i=d;i>=0;i--)if(p[a][i]!=p[b][i])a=p[a][i],b=p[b][i];
	return p[a][0];
}
signed main(){
//	freopen(".in","r",stdin);freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;d=std::__lg(n);
	for(int i=1,u,v;i<n;i++)cin>>u>>v,s[u].emplace_back(v),s[v].emplace_back(u);
	dfs(1,0);cin>>m;
	for(int i=1,u,v;i<=m;i++)cin>>u>>v,cout<<dep[u]+dep[v]-2*dep[lca(u,v)]<<'\n';
	return 0;
}