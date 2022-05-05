#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<ext/pb_ds/priority_queue.hpp>
#define int long long
using std::cin;using std::cout;
struct edge{int v,data;};
std::vector<edge>s[100007];
int dis[1000007];
bool vis[1000007];
struct point{int id,data;bool operator<(const point &t)const{return data>t.data;}};
__gnu_pbds::priority_queue<point,std::less<point>,__gnu_pbds::binary_heap_tag>q;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int n,m,stt;
	cin>>n>>m>>stt;
	for(int i=1,u,v,t;i<=m;i++)cin>>u>>v>>t,s[u].emplace_back(v,t);
	memset(dis,0x3f,sizeof dis);
	dis[stt]=0;q.push(point{stt,0});
	while(!q.empty()){
		int id=q.top().id;q.pop();
		if(vis[id])continue;else vis[id]=1;
		for(auto[v,data]:s[id])if(dis[v]>dis[id]+data){
			dis[v]=dis[id]+data;
			if(!vis[v])q.push(point{v,dis[v]});
		}
	}
	for(int i=1;i<=n;i++)cout<<dis[i]<<' ';
	return 0;
}