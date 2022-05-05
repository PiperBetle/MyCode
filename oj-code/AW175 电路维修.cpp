#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
using std::cin;using std::cout;
struct line{int x,y;};
std::deque<line>q;
int dis[1007][1007],dx1[]={1,-1,-1,1},dy1[]={1,1,-1,-1},dx2[]={0,-1,-1,0},dy2[]={0,0,-1,-1};
char mod[5]={'\\','/','\\','/'},map[1007][1007];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,n,m,T;
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(i=1;i<=n;i++)for(j=1;j<=m;j++)cin>>map[i][j];
		if((n+m)&1){cout<<"NO SOLUTION\n";continue;}
		memset(dis,0x3f,sizeof dis);
		dis[1][1]=0;
		for(q.emplace_front(line{1,1});!q.empty();){
			line now=q.front();q.pop_front();
			for(i=0;i<4;i++){
				line nt1,nt2;
				nt1.x=now.x+dx1[i];nt1.y=now.y+dy1[i];
				nt2.x=now.x+dx2[i];nt2.y=now.y+dy2[i];
				if(nt1.x<1||nt1.y<1||nt1.x>n+1||nt1.y>m+1)continue;
				if(mod[i]!=map[nt2.x][nt2.y]){
					if(dis[now.x][now.y]+1<dis[nt1.x][nt1.y])
						q.push_back(nt1),
						dis[nt1.x][nt1.y]=dis[now.x][now.y]+1;
				}
				else{
					if(dis[now.x][now.y]<dis[nt1.x][nt1.y])
						q.push_front(nt1),
						dis[nt1.x][nt1.y]=dis[now.x][now.y];
				}
			}
		}
		cout<<dis[n+1][m+1]<<'\n';
	}
	return 0;
}