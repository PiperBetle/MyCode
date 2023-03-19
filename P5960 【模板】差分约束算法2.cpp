//不向焦虑与抑郁投降，这个世界终会有我们存在的地方。
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<tuple>
#include<vector>
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
int n,m,dis[N],cnt[N];
bool vis[N];
std::vector<pii>g[N];
std::queue<int>q;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int u,v,w;m--;)cin>>u>>v>>w,g[u].emplace_back(v,-w);
	for(int i=1;i<=n;i++)g[0].emplace_back(i,0);
	memset(dis+1,-0x3f,sizeof(int)*n);
	q.push(0);vis[0]=true;
	while(!q.empty()){
		int u=q.front();q.pop();
		vis[u]=false;
		for(auto[v,w]:g[u])if(dis[v]<dis[u]+w){
			dis[v]=dis[u]+w;
			if(++cnt[v]>n)return cout<<"NO",0;
			if(!vis[v])q.push(v),vis[v]=true;
		}
	}
	for(int i=1;i<=n;i++)cout<<dis[i]<<' ';
	return 0;
}