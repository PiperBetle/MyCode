#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<tuple>
#include<vector>
#include<deque>
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
constexpr int N=2501,dx[]={-1,1,0,0},dy[]={0,0,-1,1},inf=0x3f3f3f3f;
int n,m,a[N],dis[N],ans=inf;
std::vector<pii>g[N];
std::deque<int>q;
inline int id(int x,int y){return (x-1)*m+y;}
int bfs(int s){
	int res=0;
	memset(dis+1,0x3f,sizeof(int)*n*m);
	q.push_back(s);dis[s]=0;
	while(!q.empty()){
		int u=q.front();q.pop_front();
		if(a[u])cmax(res,dis[u]);
		for(auto[v,w]:g[u])if(dis[u]+w<dis[v]){
			dis[v]=dis[u]+w;
			if(w)q.push_back(v);
			else q.push_front(v);
		}
	}
	return res;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){char c;cin>>c;a[i]=(c=='B');}
	if(!*std::max_element(a+1,a+1+n*m))return cout<<0,0;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)for(int k=0;k<4;k++){
		int nx=i+dx[k],ny=j+dy[k];
		if(nx<1||ny<1||nx>n||ny>m)continue;
		g[id(i,j)].emplace_back(id(nx,ny),a[id(i,j)]!=a[id(nx,ny)]);
	}
	for(int i=1;i<=n*m;i++)cmin(ans,bfs(i));
	cout<<ans+1;
	return 0;
}