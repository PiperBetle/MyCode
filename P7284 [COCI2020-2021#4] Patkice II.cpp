#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<deque>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=2001,dx[]={-1,1,0,0},dy[]={0,0,-1,1};
const std::string dc="^v<>";
char c[kN][kN];
int n,m,dis[kN][kN];
pii pre[kN][kN];
std::deque<pii>q;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
		cin>>c[i][j];
		if(c[i][j]=='o'){
			dis[i][j]=0;
			q.emplace_back(i,j);
		}
	}
	while(!q.empty()){
		auto[x,y]=q.front();q.pop_front();
		if(c[x][y]=='x')break;
		for(int i=0;i<4;i++){
			int nx=x+dx[i],ny=y+dy[i];
			if(nx<1||ny<1||nx>n||ny>m)continue;
			int w=(c[x][y]!=dc[i]&&c[x][y]!='o');
			if(dis[nx][ny]>dis[x][y]+w){
				dis[nx][ny]=dis[x][y]+w;
				pre[nx][ny]={x,y};
				if(w)q.emplace_back(nx,ny);
				else q.emplace_front(nx,ny);
			}
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(c[i][j]=='x'){
		cout<<dis[i][j]<<'\n';
		for(;pre[i][j]!=pii(0,0);){
			auto[px,py]=pre[i][j];
			if(px-1==i&&c[px][py]!='o')c[px][py]='^';
			if(px+1==i&&c[px][py]!='o')c[px][py]='v';
			if(py-1==j&&c[px][py]!='o')c[px][py]='<';
			if(py+1==j&&c[px][py]!='o')c[px][py]='>';
			i=px,j=py;
		}
		goto print;
	}
	print:
	for(int i=1;i<=n;i++,cout<<'\n')for(int j=1;j<=m;j++)cout<<c[i][j];
	// for(int i=1;i<=n;i++,cout<<'\n')for(int j=1;j<=m;j++)cout<<dis[i][j]<<' ';
	// for(int i=1;i<=n;i++,cout<<'\n')for(int j=1;j<=m;j++)cout<<'('<<pre[i][j].first<<','<<pre[i][j].second<<')'<<' ';
	return 0;
}