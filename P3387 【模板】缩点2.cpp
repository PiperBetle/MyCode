#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<stack>
#include<queue>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
template<typename any>inline void chkmin(any &x,const any &y){if(y<x)x=y;}
template<typename any>inline void chkmax(any &x,const any &y){if(x<y)x=y;}
template<typename any,typename...args>inline void chkmax(any &x,const any &y,const args &...z){chkmax(x,y);chkmax(x,z...);}
template<typename any,typename...args>inline void chkmin(any &x,const any &y,const args &...z){chkmin(x,y);chkmin(x,z...);}
constexpr int kN=10001;
int n,m,dfn[kN],low[kN],cnt,bl[kN],siz[kN],idx,in[kN],w[kN],val[kN],f[kN];
std::basic_string<int>g1[kN],g2[kN],b;
bool vis[kN];
std::stack<int>s;
std::queue<int>q;
void tarjan(int u){
	low[u]=dfn[u]=++idx;
	vis[u]=true;s.push(u);
	for(int v:g1[u])
		if(!dfn[v])tarjan(v),chkmin(low[u],low[v]);
		else if(vis[v])chkmin(low[u],dfn[v]);
	if(low[u]==dfn[u]){
		bl[u]=++cnt,vis[u]=false,siz[cnt]++;
		for(;s.top()!=u;s.pop())bl[s.top()]=cnt,vis[s.top()]=false,siz[cnt]++;
		s.pop();
	}
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>w[i];
	for(int i=1,u,v;i<=m;i++)cin>>u>>v,g1[u]+=v;
	for(int i=1;i<=n;i++)if(!dfn[i])tarjan(i);
	for(int i=1;i<=n;i++)for(int v:g1[i])if(bl[i]!=bl[v])in[bl[v]]++,g2[bl[i]]+=bl[v];
	for(int i=1;i<=n;i++)val[bl[i]]+=w[i];
	memcpy(f+1,val+1,sizeof(int)*cnt);
	for(int i=1;i<=cnt;i++)if(!in[i])q.push(i);
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int v:g2[u]){
			chkmax(f[v],f[u]+val[v]);
			if(!--in[v])q.push(v);
		}
	}
	cout<<*std::max_element(f+1,f+1+cnt);
	return 0;
}