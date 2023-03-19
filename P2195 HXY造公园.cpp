#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
std::vector<int>s[300007];
int f[300007],d[300007],c;
using std::cin,std::cout;
inline int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void dfs(int u,int fa){
	int d1=0,d2=0;
	for(auto v:s[u]){
		if(v==fa)continue;else dfs(v,u);
		d[u]=std::max(d[u],d[v]+1);
		if(d[v]+1>d1)d2=d1,d1=d[v]+1;
		else if(d[v]+1>d2)d2=d[v]+1;
	}
	c=std::max(c,d1+d2);
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,n,m,q,u,v,t,x,y,fx,fy;
	cin>>n>>m>>q;
	for(i=1;i<=n;i++)f[i]=i;
	for(i=1;i<=m;i++){
		cin>>u>>v,s[u].emplace_back(v),s[v].emplace_back(u);
		fx=find(u),fy=find(v);
		if(fx!=fy)f[fx]=fy;
	}
	for(i=1;i<=n;i++)if(find(i)==i)dfs(i,c=0),d[i]=c;
	while(q--){
		cin>>t>>x;
		if(t==1){cout<<d[find(x)]<<'\n';continue;}else cin>>y,fx=find(x),fy=find(y);
		if(fx!=fy)d[f[fx]=fy]=std::max({d[fx],d[fy],((d[fx]+1)>>1)+((d[fy]+1)>>1)+1});
	}
	return 0;
}