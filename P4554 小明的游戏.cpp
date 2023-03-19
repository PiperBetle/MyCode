#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
using std::cin;using std::cout;
char c[507][507];
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
bool vis[507][507];
struct point{int x,y,dis;};
std::deque<point>q;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,n,m,x1,y1,x2,y2;
	while(cin>>n>>m){
		if(!n&&!m)return 0;
		for(i=1;i<=n;i++)for(j=1;j<=m;j++)cin>>c[i][j];
		cin>>x1>>y1>>x2>>y2;
		x1++,x2++,y1++,y2++;
		memset(vis,0,sizeof vis);
		while(!q.empty())q.pop_front();
		q.push_back(point{x1,y1,0});
		vis[x1][y1]=true;
		while(!q.empty()){
			point now=q.front();q.pop_front();
			if(now.x==x2&&now.y==y2){cout<<now.dis<<'\n';break;}
			for(i=0;i<4;i++){
				int nx=now.x+dx[i],ny=now.y+dy[i];
				if(nx<1||ny<1||nx>n||ny>m||vis[nx][ny])continue;
				vis[nx][ny]=true;
				if(c[nx][ny]==c[now.x][now.y])q.push_front(point{nx,ny,now.dis});
				else q.push_back(point{nx,ny,now.dis+1});
			}
		}
	}
	return 0;
}