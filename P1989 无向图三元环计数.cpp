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
constexpr int N=1e5+1,M=2e5+1;
int n,m,deg[N],ans;
std::basic_string<int>g[N];
pii e[M];
bool vis[N];
bool cmp(int u,int v){return deg[u]>deg[v]||(deg[u]==deg[v]&&u>v);}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=m;i++)cin>>e[i].fi>>e[i].se,deg[e[i].fi]++,deg[e[i].se]++;
	for(int i=1;i<=m;i++)if(cmp(e[i].fi,e[i].se))g[e[i].se]+=e[i].fi;else g[e[i].fi]+=e[i].se;
	for(int u=1;u<=n;u++){
		for(int v:g[u])vis[v]=true;
		for(int v:g[u])for(int w:g[v])ans+=vis[w];
		for(int v:g[u])vis[v]=false;
	}
	cout<<ans;
	return 0;
}