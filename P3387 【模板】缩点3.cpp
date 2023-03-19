//不向焦虑与抑郁投降，这个世界终会有我们存在的地方。
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<tuple>
#include<stack>
#include<queue>
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
constexpr int N=10001;
bsi g1[N],g2[N];
int n1,n2,m,dc,w[N],low[N],dfn[N],bl[N],deg[N],f[N],val[N];
std::stack<int>s;
std::queue<int>q;
void tarjan(int u){
	low[u]=dfn[u]=++dc;s.push(u);
	for(int v:g1[u])
		if(!dfn[v])tarjan(v),cmin(low[u],low[v]);
		else if(!bl[v])cmin(low[u],dfn[v]);
	if(low[u]==dfn[u]){
		bl[u]=++n2;
		for(;s.top()!=u;s.pop())bl[s.top()]=n2;
		s.pop();
	}
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n1>>m;
	for(int i=1;i<=n1;i++)cin>>w[i];
	for(int u,v;m--;)cin>>u>>v,g1[u]+=v;
	for(int i=1;i<=n1;i++)if(!dfn[i])tarjan(i);
	for(int u=1;u<=n1;u++)for(int v:g1[u])if(bl[u]!=bl[v])
		deg[bl[v]]++,g2[bl[u]]+=bl[v];
	for(int i=1;i<=n1;i++)val[bl[i]]+=w[i];
	memcpy(f+1,val+1,sizeof(int)*n2);
	for(int i=1;i<=n2;i++)if(!deg[i])q.push(i);
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int v:g2[u]){
			cmax(f[v],f[u]+val[v]);
			if(!--deg[v])q.push(v);
		}
	}
	cout<<*std::max_element(f+1,f+1+n2);
	return 0;
}