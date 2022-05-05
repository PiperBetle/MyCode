#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<map>
#define int long long
std::map<int,int>mp[21][21];
using std::cin;using std::cout;
int a[21][21],n,m,k,ans=0;
void dfs1(int x,int y,int data){
	if(x+y==(n+m)/2+1){mp[x][y][data]++;return;}
	if(x<n)dfs1(x+1,y,data^a[x+1][y]);
	if(y<m)dfs1(x,y+1,data^a[x][y+1]);
}
void dfs2(int x,int y,int data){
	if(x+y==(n+m)/2+1){ans+=mp[x][y][data^k^a[x][y]];return;}
	if(x>1)dfs2(x-1,y,data^a[x-1][y]);
	if(y>1)dfs2(x,y-1,data^a[x][y-1]);
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j;
	cin>>n>>m>>k;
	for(i=1;i<=n;i++)for(j=1;j<=m;j++)cin>>a[i][j];
	dfs1(1,1,a[1][1]);
	dfs2(n,m,a[n][m]);
	cout<<ans;
	return 0;
}