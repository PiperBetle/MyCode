#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
using std::cin;using std::cout;
template<typename any>inline any max(any x,any y){return x>y?x:y;}
template<typename any>inline any min(any x,any y){return x<y?x:y;}
template<typename any>inline any abs(any x){return x>0?x:-x;}
char c[1007][1007];
int dis[1007][1007];
bool b[1007][1007];
struct point{int x,y;}begin,last,go;
std::queue<point>q;
int dx[]={-1,-1,-1,0,0,1,1,1},	
	dy[]={-1,0,1,-1,1,-1,0,1};
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,T;
	
	cin>>n>>m;
	for(i=1;i<=n;i++)for(j=1;j<=m;j++)
	{
		cin>>c[i][j];
		if(c[i][j]=='*')begin.x=i,begin.y=j;
		else if(c[i][j]=='X')last.x=i+1,last.y=j;
	}
	for(i=last.x;i<=n;i++)c[i][last.y]='|';
	memset(dis,0x3f,sizeof dis);
	memset(b,0,sizeof b);
	while(!q.empty())q.pop();
	b[begin.x][begin.y]=1;
	dis[begin.x][begin.y]=0;
	q.push(begin);
	do
	{
		point now=q.front();q.pop();
//		cout<<now.x<<' '<<now.y<<' '<<c[now.x][now.y]<<' '<<dis[now.x][now.y]<<'\n';
		for(i=0;i<8;i++)
		{
			go.x=now.x+dx[i];
			go.y=now.y+dy[i];
			if(go.x>=1&&go.x<=n&&go.y>=1&&go.y<=m&&c[go.x][go.y]=='.'&&!b[go.x][go.y])
			{
				b[go.x][go.y]=1;
				dis[go.x][go.y]=dis[now.x][now.y]+1;
				q.push(go);
			}
		}
	}while(!q.empty());
	int ans1=min(min(dis[last.x-1][last.y-1],dis[last.x][last.y-1]),dis[last.x+1][last.y-1]);
	int ans2=min(min(dis[last.x-1][last.y+1],dis[last.x][last.y+1]),dis[last.x+1][last.y+1]);
	cout<<ans1+ans2+2;
	
	return 0;
}
