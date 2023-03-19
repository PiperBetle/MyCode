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
#define rall(x) (x).rbegin(),(x).rend()
#define fi first
#define se second
#define sqrt __builtin_sqrt
#define continue(x) {x;continue;}
#define break(x) {x;break;}
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
constexpr bool ying=false,yang=true;
constexpr int N=2e5+1,M=int(sqrt(N));
bsi g[N];
bool v1[N],v2[N];
int n,m,p1,p2,c1,c2;
void dfs1(int u){v1[u]=true;for(int v:g[u])if(!v1[v]&&v!=p2)dfs1(v);}
void dfs2(int u){v2[u]=true;for(int v:g[u])if(!v2[v]&&v!=p1)dfs2(v);}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>n>>m>>p1>>p2;c1=c2=0;
		memset(v1+1,0,sizeof(bool)*n);memset(v2+1,0,sizeof(bool)*n);
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1,u,v;i<=m;i++)cin>>u>>v,g[u]+=v,g[v]+=u;
		dfs1(p1);dfs2(p2);
		for(int i=1;i<=n;i++)c1+=(v1[i]&&!v2[i]&&i!=p1),c2+=(!v1[i]&&v2[i]&&i!=p2);
		cout<<1ll*c1*c2<<'\n';
	}
	return 0;
}