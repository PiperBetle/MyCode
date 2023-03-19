#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
bool f[366][5][5][7][7][7][7],vis[366][5][5][7][7][7][7],a[366][5][5];
short n,dx[]={-2,-1,0,0,0,0,0,1,2},dy[]={0,0,-2,-1,0,1,2,0,0};
bool dfs(short now,short x,short y,short s1,short s2,short s3,short s4){
	if(x==1&&y==1)s1=0;
	else if(x==1&&y==3)s2=0;
	else if(x==3&&y==1)s3=0;
	else if(x==3&&y==3)s4=0;
	if(s1>=7||s2>=7||s3>=7||s4>=7)return false;
	bool &cur=f[now][x][y][s1][s2][s3][s4];
	if(vis[now][x][y][s1][s2][s3][s4])return cur;
	vis[now][x][y][s1][s2][s3][s4]=true;
	if(a[now][x][y]|a[now][x+1][y]|a[now][x][y+1]|a[now][x+1][y+1])return (cur=false);
	if(now==n)return true;
	for(short i=0;i<9;i++){
		short nx=x+dx[i],ny=y+dy[i];
		if(nx<1||ny<1||nx>4||ny>4)continue;
		if(dfs(now+1,nx,ny,s1+1,s2+1,s3+1,s4+1))return (cur=true);
	}
	return (cur=false);
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	while(cin>>n,n){
		for(short i=1;i<=n;i++)for(short j=1;j<=4;j++)for(short k=1;k<=4;k++)cin>>a[i][j][k];
		memset(f,0,sizeof f);
		memset(vis,0,sizeof vis);
		if(dfs(1,2,2,1,1,1,1))cout<<"1\n";else cout<<"0\n";
	}
	return 0;
}