#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<tuple>
#include<set>
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
constexpr int N=701;
int n,m,a[N*N],ans;
pii b[N*N];
bool vis[N*N];
inline int id(int x,int y){return (x-1)*m+y;}
inline int id(const pii x){return (x.fi-1)*m+x.se;}
void dfs(int x,int y){
	vis[id(x,y)]=true;
	for(int dx=-1;dx<=1;dx++)for(int dy=-1;dy<=1;dy++){
		if(!dx&&!dy)continue;
		int nx=x+dx,ny=y+dy;
		if(nx<1||nx>n||ny<1||ny>m||vis[id(nx,ny)]||a[id(nx,ny)]>a[id(x,y)])continue;
		dfs(nx,ny);
	}
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
		cin>>a[id(i,j)],b[id(i,j)]={i,j};
	std::sort(b+1,b+1+n*m,[](const pii &x,const pii &y){return a[id(x)]>a[id(y)];});
	for(int i=1;i<=n*m;i++){
		auto[x,y]=b[i];
		if(vis[id(x,y)]||!a[id(x,y)])continue;
		dfs(x,y);ans++;
	}
	cout<<ans;
	return 0;
}