#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
#define int long long
using std::cin;using std::cout;
struct point{int x,y,step,d;}begin,end,go;
char c[1007][1007];
std::queue<point>q;
inline point fall(point&now)
{
	for(;c[now.x][now.y]!='#';now.x+=now.d)
		if(c[now.x][now.y]=='D'){cout<<now.step;exit(0);}
}
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
		if(c[i][j]=='C')begin.x=i,begin.y=j;
	}
	begin.step=0;begin.d=1;
	while(!q.empty())q.pop();
	q.emplace(begin);
	do
	{
		point now=q.top();q.pop();
		go.x=now.x+dx[d];go.y=now.y;
		go.step=now.step+1;go.d=now.d;
		
	}while(!q.empty());
	
	return 0;
}