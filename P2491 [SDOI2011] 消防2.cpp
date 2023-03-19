#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<vector>
#define int loli
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
constexpr int N=3e5+1,inf=0x3f3f3f3f3f3f3f3f;
int n,m,dis[N],fat[N],ans=inf,stt,end;
bool line[N];
std::vector<pii>g[N];
void dfs1(int u,int fa){for(auto[v,w]:g[u])if(v!=fa)dis[v]=dis[u]+w,dfs1(v,u);}
void dfs2(int u,int fa){for(auto[v,w]:g[u])if(v!=fa)dis[v]=dis[u]+w,fat[v]=u,dfs2(v,u);}
void dfs3(int u,int fa){for(auto[v,w]:g[u])if(v!=fa&&!line[v])dis[v]=dis[u]+w,dfs3(v,u);}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1,u,v,w;i<n;i++)cin>>u>>v>>w,g[u].emplace_back(v,w),g[v].emplace_back(u,w);
	dis[1]=0;dfs1(1,0);for(int i=1;i<=n;i++)if(dis[i]>dis[stt])stt=i;
	dis[stt]=0;dfs2(stt,0);for(int i=1;i<=n;i++)if(dis[i]>dis[end])end=i;
	for(int i=end;i;i=fat[i])line[i]=true;
	for(int i=end,j=end;i;i=fat[i]){
		while(dis[j]-dis[i]>m)j=fat[j];
		ans=std::min(ans,std::max(dis[i],dis[end]-dis[j]));
	}
	for(int i=end;i;i=fat[i])dis[i]=0,dfs3(i,fat[i]);
	cout<<std::max(ans,*std::max_element(dis+1,dis+1+n));
	return 0;
}