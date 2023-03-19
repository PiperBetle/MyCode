#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
#define int long long
using std::cin;using std::cout;
struct point{int x,y,step,d;}begin,end,go;
int a[107][107],dis[107][107][4];
int dx[]={0,1,0,-1},
	dy[]={1,0,-1,0};
std::queue<point>q;
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	// std::ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,T;
	char c;
	
	cin>>n>>m;
	for(i=1;i<=n;i++)for(j=1;j<=m;j++)cin>>a[i][j];
	cin>>begin.x>>begin.y>>end.x>>end.y>>c;
	if(c=='E')begin.d=0;else if(c=='S')begin.d=1;else if(c=='W')begin.d=2;else begin.d=3;
	memset(dis,0,sizeof dis);
	dis[begin.x][begin.y][begin.d]=1;begin.step=1;
	while(!q.empty())q.pop();q.push(begin);
	do
	{
		point now=q.front();q.pop();
		cout<<now.x<<' '<<now.y<<' '<<now.step<<' '<<now.d<<'\n';
		dis[now.x][now.y][now.d]=now.step;now.step++;

		go=now;go.d--;if(go.d==-1)go.d=3;
		if(dis[go.x][go.y][go.d]==0)q.push(go);
		
		go=now;go.d++;if(go.d==4)go.d=0;
		if(dis[go.x][go.y][go.d]==0)q.push(go);
		for(go=now,i=1;i<=3;i++)
		{
			go.x+=dx[go.d];go.y+=dy[go.d];
			if(go.x<1||go.y<1||go.x>n||go.y>m||a[go.x][go.y]==0)break;
			if(go.x==end.x&&go.y==end.y)return cout<<go.step-1,0;
			if(dis[now.x][now.y][now.d]==0)q.push(go);
			q.push(go);
		}
	}while(!q.empty());
	cout<<"-1";
	
	return 0;
}