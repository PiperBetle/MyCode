//不向焦虑与抑郁投降，这个世界终会有我们存在的地方。
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<tuple>
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
constexpr int N=4e5+1;
int n,m,k,a[N],dis[2][N],ans;
std::queue<int>q;
bsi g[N];
template<int Z>void bfs(int s){
	int(&d)[N]=dis[Z];
	memset(d+1,0x3f,sizeof(int)*n);
	q.push(s);d[s]=0;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int v:g[u])if(d[v]>d[u]+1)
			d[v]=d[u]+1,q.push(v);
	}
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++)cin>>a[i];
	for(int i=1,u,v;i<=m;i++)cin>>u>>v,g[u]+=v,g[v]+=u;
	bfs<0>(1);bfs<1>(n);
	std::sort(a+1,a+1+k,[](int x,int y){return dis[0][x]<dis[0][y];});
	for(int i=1;i<k;i++)cmax(ans,dis[0][a[i]]+dis[1][a[i+1]]+1);
	cout<<min(ans,dis[0][n]);
	return 0;
}