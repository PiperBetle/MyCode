#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<stack>
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
constexpr int N=2e6+1;
int n,m,idx,low[N],dfn[N],cnt,scc[N];
bool vis[N];
std::basic_string<int>g[N];
std::stack<int>s;
template<typename any>inline void cmin(any &x,const any &y){if(y<x)x=y;}
template<typename any>inline void cmax(any &x,const any &y){if(x<y)x=y;}
template<typename any,typename...args>inline void cmax(any &x,const any &y,const args &...z){cmax(x,y);cmax(x,z...);}
template<typename any,typename...args>inline void cmin(any &x,const any &y,const args &...z){cmin(x,y);cmin(x,z...);}
void tarjan(int u){
	low[u]=dfn[u]=++idx;
	s.emplace(u);vis[u]=true;
	for(int v:g[u]){
		if(!dfn[v])tarjan(v),cmin(low[u],low[v]);
		else if(vis[v])cmin(low[u],dfn[v]);
	}
	if(low[u]==dfn[u]){
		cnt++;int v;
		do{
			v=s.top();s.pop();
			vis[v]=false;
			scc[v]=cnt;
		}while(u!=v);
	}
}
bool two_SAT(){
	for(int i=1;i<=n*2;i++)if(!dfn[i])tarjan(i);
	for(int i=1;i<=n;i++)if(scc[i]==scc[i+n])return false;
	return true;
}
void add(int u,int v){g[u]+=v;}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1,a,b,x,y;i<=m;i++){
		cin>>a>>x>>b>>y;
		g[a+(x^1)*n]+=b+y*n;
		g[b+(y^1)*n]+=a+x*n;
	}
	if(two_SAT()){
		cout<<"POSSIBLE\n";
		for(int i=1;i<=n;i++)cout<<(scc[i]>scc[i+n])<<' ';
	}else cout<<"IMPOSSIBLE";
	return 0;
}