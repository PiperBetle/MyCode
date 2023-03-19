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
constexpr int N=3e4+1;
std::basic_string<int>g[N],ans;
bool vis[N];
int n,m;
void dfs(int u){
	vis[u]=true;
	for(int v:g[u])if(!vis[v])dfs(v);
	ans+=u;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int u,v;m--;)cin>>u>>v,g[u]+=v;
	for(int i=1;i<=n;i++)if(!vis[i])dfs(i);
	for(int i:ans)cout<<i<<' ';
	return 0;
}