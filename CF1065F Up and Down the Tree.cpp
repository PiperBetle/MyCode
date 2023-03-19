#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
#define cauto const auto
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=1e6+1;
std::basic_string<int>s[kN];
int n,k,f[kN],g[kN],h[kN];
void dfs(int u){
	if(s[u].empty()){
		h[u]=k;
		f[u]=g[u]=1;
		return;
	}
	h[u]=f[u]=g[u]=0;
	for(int v:s[u]){
		dfs(v);
		h[u]=std::max(h[v]-1,h[u]);
		if(h[v]>0)f[u]+=f[v];
	}
	for(int v:s[u]){
		if(h[v]>0)g[u]=std::max(g[u],f[u]-f[v]+g[v]);
		else g[u]=std::max(g[u],f[u]+g[v]);
	}
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>k;
	for(int u,v=2;v<=n;v++)cin>>u,s[u]+=v;
	dfs(1);cout<<g[1];
	return 0;
}