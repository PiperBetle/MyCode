#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<vector>
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
constexpr int N=200001;
int n,a[N],dis[N];
std::vector<pii>g[N];
void dfs(int u,int fa){for(auto[v,w]:g[u])if(v!=fa){dis[v]=std::min(dis[u]+w,dis[v]);dfs(v,u);}}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1,u,v;i<n;i++)cin>>u>>v,g[u].emplace_back(v,a[u]!=a[v]),g[v].emplace_back(u,a[u]!=a[v]);
	memset(dis+1,0x3f,sizeof(int)*n);dis[1]=0;dfs(1,0);int p1=int(std::max_element(dis+1,dis+1+n)-dis);
	memset(dis+1,0x3f,sizeof(int)*n);dis[p1]=0;dfs(p1,0);int p2=int(std::max_element(dis+1,dis+1+n)-dis);
	cout<<(dis[p2]+1)/2;
	return 0;
}