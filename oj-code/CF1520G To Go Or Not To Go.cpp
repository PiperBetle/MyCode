#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
using std::cin;using std::cout;
constexpr auto inf=0x3f3f3f3f3f3f3f3f;
int n,m,w,a[2007][2007],dis[2007][2007],dx[]={-1,1,0,0},dy[]={0,0,-1,1};
long long ans1=inf,ans2=inf,ans0=inf;
struct point{int x,y;};
std::queue<point>q;
void bfs(int x,int y,long long &ans){
	while(!q.empty())q.pop();
	memset(dis,-1,sizeof dis);
	for(q.emplace(x,y),dis[x][y]=0;!q.empty();){
		point u=q.front();q.pop();
		for(int i=0;i<4;i++)if(point v={u.x+dx[i],u.y+dy[i]};v.x>=1&&v.x<=n&&v.y>=1&&v.y<=m&&a[v.x][v.y]!=-1&&dis[v.x][v.y]==-1)
			dis[v.x][v.y]=dis[u.x][u.y]+1,q.emplace(v);
	}
	if(x==1&&y==1&&dis[n][m]!=-1)ans0=std::min(ans0,1ll*dis[n][m]*w);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(a[i][j]>0&&dis[i][j]!=-1)ans=std::min(ans,1ll*dis[i][j]*w+a[i][j]);
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m>>w;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>a[i][j];
	bfs(1,1,ans1);bfs(n,m,ans2);ans0=std::min(ans0,ans1+ans2);
	cout<<(ans0==inf?-1:ans0);
	return 0;
}