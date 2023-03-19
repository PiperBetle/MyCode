#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define int long long
using std::cin;using std::cout;
int n,size[1000007],dep[1000007],f[1000007],ans=1;
std::vector<int>s[1000007];
void pre_work(int u,int fa){
	size[u]=1,f[1]+=dep[u]=dep[fa]+1;
	for(int v:s[u])if(fa!=v)
		pre_work(v,u),size[u]+=size[v];
}
void dfs(int u,int fa){
	for(int v:s[u])if(fa!=v)
		f[v]=f[u]+n-(size[v]<<1),dfs(v,u);
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
//	cin.tie(nullptr);
	cin>>n;
	for(int i=1,u,v;i<n;i++)cin>>u>>v,s[u].emplace_back(v),s[v].emplace_back(u);
	pre_work(1,0);dfs(1,0);
	for(int i=2;i<=n;i++)if(f[i]>f[ans])ans=i;
	cout<<ans;
	return 0;
}