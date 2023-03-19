#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<ext/pb_ds/priority_queue.hpp>
inline auto sqr(auto x){return x*x;}
struct point{int id;double dis;bool operator<(const point&t)const{return dis>t.dis;}};
__gnu_pbds::priority_queue<point>q;
struct edge{int go;double data;};
std::vector<edge>s[207];
using std::cin;using std::cout;
struct coordinate{int x,y;}a[207];
int pre[207];
bool vis[207];
double dis[207];
void dijkstra(int x,int y){
	memset(vis,0,sizeof vis);
	memset(dis,0x42,sizeof dis);
	for(q.push(point{1,dis[1]=0.0});!q.empty();){
		int u=q.top().id;q.pop();
		if(vis[u])continue;else vis[u]=true;
		for(auto[v,t]:s[u])if(!((x==u&&y==v)||(x==v&&y==u))&&dis[v]>dis[u]+t)
			q.push(point{v,dis[v]=dis[u]+t});
	}
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n,m;double ans=1e100;cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%d%d",&a[i].x,&a[i].y);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);double t=sqrt(sqr(a[u].x-a[v].x)+sqr(a[u].y-a[v].y));
		s[u].emplace_back(v,t),s[v].emplace_back(u,t);
	}
	memset(dis,0x42,sizeof dis);
	for(q.push(point{1,dis[1]=.0});!q.empty();){
		int u=q.top().id;q.pop();
		if(vis[u])continue;else vis[u]=true;
		for(auto[v,t]:s[u])if(dis[v]>dis[u]+t)
			pre[v]=u,q.push(point{v,dis[v]=dis[u]+t});
	}
	for(int v=n;v!=1;v=pre[v])dijkstra(pre[v],v),ans=std::min(ans,dis[n]);
	if(ans>dis[n])printf("-1");else printf("%.2lf",ans);
	return 0;
}