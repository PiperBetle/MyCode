#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<ctime>
using std::cin;using std::cout;
constexpr int MOD=9901;
constexpr int dx[]={0,-2,-2,-1,-1,+1,+1,+2,+2};
constexpr int dy[]={0,+1,-1,+2,-2,+2,-2,+1,-1};
int a[11][11],b[11][11];
int n,m,k,ans,cnt;
struct point{
	int x,y;
	int fixt()const{
		int sum=0;
		for(int i=1;i<9;i++){
			int nx=x+dx[i],ny=y+dy[i];
			if(nx<1||nx>n||ny<1||ny>n)continue;
			sum+=b[nx][ny];
		}
		return sum;
	}
	bool operator<(const point &t)const{
		return fixt()>t.fixt();
	}
}p[41];
void dfs(int u,int sum){
	if(sum==k){
		if(++ans>=MOD)ans-=MOD;
		return;
	}
	if(m+1-u<k-sum)return;
	dfs(u+1,sum);
	if(a[p[u].x][p[u].y])return;
	for(int i=0;i<9;i++){
		int nx=p[u].x+dx[i],ny=p[u].y+dy[i];
		if(nx<1||nx>n||ny<1||ny>n)continue;
		a[nx][ny]++;
	}
	dfs(u+1,sum+1);
	for(int i=0;i<9;i++){
		int nx=p[u].x+dx[i],ny=p[u].y+dy[i];
		if(nx<1||nx>n||ny<1||ny>n)continue;
		a[nx][ny]--;
	}
}
signed main(){
//	freopen("knight.in","r",stdin);
//	freopen("knight.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>p[i].x>>p[i].y,b[p[i].x][p[i].y]=1;
	std::sort(p+1,p+1+m);
	dfs(1,0);
//	std::cerr<<clock();
	cout<<ans;
	return 0;
}
// 我要用这种方式，表达对[数据删除]无声的抗议
