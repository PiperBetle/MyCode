#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=52,dx[]={-1,0,0,1},dy[]={0,-1,1,0};
int n,m,lim,k1,k2,ans=0x3f3f3f3f;
pii num[kN];
bool vis[kN][kN];
void dfs(int x,int y,int cnt,int max){
	if(vis[x-1][y]&&vis[x+1][y]&&!vis[x][y+1]&&!vis[x][y-1])return;
	if(vis[x][y-1]&&vis[x][y+1]&&!vis[x+1][y]&&!vis[x-1][y])return;
	if(cnt<=lim)num[cnt]={x,y};
	else max=std::max(max,k1*abs(num[cnt-lim].first-x)+k2*abs(num[cnt-lim].second-y));
	if(cnt>=n*m){ans=std::min(ans,max);return;}
	if(max>=ans)return;
	for(int i=0;i<4;i++){
		int nx=x+dx[i],ny=y+dy[i];
		if(vis[nx][ny])continue;
		vis[nx][ny]=true;
		dfs(nx,ny,cnt+1,max);
		vis[nx][ny]=false;
	}
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m>>k1>>k2;lim=n*m/2;
	for(int i=0;i<=n+1;i++)vis[i][0]=vis[i][m+1]=true;
	for(int i=0;i<=m+1;i++)vis[0][i]=vis[n+1][i]=true;
	vis[1][1]=true;
	dfs(1,1,1,0);cout<<ans;
	return 0;
}