//不向焦虑与抑郁投降，这个世界终会有我们存在的地方。
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<tuple>
#include<ctime>
#include<random>
#include<queue>
#if __cplusplus>=202002L
#include<ranges>
namespace vw=std::views;
#endif
struct _time{~_time(){std::cerr<<"\n\033[33;40m"<<1.*clock()/CLOCKS_PER_SEC<<"s\033[37;40m";}}_TM;
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) std::begin(x),std::end(x)
#define rall(x) std::rbegin(x),std::rend(x)
#define sqrt __builtin_sqrt
#define fi first
#define se second
#define continue(x...) {x;continue;}
#define break(x...) {x;break;}
using std::cin;using std::cout;
using std::max;using std::min;
using std::tie;using std::ignore;
template<typename any>inline void cmin(any &x,const any &y){if(y<x)x=y;}
template<typename any>inline void cmax(any &x,const any &y){if(x<y)x=y;}
template<typename any,typename...args>inline void cmin(any &x,const any &y,const args &...z){cmin(x,y);cmin(x,z...);}
template<typename any,typename...args>inline void cmax(any &x,const any &y,const args &...z){cmax(x,y);cmax(x,z...);}
using loli=long long;
using unt=unsigned;
using lolu=unsigned long long;
using lodb=long double;
using venti=__int128_t;
using pii=std::pair<int,int>;
using tiii=std::tuple<int,int,int>;
using inlsi=const std::initializer_list<int>&;
using bsi=std::basic_string<int>;
using bsl=std::basic_string<loli>;
using bsc=std::string;
using std::operator""s;
#if __cplusplus>=201703L
using bscv=std::string_view;
using std::operator""sv;
#endif
std::mt19937 rng(std::random_device{}());
constexpr venti operator""_vt(lolu x){return venti(x);}
constexpr bool ying=false,yang=true;
constexpr int N=200001;
int n,m,k,lt,fa[N];
bsi b,g[N];
std::queue<int>q;
bool del[N],vis[N];
inline int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
inline void merge(int x,int y){if((x=find(x))!=(y=find(y)))fa[x]=y;}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1,u,v;i<=m;i++){
		cin>>u>>v;if(u>v)std::swap(u,v);
		if(u!=1)g[u]+=v,g[v]+=u,merge(u,v);
		else b+=v;
	}
	for(int i=2;i<=n;i++)lt+=(find(i)==i);
	if(k>siz(b)||k<lt)return cout<<"NO",0;else cout<<"YES\n";
	for(int i=0;i<siz(b);i++)if(int v=b[i];!del[find(v)])
		g[1]+=v,g[v]+=1,k--,del[find(v)]=true,b[i]=0;
	for(int i=0;i<siz(b)&&k;i++)if(int v=b[i])
		g[1]+=v,g[v]+=1,k--;
	q.push(1);vis[1]=true;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int v:g[u])if(!vis[v])
			vis[v]=true,q.push(v),
			cout<<u<<' '<<v<<'\n';
	}
	return 0;
}