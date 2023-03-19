//不向焦虑与抑郁投降，这个世界终会有我们存在的地方。
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<tuple>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
using std::cin;using std::cout;
using std::max;using std::min;
using std::tie;using std::ignore;
template<typename any>inline void cmin(any &x,const any &y){if(y<x)x=y;}
template<typename any>inline void cmax(any &x,const any &y){if(x<y)x=y;}
template<typename any,typename...args>inline void cmax(any &x,const any &y,const args &...z){cmax(x,y);cmax(x,z...);}
template<typename any,typename...args>inline void cmin(any &x,const any &y,const args &...z){cmin(x,y);cmin(x,z...);}
using loli=long long;
using uloli=unsigned long long;
using lodb=long double;
using venti=__int128_t;
using pii=std::pair<int,int>;
using inlsi=const std::initializer_list<int>&;
using bsi=std::basic_string<int>;
using bsc=std::basic_string<char>;
constexpr venti operator""_vt(uloli x){return venti(x);}
constexpr int N=2e4+1;
int n,m,dc,dfn[N],low[N];
bsi g[N];
bool cut[N];
void tarjan(int u,bool top){
	low[u]=dfn[u]w=++dc;
	int child=0;
	for(int v:g[u])
		if(!dfn[v]){
			tarjan(v,false);
			cmin(low[u],low[v]);
			if(low[v]>=dfn[u]&&!top)cut[u]=true;
			child+=top;
		}else cmin(low[u],dfn[v]);
	if(child>=2)cut[u]=true;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1,u,v;i<=m;i++)cin>>u>>v,g[u]+=v,g[v]+=u;
	for(int i=1;i<=n;i++)if(!dfn[i])tarjan(i,true);
	cout<<std::count(cut+1,cut+1+n,true)<<'\n';
	for(int i=1;i<=n;i++)if(cut[i])cout<<i<<' ';
	return 0;
}