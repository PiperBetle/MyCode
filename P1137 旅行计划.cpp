#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using std::cin;using std::cout;
std::vector<int>s[100007];
int f[100007];
inline int dfs(int i){
	if(f[i]!=0x3f3f3f3f)return f[i];
	f[i]=1;
	for(auto it:s[i])f[i]=std::max(f[i],dfs(it)+1);
	return f[i];
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,n,m,u,v;
	cin>>n>>m;
	memset(f,0x3f,sizeof f);
	for(i=1;i<=m;i++)cin>>u>>v,s[v].emplace_back(u);
	for(i=1;i<=n;i++)cout<<dfs(i)<<'\n';
	return 0;
}