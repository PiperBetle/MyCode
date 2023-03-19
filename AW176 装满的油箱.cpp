#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<ext/pb_ds/priority_queue.hpp>
struct point{int id,dis,oil;bool operator<(const point &n)const{return dis>n.dis;}};
__gnu_pbds::priority_queue<point>q;
using std::cin;using std::cout;
int p[1007],dis[1007][107];
bool vis[1007][107];
struct edge{int go,data;};
std::vector<edge>s[1007];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,n,m,Q,u,v,t,c,start,end,ans;
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>p[i];
	for(i=1;i<=m;i++)cin>>u>>v>>t,u++,v++,s[u].emplace_back(edge{v,t}),s[v].emplace_back(edge{u,t});
	cin>>Q;
	while(Q--){
		cin>>c>>start>>end;
		start++;end++;
		memset(dis,0x3f,sizeof dis);
		memset(vis,0,sizeof vis);
		while(!q.empty())q.pop();
		ans=-1;
		for(q.push(point{start,dis[start][0]=0,0});!q.empty();){
			point u=q.top();q.pop();
			if(u.id==end){ans=u.dis;break;}
			if(vis[u.id][u.oil])continue;else vis[u.id][u.oil]=true;
			if(u.oil<c&&dis[u.id][u.oil+1]>u.dis+p[u.id])
				dis[u.id][u.oil+1]=u.dis+p[u.id],
				q.push(point{u.id,dis[u.id][u.oil+1],u.oil+1});
			for(auto v:s[u.id])if(u.oil>=v.data&&dis[v.go][u.oil-v.data]>dis[u.id][u.oil])
				dis[v.go][u.oil-v.data]=dis[u.id][u.oil],
				q.push(point{v.go,dis[v.go][u.oil-v.data],u.oil-v.data});
		}
		if(ans==-1)cout<<"impossible\n";else cout<<ans<<'\n';
	}
	return 0;
}