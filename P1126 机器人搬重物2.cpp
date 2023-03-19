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
constexpr int N=52,inf=0x3f3f3f3f;
constexpr int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
int n,m,a[N][N],d[N][N][4],x1,y1,x2,y2,k0;
struct node{int x,y,k;};
std::queue<node>q;
char c;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	memset(d,0x3f,sizeof d);
	cin>>n>>m;
	for(int i=1,x;i<=n;i++)for(int j=1;j<=m;j++)
		if(cin>>x,x)a[i][j]=a[i-1][j]=a[i][j-1]=a[i-1][j-1]=1;
	cin>>x1>>y1>>x2>>y2>>c;
	if(c=='E')k0=0;if(c=='S')k0=1;if(c=='W')k0=2;if(c=='N')k0=3;
	q.emplace(x1,y1,k0);d[x1][y1][k0]=0;
	while(!q.empty()){
		auto[x,y,k]=q.front();q.pop();
		for(int i=1,nx=x,ny=y;i<=3;i++){
			nx+=dx[k],ny+=dy[k];
			if(nx<1||nx>=n||ny<1||ny>=m||a[nx][ny])break;
			if(d[nx][ny][k]>d[x][y][k]+1)
				d[nx][ny][k]=d[x][y][k]+1,q.emplace(nx,ny,k);
		}
		if(int k1=k==3?0:k+1;d[x][y][k1]>d[x][y][k]+1)
			d[x][y][k1]=d[x][y][k]+1,q.emplace(x,y,k1);
		if(int k1=k==0?3:k-1;d[x][y][k1]>d[x][y][k]+1)
			d[x][y][k1]=d[x][y][k]+1,q.emplace(x,y,k1);
	}
	int res=*std::min_element(d[x2][y2],d[x2][y2]+4);
	cout<<(res==inf?-1:res);
	return 0;
}