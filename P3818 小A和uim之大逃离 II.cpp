#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
#define int long long
using std::cin;using std::cout;
template<typename any>inline any max(any x,any y){return x>y?x:y;}
template<typename any>inline any min(any x,any y){return x<y?x:y;}
template<typename any>inline any abs(any x){return x>0?x:-x;}
char c[1007][1007];
bool b[1007][1007][2];
struct point{int x,y,step;bool flag;}go;
std::queue<point>q;
int dx[]={-1,1,0,0},
	dy[]={0,0,-1,1};
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,d,r;
	
	cin>>n>>m>>d>>r;
	for(i=1;i<=n;i++)for(j=1;j<=m;j++)cin>>c[i][j];
	memset(b,0,sizeof b);while(!q.empty())q.pop();
	q.emplace((point){1,1,0,1});
	do
	{
		point now=q.front();q.pop();
		for(i=0;i<4;i++)
		{
			go.x=now.x+dx[i];go.y=now.y+dy[i];go.step=now.step+1;go.flag=now.flag;
			if(go.x<1||go.x>n||go.y<1||go.y>m||c[go.x][go.y]=='#'||b[go.x][go.y][go.flag])continue;
			if(go.x==n&&go.y==m)return cout<<go.step,0;
			b[go.x][go.y][go.flag]=1;
			q.emplace(go);
		}
		if(!now.flag)continue;
		go.x=now.x+d;go.y=now.y+r;go.step=now.step+1;go.flag=0;
		if(go.x<1||go.x>n||go.y<1||go.y>m||c[go.x][go.y]=='#'||b[go.x][go.y][go.flag])continue;
		if(go.x==n&&go.y==m)return cout<<go.step,0;
		b[go.x][go.y][go.flag]=1;
		q.emplace(go);
	}while(!q.empty());
	cout<<"-1";
	
	return 0;
}