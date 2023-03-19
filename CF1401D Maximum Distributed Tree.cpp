#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<queue>
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
using bsi=std::basic_string<int>;
constexpr venti operator""_vt(uloli x){return venti(x);}
constexpr int N=1e6+1,MOD=1e9+7;
int n,m,p[N],sz[N],ans,sum[N];
std::priority_queue<int,std::vector<int>,std::less<int>>q;
bsi g[N];
inline void dfs(int u,int fa){
	sz[u]=1;
	for(int v:g[u])if(v!=fa)
		dfs(v,u),sz[u]+=sz[v];
	q.push((n-sz[u])*sz[u]);
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>n;ans=0;
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1,u,v;i<n;i++)cin>>u>>v,g[u]+=v,g[v]+=u;
		dfs(1,0);
		cin>>m;
		for(int i=1;i<=m;i++)cin>>p[i];
		std::sort(p+1,p+1+m);n--;
		if(m>n){for(int i=n+1;i<=m;i++)(p[n]*=p[i])%=MOD;m=n;}
		while(!q.empty()){
			(ans+=std::max(1ll,p[m--])*q.top())%=MOD;
			q.pop();if(m<0)m=0;
		}
		cout<<ans<<'\n';
	}
	return 0;
}