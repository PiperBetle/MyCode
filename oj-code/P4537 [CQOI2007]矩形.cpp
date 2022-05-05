#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
int dx[]={-1,1,0,0},dy[]={0,0,-1,1},n,m;
bool vis[10][10];
long long ans=0;
inline void dfs(int x,int y){
	if(x<1||x>=n||y<1||y>=m){ans++;return;}
	vis[x][y]=true;
	for(int i=0;i<4;i++)if(!vis[x+dx[i]][y+dy[i]])dfs(x+dx[i],y+dy[i]);
	vis[x][y]=false;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i;
	cin>>n>>m;
	for(i=1;i<n;i++)memset(vis,0,sizeof vis),vis[i][0]=true,dfs(i,1);
	for(i=1;i<m;i++)memset(vis,0,sizeof vis),vis[0][i]=true,dfs(1,i);
	cout<<ans;
	return 0;
}