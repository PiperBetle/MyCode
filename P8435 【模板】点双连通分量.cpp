#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<stack>
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
constexpr int kN=1000001;
int n,m,low[kN],dfn[kN],idx;
bool cut[kN];
std::basic_string<int>g[kN];
std::stack<int>s;
void tarjan(int u,int fa){
	low[u]=dfn[u]=++idx;
	int child=0;
	for(int v:g[u]){
		child++;
		if(dfn[v])continue;
		s.emplace(u,v);
		tarjan(v,u);
		chkmin(low[u],low[v]);
		if(low[v]>=dfn[u]){
			
		}
	}
	if(child>=2&&u==fa)cut[u]=true;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1,u,v;i<=m;i++){cin>>u>>v;if(u!=v)g[u]+=v,g[v]+=u};
	for(int i=1;i<=n;i++)if(!dfn[i])tarjan(i,i);
	cout<<std::count(cut+1,cut+1+n,true)<<'\n';
	return 0;
}