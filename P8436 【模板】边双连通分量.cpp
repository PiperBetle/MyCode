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
constexpr int kN=2e5+1;
std::basic_string<int>d,g[kN];
int n,m,dfn[kN],low[kN],idx;
std::stack<int>s;
std::basic_string<bool>bri;
void tarjan(int u,int fr){
	low[u]=dfn[u]=++idx;
	s.push(u);
	for(int i:g[u]){
		int v=d[i];
		if(!dfn[v]){
			tarjan(v,i);
			chkmin(low[u],low[v]);
			if(dfn[u]<low[v])bri[i]=bri[i^1]=false;
		}else if(i!=(fa^1))low
	}
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int u,v;m--;)cin>>u>>v,g[u]+=siz(d),d+=v,g[v]+=siz(d),d+=u;
	bri.resize(siz(d));
	for(int i=1;i<=n;i++)if(!dfn[i])
	return 0;
}