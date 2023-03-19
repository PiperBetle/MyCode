#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
int n,m,q,d[1007];
char a[57][57];
bool b[1007][57][57];
int dx[4]={-1,1,0,0},
	dy[4]={0,0,-1,1};
std::string s;
inline void dfs(int now,int x,int y)
{
	if(b[now][x][y])return;
	b[now][x][y]=1;
	if(now==q+1)return;
	for(int i=1;;i++)
	{
		int nx=x+i*dx[d[now]],ny=y+i*dy[d[now]];
		if(nx>n||ny>m||nx<1||ny<1||a[nx][ny]=='X')return;
		dfs(now+1,nx,ny);
	}
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int x1,y1;

	cin>>n>>m;
	for(i=1;i<=n;i++)for(j=1;j<=m;j++){cin>>a[i][j];if(a[i][j]=='*')x1=i,y1=j;}
	a[x1][y1]='.';
	cin>>q;
	for(i=1;i<=q;i++)
	{
		cin>>s;
		if(s=="NORTH")d[i]=0;
		if(s=="SOUTH")d[i]=1;
		if(s=="WEST")d[i]=2;
		if(s=="EAST")d[i]=3;
	}
	dfs(1,x1,y1);
	for(i=1;i<=n;i++,cout<<'\n')for(j=1;j<=m;j++)
		if(a[i][j]=='X')cout<<'X';
		else cout<<(b[q+1][i][j]?'*':'.');

	return 0;
}