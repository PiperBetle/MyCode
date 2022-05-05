#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#include<queue>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define int long long
using namespace std;
struct point
{
	int x,y,step;
};
int dx[12]={1,1,2,2,2,2,-1,-1,-2,-2,-2,-2},
	dy[12]={-2,2,-2,-1,1,2,-2,2,-1,1,-2,2};
int b[107][107];
queue<point> q;
int bfs(int x,int y)
{
	point t;
	q.push({x,y,0});
	do
	{
		t=q.front();
		q.pop();
		for(int i=0;i<12;i++)
		{
			point n;
			n.x=t.x+dx[i];
			n.y=t.y+dy[i];
			if(n.x>=1&&n.y>=1&&b[n.x][n.y]==0)
			{
				if(n.x==1&&n.y==1)
					return n.step;
				b[n.x][n.y]=1;
				n.step=t.step+1;
				q.push(n);
			}
		}
	}
	while(!q.empty());
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int x1,y1,x2,y2;
	
	cin>>x1>>y1>>x2>>y2;
	cout<<bfs(x1,y1)<<'\n';
	memset(b,0,sizeof b);
	while(!q.empty())
		q.pop();
	cout<<bfs(x2,y2);
	
	return 0;
}
