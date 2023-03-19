#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define int long long
using std::cin;using std::cout;
constexpr int MOD=1000000007;
std::vector<int>s[200007];
int f[200007],g[200007],m[200007],vis[200007];
inline int qp(int a,int b,int t=1){for(;b;b>>=1,a=a*a%MOD)if(b&1)t=t*a%MOD;return t;}
void pre_work(int u,int fa){f[u]=1;bool flag=false;for(int v:s[u])if(v!=fa){pre_work(v,u);if(f[v]+1==MOD&&!flag)vis[v]=1,flag=true;else f[u]=f[u]*(f[v]+1)%MOD;}if(flag)m[u]=f[u],f[u]=0;}
void dfs(int u,int fa){g[u]++;for(int v:s[u])if(v!=fa){if(!vis[v])g[v]=g[u]*f[u]%MOD*qp(f[v]+1,MOD-2)%MOD;else g[v]=g[u]*m[u]%MOD;dfs(v,u);}}
signed main(){
//	freopen("snack.in","r",stdin);
//	freopen("snack.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;cin>>n;
	for(int u=2,v;u<=n;u++)cin>>v,s[u].emplace_back(v),s[v].emplace_back(u);
	pre_work(1,0);dfs(1,0);
	for(int i=1;i<=n;i++)cout<<g[i]*f[i]%MOD<<' ';
	return 0;
}