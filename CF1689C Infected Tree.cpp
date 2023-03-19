#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
using std::cin;using std::cout;
using loli=long long;
using uloli=unsigned long long;
using lodb=long double;
using venti=__int128_t;
using pii=std::pair<int,int>;
using inlsi=const std::initializer_list<int>&;
constexpr venti operator""_vt(uloli x){return venti(x);}
constexpr int N=3e5+1;
int n,sz[N],f[N],son[N][2];
std::basic_string<int>g[N];
void dfs(int u,int fa){
	sz[u]=1;f[u]=0;
	for(int v:g[u])if(v!=fa){
		dfs(v,u);sz[u]+=sz[v];
		if(!son[u][0])son[u][0]=v;
		else son[u][1]=v;
	}
	for(int i=0;i<2;i++)f[u]=std::max(f[u],sz[son[u][i]]+f[son[u][!i]]-1);
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>n;
		for(int i=1;i<=n;i++)g[i].clear();
		memset(son+1,0,sizeof(int[2])*n);
		for(int i=1,u,v;i<n;i++)cin>>u>>v,g[u]+=v,g[v]+=u;
		dfs(1,0);
		cout<<f[1]<<'\n';
	}
	return 0;
}