#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<ext/pb_ds/priority_queue.hpp>
using namespace __gnu_pbds;
#define int long long
using std::cin;using std::cout;
int dis[3][1007][1007],n,m,ans,A,B,C;bool visit[1007][1007];
struct point{int x,y,dis;bool operator<(const point&n)const{return dis>n.dis;}}now,go;
priority_queue<point>q;
int a[1007][1007],dx[]={0,0,1,-1},dy[]={1,-1,0,0};
inline void dijkstra(int x,int y,int k)
{
	for(int i=0;i<1007;i++)for(int j=0;j<1007;j++)dis[k][i][j]=0x3f3f3f3f3f3f3f3f,visit[i][j]=0;
	while(!q.empty())q.pop();
	dis[k][x][y]=a[x][y];q.push((point){x,y,a[x][y]});
	while(!q.empty())
	{
		now=q.top();q.pop();
		if(visit[now.x][now.y])continue;
		visit[now.x][now.y]=1;
		for(int i=0;i<4;i++)
		{
			go.x=now.x+dx[i];go.y=now.y+dy[i];
			if(go.x>=1&&go.y>=1&&go.x<=n&&go.y<=m&&dis[k][go.x][go.y]>dis[k][now.x][now.y]+a[go.x][go.y])
			{
				go.dis=dis[k][go.x][go.y]=dis[k][now.x][now.y]+a[go.x][go.y];
				if(!visit[go.x][go.y])q.push(go);
			}
		}
	}
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int u,v,ans=0x3f3f3f3f3f3f3f3f;
	
	cin>>n>>m>>A>>B>>C;
	for(i=1;i<=n;i++)for(j=1;j<=m;j++)cin>>a[i][j];
	dijkstra(1,A,0);
	dijkstra(n,B,1);
	dijkstra(n,C,2);
	for(i=1;i<=n;i++)for(j=1;j<=m;j++)ans=std::min(ans,dis[0][i][j]+dis[1][i][j]+dis[2][i][j]-(a[i][j]<<1));
	cout<<ans;

	return 0;
}