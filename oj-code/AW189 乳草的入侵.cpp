#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
using std::cin;using std::cout;
struct point{int x,y;};
std::queue<point>q;
char c[107][107];
int dis[107][107];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,n,m,x1,y1,ans=0;
	cin>>m>>n>>y1>>x1;x1=n-x1+1;
	for(i=1;i<=n;i++)for(j=1;j<=m;j++)cin>>c[i][j];
	memset(dis,0x3f,sizeof dis);
	dis[x1][y1]=0;
	for(q.emplace(point{x1,y1});!q.empty();){
		auto now=q.front();q.pop();
		for(int nx=now.x-1;nx<=now.x+1;nx++)for(int ny=now.y-1;ny<=now.y+1;ny++){
			if(nx<1||ny<1||nx>n||ny>m||c[nx][ny]=='*'||dis[nx][ny]!=0x3f3f3f3f)continue;
			ans=dis[nx][ny]=dis[now.x][now.y]+1;
			q.emplace(point{nx,ny});
		}
	}
	cout<<ans;
	return 0;
}