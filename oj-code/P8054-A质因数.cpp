#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
#include<algorithm>
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
char c[5007][5007];
int visit[5007][5007];
int dx[]={0,0,1,-1,1,1,-1,-1},
	dy[]={1,-1,0,0,-1,1,-1,1};
struct point{int x,y,step;};
queue<point> q;
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T;
	int x1,y1;
	point t;
	
	cin>>n>>m;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			cin>>c[i][j];
	while(cin>>x1>>y1>>t.x>>t.y)
	{
		t.step=0;
		memset(visit,0,sizeof visit);
		for(i=0;i<=5000;i++)
			for(j=0;j<8;j++)
			{
				int nx=x1+i*dx[j],ny=y1+i*dy[j];
				if(nx>=1&&nx<=n&&ny>=1&&ny<=m)
					visit[x1+i*dx[j]][y1+i*dy[j]]=i+1;
			}
		if(x1==t.x&&y1==t.y)
		{
			puts("0");
			continue;
		}
		q.push(t);
		while(!q.empty())
			q.pop();
		while(!q.empty())
		{
			point now=q.front();
			q.pop();
			if(visit[now.x][now.y]>=1)
			{
				cout<<visit[now.x][now.y]-1+now.step<<'\n';
				goto end;
			}
			for(i=0;i<4;i++)
			{
				int nx=now.x+dx[i],ny=now.y+dy[i];
				if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&visit[nx][ny]!=-1&&c[nx][ny]!='X')
				{
					point nn;
					nn.x=nx;nn.y=ny;nn.step=now.step+1;
					q.push(nn);
					visit[nx][ny]=-1;
				}
			}
		}
		puts("Poor Harry");
		end:
		"I AK IOI";
	}
	
	return 0;
}