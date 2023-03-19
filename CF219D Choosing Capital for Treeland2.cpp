#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<vector>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
using std::cin;using std::cout;
using std::max;using std::min;
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
constexpr venti operator""_vt(uloli x){return venti(x);}
constexpr int N=2e5+1;
int n,m,f[N];
std::vector<pii>g[N];
void dfs1(int u,int fa){for(auto[v,w]:g[u])if(v!=fa)f[1]+=w,dfs1(v,u);}
void dfs2(int u,int fa){for(auto[v,w]:g[u])if(v!=fa)f[v]=f[u]+(w?-1:1),dfs2(v,u);}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1,u,v;i<n;i++)cin>>u>>v,g[u].emplace_back(v,0),g[v].emplace_back(u,1);
	dfs1(1,0);dfs2(1,0);
	cout<<(m=*std::min_element(f+1,f+1+n))<<'\n';
	for(int i=1;i<=n;i++)if(m==f[i])cout<<i<<' ';
	return 0;
}