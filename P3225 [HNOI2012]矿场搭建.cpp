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
template<typename any>inline void cmin(any &x,const any &y){if(y<x)x=y;}
template<typename any>inline void cmax(any &x,const any &y){if(x<y)x=y;}
template<typename any,typename...args>inline void cmax(any &x,const any &y,const args &...z){cmax(x,y);cmax(x,z...);}
template<typename any,typename...args>inline void cmin(any &x,const any &y,const args &...z){cmin(x,y);cmin(x,z...);}
constexpr int N=1001;
std::basic_string<int>g[N];
int n,m,idx,dfn[N],low[N],vis[N],cnt,num;
loli ans1,ans2;
bool cut[N];
void tarjan(int u,int fa){
	low[u]=dfn[u]=++idx;
	int child=0;
	for(int v:g[u]){
		if(!dfn[v]){
			tarjan(v,fa);
			cmin(low[u],low[v]);
			if(low[v]>=dfn[u]&&u!=fa)cut[u]=true;
			child+=(u==fa);
		}else cmin(low[u],dfn[v]);
	}
	if(child>=2&&u==fa)cut[u]=true;
}
void dfs(int u){
	vis[u]=idx;
	if(cut[u])return;else cnt++;
	for(int v:g[u]){
		if(cut[v]&&vis[v]!=idx)num++,vis[v]=idx;
		if(!vis[v])dfs(v);
	}
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	while(cin>>m,m){
		static int cases=0;
		ans1=n=0;ans2=1;
		for(int i=1,u,v;i<=m;i++)cin>>u>>v,g[u]+=v,g[v]+=u,cmax(n,u,v);
		for(int i=1;i<=n;i++)if(!dfn[i])tarjan(i,i);
		for(int i=1;i<=n;i++)if(!vis[i]&&!cut[i]){
			idx++;cnt=num=0;dfs(i);
			if(num==0)ans1+=2,ans2*=1ll*cnt*(cnt-1)/2;
			if(num==1)ans1++,ans2*=cnt;
		}
		cout<<"Case "<<++cases<<": "<<ans1<<' '<<ans2<<'\n';
		for(int i=1;i<=n;i++)g[i].clear();
		memset(dfn+1,0,sizeof(int)*n);
		memset(low+1,0,sizeof(int)*n);
		memset(vis+1,0,sizeof(int)*n);
		memset(cut+1,0,sizeof(bool)*n);
	}
	return 0;
}