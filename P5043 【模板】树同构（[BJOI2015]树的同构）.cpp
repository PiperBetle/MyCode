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
constexpr int N=51;
int n,m,h,d[N],sz[N];
std::basic_string<int>g[N],f[N],mn;
std::vector<std::basic_string<int>>ans,t[N];
void dfs1(int u,int fa){
	sz[u]=1;
	for(int v:g[u])if(v!=fa){
		dfs1(v,u);
		sz[u]+=sz[v];
		d[u]=std::max(d[u],sz[v]);
	}
	h=std::min(h,d[u]=std::max(d[u],n-sz[u]));
}
void dfs2(int u,int fa){
	t[u].clear();f[u]=0;
	for(int v:g[u])if(v!=fa)dfs2(v,u),t[u].push_back(f[v]);
	std::sort(all(t[u]));
	for(cauto&i:t[u])f[u]+=i;
	f[u]+=1;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>m;while(m--){
		cin>>n;h=n+1;
		for(int i=1;i<=n;i++)g[i].clear(),d[i]=0;
		for(int v=1,u;v<=n;v++){cin>>u;if(u)g[u]+=v,g[v]+=u;}
		dfs1(1,0);mn=1;
		for(int i=1;i<=n;i++)if(d[i]==h)dfs2(i,0),mn=std::min(mn,f[i]);
		ans.push_back(mn);
		cout<<std::find(all(ans),mn)-ans.begin()+1<<'\n';
	}
	return 0;
}