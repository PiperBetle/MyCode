#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
using std::cin;using std::cout;
char c[157][157];
int dis[157][157],dx[]={-2,-2,-1,-1,1,1,2,2},dy[]={-1,1,-2,2,-2,2,-1,1};
struct point{int x,y;};
std::queue<point>q;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,n,m;
	cin>>m>>n;
	for(i=1;i<=n;i++)for(j=1;j<=m;j++){
		cin>>c[i][j];
		if(c[i][j]=='K')dis[i][j]=0,q.emplace(point{i,j});
		else dis[i][j]=0x3f3f3f3f;
	}
	while(!q.empty()){
		auto now=q.front();q.pop();
		for(i=0;i<8;i++){
			int nx=now.x+dx[i],ny=now.y+dy[i];
			if(nx<1||ny<1||nx>n||ny>m||c[nx][ny]=='*'||dis[nx][ny]!=0x3f3f3f3f)continue;
			dis[nx][ny]=dis[now.x][now.y]+1;
			if(c[nx][ny]=='H')return cout<<dis[nx][ny],0;
			q.push(point{nx,ny});
		}
	}
}