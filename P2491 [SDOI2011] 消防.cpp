#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<vector>
#include<queue>
#include<deque>
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
constexpr int N=3e5+2,inf=0x3f3f3f3f;
int n,m,dis[N],fat[N],gtp[N],diy[N],sum[N],ans=inf,stt,end;
std::vector<pii>g[N];
std::queue<pii>q;
std::deque<int>res;
void dfs1(int u,int fa){for(auto[v,w]:g[u])if(v!=fa){dis[v]=dis[u]+w;dfs1(v,u);}}
void dfs2(int u,int fa){for(auto[v,w]:g[u])if(v!=fa){dis[v]=dis[u]+w;fat[v]=u;gtp[u]=w;dfs2(v,u);}}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1,u,v,w;i<n;i++)cin>>u>>v>>w,g[u].emplace_back(v,w),g[v].emplace_back(u,w);
	dfs1(1,0);for(int i=1;i<=n;i++)if(dis[i]>dis[stt])stt=i;
	dfs2(stt,0);for(int i=1;i<=n;i++)if(dis[i]>dis[end])end=i;
	memset(dis+1,0x3f,sizeof(int)*n);
	for(int i=end;i;i=fat[i])q.emplace(i,i),dis[i]=0;
	while(!q.empty()){
		auto[u,top]=q.front();q.pop();
		for(auto[v,w]:g[u])if(dis[v]==inf){
			diy[top]=std::max(diy[top],dis[v]=dis[u]+w);
			q.emplace(v,top);
		}
	}
	cout<<"================\n";
	fat[n+1]=end;
	for(int i=n+1;i;i=fat[i])sum[fat[i]]=sum[i]+gtp[i];
	for(int l=end,r=end;l&&r!=stt;l=fat[l]){
		int lst=r;
		if(!res.empty())res.pop_front();
		while(sum[r]-sum[l]<=m&&r){
			lst=r;r=fat[r];
			if(r&&sum[r]-sum[l]<=m){
				for(;!res.empty()&&diy[r]>=res.back();)res.pop_back();
				res.push_back(diy[r]);
			}
		}
		if(!r||sum[r]-sum[l]>m)r=lst;
		ans=std::min(ans,std::max({sum[l],sum[stt]-sum[r],res.empty()?0:res.back()}));
	}
	cout<<ans;
	return 0;
}