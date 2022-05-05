#include<iostream>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
char a[2007][2007];
int n,m;
void dfs(int x,int y){
	if(x<1||y<1||x>n||y>m||a[x][y]=='.')return;
	if((a[x+1][y]=='.'&&a[x+1][y+1]=='.'&&a[x][y+1]=='.')||(a[x-1][y]=='.'&&a[x-1][y-1]=='.'&&a[x][y-1]=='.')||(a[x+1][y]=='.'&&a[x+1][y-1]=='.'&&a[x][y-1]=='.')||(a[x-1][y]=='.'&&a[x-1][y+1]=='.'&&a[x][y+1]=='.'))a[x][y]='.';else return;
	dfs(x-1,y-1);dfs(x-1,y);dfs(x-1,y+1);dfs(x,y-1);dfs(x,y+1);dfs(x+1,y-1);dfs(x+1,y);dfs(x+1,y+1);
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
//	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>a[i][j];
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(a[i][j]=='*')dfs(i,j);
	for(int i=1;i<=n;i++,cout<<'\n')for(int j=1;j<=m;j++)cout<<a[i][j];
	return 0;
}