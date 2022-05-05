#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<ext/pb_ds/priority_queue.hpp>
using std::cin;using std::cout;
struct edge{int go,data;};
std::vector<edge>s[100007];
int dis[100007],visit[100007];
struct point{int id,dis;bool operator<(const point&n)const{return dis>n.dis;}};
__gnu_pbds::priority_queue<point>q;
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k,n,m,ans=0x3f3f3f3f,u,v,t;
	memset(dis,0x3f,sizeof dis);
	cin>>n>>m>>k;
	for(i=1;i<=m;i++){
		cin>>u>>v>>t;
		s[u].emplace_back(edge{v,t});
		s[v].emplace_back(edge{u,t});
		for(j=1;j<=k;j++)
			s[u+(j-1)*n].emplace_back(edge{v+j*n,0}),
			s[v+(j-1)*n].emplace_back(edge{u+j*n,0}),
			s[u+j*n].emplace_back(edge{v+j*n,t}),
			s[v+j*n].emplace_back(edge{u+j*n,t});
	}
	for(q.push(point{1,dis[1]=0});!q.empty();){
		u=q.top().id;q.pop();
		if(visit[u])continue;else visit[u]=true;
		for(auto it:s[u])if(dis[it.go]>std::max(dis[u],it.data)){
			dis[it.go]=std::max(dis[u],it.data);
			if(!visit[it.go])q.push(point{it.go,dis[it.go]});
		}
	}
	for(i=0;i<=k;i++)ans=std::min(ans,dis[n+i*n]);
	if(ans==0x3f3f3f3f)cout<<"-1";else cout<<ans;
	return 0;
}