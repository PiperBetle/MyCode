#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<tuple>
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
constexpr int N=501,dx[]={1,-1,0,0},dy[]={0,0,1,-1};
int n,m,l[N][N],r[N][N],h[N][N];
bool vis[N][N];
inline void dfs(int x,int y){
	vis[x][y]=true;
	for(int i=0;i<4;i++){
		int nx=x+dx[i],ny=y+dy[i];
		if(nx<1||nx>n||ny<1||ny>m||h[nx][ny]>=h[x][y])continue;
		if(!vis[nx][ny])dfs(nx,ny);
		cmin(l[x][y],l[nx][ny]);
		cmax(r[x][y],r[nx][ny]);
	}
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	memset(l,0x3f,sizeof l);
	cin>>n>>m;
	for(int i=1;i<=m;i++)l[n][i]=r[n][i]=i;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>h[i][j];
	for(int i=1;i<=m;i++)if(!vis[1][i])dfs(1,i);
	if(int cnt=int(std::count(vis[n]+1,vis[n]+1+m,false));cnt){
		cout<<"0\n"<<cnt;
	}else{
		int p1=1,p2;
		for(;p1<=m;p1=p2+1){
			cnt++;p2=0;
			for(int i=1;i<=m;i++)if(l[1][i]<=p1)cmax(p2,r[1][i]);
		}
		cout<<"1\n"<<cnt;
	}
	return 0;
}