#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<vector>
#include<deque>
#define siz(x) int((x).size())
#define cauto const auto
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=12,kM=102;
constexpr int dx[]={-1,0,0,0,1},dy[]={0,-1,0,1,0};
int n,m,T,Xfr,Yfr,c1,c2,tot;
int mp[kN][kN][kM],dis[kN][kN][kM][1100];
struct suika{int x,y,t,w;};
std::deque<suika>q;
signed main(){
//	freopen("Yukari.in","r",stdin);
//	freopen("Yukari.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m>>T>>Xfr>>Yfr>>c1>>c2;
	if(!c1)return cout<<0,0;
	while(c1--){
		int p1,p2,t;
		cin>>p1>>p2>>t;
		int tag=(t?1<<tot++:-1);
		for(int i=p1,x,y;i<p2;i++)cin>>x>>y,mp[x][y][i]|=tag;
	}
	if(!~mp[Xfr][Yfr][1])return cout<<"-1",0;
	memset(dis,-1,sizeof dis);
	dis[Xfr][Yfr][1][mp[Xfr][Yfr][1]]=0;
	q.emplace_back(Xfr,Yfr,1,mp[Xfr][Yfr][1]);
	while(!q.empty()){
		auto[x,y,t,w]=q.front();q.pop_front();
		if(t==T){if(w==(1<<c2)-1)return cout<<dis[x][y][t][w],0;continue;}
		for(int i=0;i<5;i++){
			int nx=x+dx[i],ny=y+dy[i],nt=t+1,nw=w|mp[nx][ny][nt],cost=(i!=2);
			if(nx<1||ny<1||nx>n||ny>m||!~mp[nx][ny][nt]||~dis[nx][ny][nt][nw])continue;
			dis[nx][ny][nt][nw]=dis[x][y][t][w]+cost;
			cost?q.emplace_back(nx,ny,nt,nw):q.emplace_front(nx,ny,nt,nw);
		}
	}
	cout<<"-1";
	return 0;
}