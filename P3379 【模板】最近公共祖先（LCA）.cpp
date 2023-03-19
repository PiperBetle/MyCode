#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
std::vector<int>s[500007];
using std::cin;using std::cout;
int n,d,dep[500007],p[500007][21];
void dfs(int now,int fa){
	dep[now]=dep[fa]+1;
	p[now][0]=fa;
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
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,k,m,u,v;
	cin>>n>>m>>k;d=log(n)/log(2)+1;
	for(i=1;i<n;i++)cin>>u>>v,s[u].emplace_back(v),s[v].emplace_back(u);
	dfs(k,0);
	for(i=1;i<=m;i++)cin>>u>>v,cout<<lca(u,v)<<'\n';
	return 0;
}