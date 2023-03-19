//不向焦虑与抑郁投降，这个世界终会有我们存在的地方。
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<tuple>
#include<vector>
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
constexpr int N=3e5+1;
int n,m,q,deg[N],V,E,D,C,fa[N],sz[N],g[N];
pii ans[N];
struct node{
	int u,v,w;
	node(int x,int y,int z):u(x),v(y),w(z){}
	friend bool operator<(const node &x,const node &y){
		return x.w==y.w?x.v>y.v:x.w>y.w;
	}
};
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void merge(int x,int y){
	if((x=find(x))==(y=find(y)))return;
	C-=sz[x]==g[x];C-=sz[y]==g[y];
	fa[y]=x;sz[x]+=sz[y];g[x]+=g[y];
	C+=sz[x]==g[x];
}
void add(int x){
	int y=find(x);
	if(!deg[x])V++;
	if(deg[x]==2)D--,C-=sz[y]==g[y],g[y]--;
	if(++deg[x]==2)D++,g[y]++,C+=sz[y]==g[y];
}
std::vector<node>b;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1,u,v,w;i<=m;i++)cin>>u>>v>>w,b.emplace_back(u,v,w);
	cin>>q;
	for(int i=1,x;i<=q;i++)cin>>x,b.emplace_back(i,0,x);
	for(int i=1;i<=n;i++)fa[i]=i,sz[i]=1,g[i]=0;
	sort(all(b));
	for(auto[u,v,w]:b)
		if(!v)ans[u]={V-D+C,E-D+C};
		else E++,merge(u,v),add(u),add(v);
	for(int i=1;i<=q;i++)cout<<ans[i].fi<<' '<<ans[i].se<<'\n';
	return 0;
}